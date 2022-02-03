#pragma once

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;
    public:
        ASpell(const std::string& Name, const std::string& Effects): name(Name), effects(Effects) {}
        ASpell(const ASpell& other)
        {
            name = other.name;
            effects = other.effects;
        }
        ASpell& operator=(const ASpell& other)
        {
            if (this != &other)
            {
                name = other.name;
                effects = other.effects;
            }
            return *this;
        }

        virtual ~ASpell() {};

        const std::string& getName() const { return name; }
        const std::string& getEffects() const { return effects; }

        virtual ASpell *clone() const = 0;

        void launch(const ATarget& target);
};