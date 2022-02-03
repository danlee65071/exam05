#pragma once

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string type;
    public:
        ATarget(const std::string& Type): type(Type) {}
        ATarget(const ATarget& other)
        {
            type = other.type;
        }
        ATarget& operator=(const ATarget& other)
        {
            if (this != &other)
                type = other.type;
            return *this;
        }
        virtual ~ATarget() {}

        const std::string& getType() const { return type; }

        virtual ATarget *clone() const = 0;

        void getHitBySpell(const ASpell& spell) const;
};