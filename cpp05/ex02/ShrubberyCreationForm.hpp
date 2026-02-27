#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
        ~ShrubberyCreationForm();
    private:
        void formEffect(const Bureaucrat& executor) const;
};

#endif