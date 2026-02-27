#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137, "nothing"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137, target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& origShrub)
    : AForm(origShrub){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& origShrub)
{
    if (this != &origShrub)
        AForm::operator=(origShrub); //same as 'static_cast<AForm&>(*this).operator=(other)' OR 'static_cast<AForm&>(*this) = static_cast<AForm const&>(other)'
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

void ShrubberyCreationForm::formEffect(const Bureaucrat& executor) const
{
    //create shrub ASCII file
}