#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
    : name("Generic Form"), gradeToSign(150), gradeToExec(150), isSigned(0){}

Form::Form(const std::string newName, const int newSignGrade, const int newExecGrade)
    : name(newName), gradeToSign(checkGrade(newSignGrade)),
        gradeToExec(checkGrade(newExecGrade)), isSigned(0){}

Form::Form(const Form& origForm)
    : name(origForm.name), gradeToSign(origForm.gradeToSign),
        gradeToExec(origForm.gradeToExec), isSigned(0){}

Form& Form::operator=(const Form& origForm)
{
    isSigned = origForm.isSigned;
    return(*this);
}

Form::~Form(){}

std::string Form::getName() const
{
    return(name);
}

int Form::getExecGrade() const
{
    return(gradeToExec);
}

int Form::getSignGrade() const
{
    return(gradeToSign);
}

bool Form::getSignedStatus() const
{
    return(isSigned);
}

int Form::checkGrade(int newGrade) const
{
    if (newGrade > 150)
        throw(GradeTooLowException());
    if (newGrade < 1)
        throw(GradeTooHighException());
    return newGrade;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return("Invalid grade: grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return("Invalid grade: grade too low");
}

const char* Form::AlreadySignedException::what() const throw()
{
    return("Form is already signed, no need!");
}

void    Form::beSigned(const Bureaucrat& signer)
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

std::ostream& operator<<(std::ostream& stream, const Form& other)
{
    stream << other.getName() << "; Signed? " << other.getSignedStatus() \
        << "; Sign Grade: " << other.getSignGrade() << "; Execution Grade: " << other.getExecGrade();
    return(stream);
}