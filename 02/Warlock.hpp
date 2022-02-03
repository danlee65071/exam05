#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
        SpellBook book;
        std::string name;
        std::string title;

        Warlock(const Warlock& other);
        Warlock& operator=(const Warlock& other);
    public:
        Warlock(const std::string& Name, const std::string& Title): name(Name), title(Title)
        {
            std::cout << name << ": This looks like another boring day.\n";
        }
        ~Warlock()
        {
            std::cout << name << ": My job here is done!\n";
        }

        const std::string& getName() const { return name; }
        const std::string&getTitle() const { return title; }

        void setTitle(const std::string& Title) { title = Title; }

        void introduce() const
        {
            std::cout << name << ": I am " << name << ", " << title << "!\n";
        }

        void learnSpell(ASpell *Spell)
        {
            book.learnSpell(Spell);
        }

        void forgetSpell(const std::string& spell_name)
        {
            book.forgetSpell(spell_name);
        }

        void launchSpell(const std::string& spell_name, const ATarget& target)
        {
            ASpell *Spell = book.createSpell(spell_name);
            if (Spell)
                Spell->launch(target);
        }
};