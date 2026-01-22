#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
    public:
        Bureaucrat();
        Bureaucrat(const std::string, unsigned int);
        Bureaucrat(const Bureaucrat&);
        Bureaucrat& operator=(const Bureaucrat&);
        ~Bureaucrat();
        std::string getName() const;
        unsigned int getGrade() const;
        unsigned int incrementGrade();
        unsigned int decrementGrade();

    private:
        const std::string   name;
        unsigned int        grade; //instantiate w/ an invalid grade = throw exception
        //class

};

std::ostream& operator<<(std::ostream&, const Bureaucrat&);

#endif