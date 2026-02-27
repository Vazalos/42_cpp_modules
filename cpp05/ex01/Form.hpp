#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
    class GradeTooHighException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class AlreadySignedException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    public:
        Form();
        Form(const std::string, const int, const int);
        Form(const Form&);
        Form& operator=(const Form&);
        ~Form();
        int         getSignGrade() const;
        int         getExecGrade() const;
        std::string getName() const;
        bool        getSignedStatus() const;
        void        beSigned(const Bureaucrat&);
        int         checkGrade(int) const;

    private:
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExec;
        bool                isSigned;
};

std::ostream& operator<<(std::ostream&, const Form&);

#endif