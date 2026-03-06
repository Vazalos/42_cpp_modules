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

void ShrubberyCreationForm::beExecuted(void) const
{
    std::ofstream f((getTarget() + "_shrubbery").c_str());
	if (!f.is_open())
		return;

    f   << "    -˙-\n"
	    << "   -˙ ˙-\n"
	    << "  -˙   ˙-\n"
	    << " -˙ ___ ˙-\n"
	    << "-˙--| |--˙-\n"
	    << "    |_|\n";
	f.close();
}