#pragma once

#include <iostream>
#include <map>
#include "ASpell.hpp"

class SpellBook
{
    private:
        typedef std::map<std::string, ASpell *>::iterator iterator;
        std::map<std::string, ASpell *> book;
        SpellBook(const SpellBook& other);
        SpellBook& operator=(const SpellBook& other);
    public:
        SpellBook() {}
        ~SpellBook() {}

        void learnSpell(ASpell *spell)
        {
            if (spell)
                book.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
        }

        void forgetSpell(const std::string& spell_name)
        {
            iterator it = book.find(spell_name);
            if (it != book.end())
                delete it->second;
            book.erase(spell_name);
        }

        ASpell* createSpell(const std::string& spell_name)
        {
            ASpell *spell = book[spell_name];
            if (spell)
                return spell;
            return NULL;
        }
};