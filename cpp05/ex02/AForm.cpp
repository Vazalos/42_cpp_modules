#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
    : name("Generic AForm"), gradeToSign(150), gradeToExec(150), isSigned(0){}

AForm::AForm(const std::string newName, const int newSignGrade, const int newExecGrade, const std::string newTarget)
    : name(newName), gradeToSign(checkGrade(newSignGrade)),
        gradeToExec(checkGrade(newExecGrade)), isSigned(0), target(newTarget){}

AForm::AForm(const AForm& origAForm)
    : name(origAForm.name), gradeToSign(origAForm.gradeToSign),
        gradeToExec(origAForm.gradeToExec), isSigned(0){}

AForm& AForm::operator=(const AForm& origAForm)
{
    isSigned = origAForm.isSigned;
    return(*this);
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const throw()
{
    return("Invalid grade: grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return("Invalid grade: grade too low");
}

const char* AForm::AlreadySignedException::what() const throw()
{
    return("Form is already signed, no need!");
}

const char* AForm::NotSignedException::what() const throw()
{
    return("Form is not signed yet!");
}

std::string AForm::getName() const
{
    return(name);
}

int AForm::getExecGrade() const
{
    return(gradeToExec);
}

int AForm::getSignGrade() const
{
    return(gradeToSign);
}

bool AForm::getSignedStatus() const
{
    return(isSigned);
}

void    AForm::beSigned(const Bureaucrat& signer)
{
    if (isSigned)
        throw AlreadySignedException();
    else
    {
        if (signer.getGrade() <= gradeToSign)
            isSigned = true;
        else
            throw GradeTooLowException();
    }
}

int AForm::checkGrade(int newGrade) const
{
    if (newGrade > 150)
        throw(GradeTooLowException());
    if (newGrade < 1)
        throw(GradeTooHighException());
    return newGrade;
}

std::ostream& operator<<(std::ostream& stream, const AForm& other)
{
    stream << other.getName() << "; Signed? " << other.getSignedStatus() \
        << "; Sign Grade: " << other.getSignGrade() << "; Execution Grade: " << other.getExecGrade();
    return(stream);
}