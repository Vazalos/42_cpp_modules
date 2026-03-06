#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : AForm("PresidentialPardonForm", 25, 5, "nothing"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
    : AForm("PresidentialPardonForm", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& origShrub)
    : AForm(origShrub){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& origShrub)
{
    if (this != &origShrub)
        AForm::operator=(origShrub); //same as 'static_cast<AForm&>(*this).operator=(other)' OR 'static_cast<AForm&>(*this) = static_cast<AForm const&>(other)'
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){}

void PresidentialPardonForm::beExecuted(void) const
{
    std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox.\n";
}