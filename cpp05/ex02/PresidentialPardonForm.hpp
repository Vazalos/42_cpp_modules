#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string target);
        PresidentialPardonForm(const PresidentialPardonForm&);
        PresidentialPardonForm& operator=(const PresidentialPardonForm&);
        ~PresidentialPardonForm();
    private:
        void    beExecuted(void) const;
};

#endif