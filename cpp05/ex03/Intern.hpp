#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        ~Intern();
        AForm* makeForm(const std::string& name, const std::string& target);

    private:
        Intern(Intern&);
        Intern& operator=(Intern&);
};

#endif