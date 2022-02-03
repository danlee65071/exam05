#pragma once

#include "ATarget.hpp"
#include <map>

class TargetGenerator
{
    private:
        typedef std::map<std::string, ATarget *>::iterator iterator;
        std::map<std::string, ATarget *> generator;

        TargetGenerator(const TargetGenerator& other);
        TargetGenerator& operator=(const TargetGenerator& other);
    public:
        TargetGenerator() {}
        ~TargetGenerator() {}

        void  learnTargetType(ATarget *target)
        {
            if (target)
                generator.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
        }

        void forgetTargetType(std::string const &type)
        {
            iterator it = generator.find(type);
            if (it != generator.end())
                delete it->second;
            generator.erase(type);
        }

        ATarget* createTarget(std::string const &type)
        {
            ATarget *t = generator[type];
            if (t)
                return t;
            return NULL;
        }
};