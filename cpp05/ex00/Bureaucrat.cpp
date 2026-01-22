/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:00:21 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/22 15:27:36 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("John Smith"), grade(150)
{
    std::cout << "Default Bureaucrat constructor called" << '\n';   
}

Bureaucrat::Bureaucrat(const std::string newName, unsigned int newGrade)
    : name(newName), grade(newGrade)
{
    std::cout << "Parameter Bureaucrat constructor called" << '\n';
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
    : name(other.name), grade(other.grade)
{
    std::cout << "Bureaucrat copy constructor called" << '\n';
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    //name = other.name; 
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

unsigned int Bureaucrat::getGrade() const
{
    return(grade);
}

unsigned int Bureaucrat::incrementGrade()
{
    try 
    {
        grade++;
        if (grade > 150)
            throw(grade);
    }
    catch (unsigned int wrongGrade)
    {
        std::cout << "Invalid grade detected. " << wrongGrade 
            << " is above max value of 150, and will be set to 150." << '\n';
        grade = 150;
    }
    return(grade);
}

unsigned int Bureaucrat::decrementGrade()
{
    try 
    {
        grade--;
        if (grade < 1)
            throw(grade);
    }
    catch (unsigned int wrongGrade)
    {
        std::cout << "Invalid grade detected. " << wrongGrade 
            << " is below min value of 1, and will be set to 1." << '\n';
        grade = 1;
    }
    return(grade);
}

std::ostream& operator<<(std::ostream& stream, const Bureaucrat& other)
{
    stream << other.getName() << ", bureaucrat grade " << other.getGrade();
    return(stream);
}