#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp" 

class Bureaucrat
{
    class GradeTooHighException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    class GradeTooLowException: public std::exception {
    public:
        virtual const char* what() const throw();
    };

    public:
        Bureaucrat(const std::string, int);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void setGrade(int);
        void incrementGrade();
        void decrementGrade();
        void signAForm(AForm&);

    private:
        Bureaucrat();
        const std::string   name;
        int        grade; 
};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif