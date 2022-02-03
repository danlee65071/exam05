#pragma once

#include <iostream>

class Warlock
{
    private:
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
};