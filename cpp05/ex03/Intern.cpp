#include "Intern.hpp"

Intern::Intern(){}

Intern::~Intern(){}

Intern::Intern(Intern& intern)
{
    (void)intern;
}

Intern& Intern::operator=(Intern& intern)
{
    (void)intern;
    return(*this);
}

static AForm* makeShrubForm(const std::string& target)
{
    return(new ShrubberyCreationForm(target));
}

static AForm* makePardonForm(const std::string& target)
{
    return(new PresidentialPardonForm(target));
}

static AForm* makeRoboForm(const std::string& target)
{
    return(new RobotomyRequestForm(target));
}

AForm* Intern::makeForm(const std::string& name, const std::string& target)
{
    std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
    AForm* (*formFuncs[3])(const std::string&) = {&makePardonForm, &makeRoboForm, &makeShrubForm};

    for (int i = 0; i < 3; i++)
        if(name == formNames[i])
        {
            std::cout << "Intern creates " << "form" << '\n';
            return (formFuncs[i](target));
        }
    std::cout << "Form name not found\n";
    return(NULL);
}