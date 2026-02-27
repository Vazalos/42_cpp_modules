#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>

class Bureaucrat;

class AForm
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

    class NotSignedException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    public:
        AForm(const std::string, const int, const int, const std::string);
        AForm(const AForm&);
        AForm& operator=(const AForm&);
        virtual ~AForm() = 0;
        std::string getName() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        bool        getSignedStatus() const;
        void        beSigned(const Bureaucrat&);
        int         checkGrade(int) const;
        virtual void    execute(Bureaucrat const & executor) const;

    private:
        AForm();
        const std::string   name;
        const int           gradeToSign;
        const int           gradeToExec;
        bool                isSigned;
        const std::string   target;
};

std::ostream& operator<<(std::ostream&, const AForm&);

#endif