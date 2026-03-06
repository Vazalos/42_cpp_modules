#include "RobotomyRequestForm.hpp"
#include <cstdlib> 

RobotomyRequestForm::RobotomyRequestForm()
    : AForm("RobotomyRequestForm", 72, 45, "nothing"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
    : AForm("RobotomyRequestForm", 72, 45, target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& origShrub)
    : AForm(origShrub){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& origShrub)
{
    if (this != &origShrub)
        AForm::operator=(origShrub); //same as 'static_cast<AForm&>(*this).operator=(other)' OR 'static_cast<AForm&>(*this) = static_cast<AForm const&>(other)'
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){}

void RobotomyRequestForm::beExecuted(void) const
{
    std::cout << "~~LOUD DRILLING NOISES~~\n";
    if ((std::rand() % 2) == 0)
        std::cout << getTarget() << " has been sucessfully robotomized\n";
    else
        std::cout << getTarget() << "'s robotomy failed. Cope and seethe, fleshy!\n";
}