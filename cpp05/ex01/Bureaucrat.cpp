/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:00:21 by david-fe          #+#    #+#             */
/*   Updated: 2026/02/26 14:12:19 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("John Smith"), grade(150)
{
    std::cout << "Default Bureaucrat constructor called" << '\n';   
}

Bureaucrat::Bureaucrat(const std::string newName, int newGrade)
    : name(newName)
{
    setGrade(newGrade);
    std::cout << "Parameter Bureaucrat constructor called" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << '\n';
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    grade = other.grade;
    std::cout << "Bureaucrat copy assignment called" << '\n';
    return(*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << '\n';
}

std::string Bureaucrat::getName() const
{
    return(name);
}

int Bureaucrat::getGrade() const
{
    return(grade);
}

void Bureaucrat::setGrade(int newGrade)
{
    if (newGrade > 150)
        throw(GradeTooLowException());
    if (newGrade < 1)
        throw(GradeTooHighException());
    grade = newGrade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Invalid grade: max grade is 1");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Invalid grade: minimum grade is 150");
}

void Bureaucrat::incrementGrade()
{
    setGrade(grade - 1);
}

void Bureaucrat::decrementGrade()
{
    setGrade(grade + 1);
}

void Bureaucrat::signForm(Form& toSign)
{
    try
    {
        toSign.beSigned(*this);
        std::cout << this->name << " signed " << toSign.getName() << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << this->name << " couldn’t sign " << toSign.getName() << " because " << e.what() <<'\n';
    }
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& other)
{
    stream << other.getName() << ", bureaucrat grade " << other.getGrade();
    return(stream);
}