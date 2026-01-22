/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david-fe <david-fe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:58:16 by david-fe          #+#    #+#             */
/*   Updated: 2026/01/09 15:10:24 by david-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    val = 0;
}

Fixed::Fixed( const int i )
{
    val = i << fractBits;
}

Fixed::Fixed( const float f )
{
    val = roundf(f * (1 << fractBits));
}

Fixed::Fixed(const Fixed& origFixed)
    :val(origFixed.val){
}

Fixed& Fixed::operator=(const Fixed& origFixed)
{
    if (this != &origFixed)
        val = origFixed.getRawBits();
    return(*this);
}

Fixed::~Fixed(){
}

int Fixed::getRawBits( void ) const{
    return(val);
}

void Fixed::setRawBits( int const raw ){
    val = raw;
}

float Fixed::toFloat( void ) const{
    return(static_cast<float>(val) / (1 << fractBits));
}

int Fixed::toInt( void ) const
{
    return(val >> fractBits);
}

bool Fixed::operator>(const Fixed& num) const{
    return(val > num.val);
}

bool Fixed::operator<(const Fixed& num) const{
    return(val < num.val);
}

bool Fixed::operator>=(const Fixed& num) const{
    return(val >= num.val);
}

bool Fixed::operator<=(const Fixed& num) const{
    return(val <= num.val);
}

bool Fixed::operator==(const Fixed& num) const{
    return(val == num.val);
}

bool Fixed::operator!=(const Fixed& num) const{
    return(val != num.val);
}

Fixed Fixed::operator+(const Fixed& num) const
{
	Fixed ret;
	ret.val = val + num.val;
	return ret;
}

Fixed Fixed::operator-(const Fixed& num) const
{
	Fixed ret;
	ret.val = val - num.val;
	return ret;
}

Fixed Fixed::operator*(const Fixed& num) const{
    return(Fixed(toFloat() * num.toFloat()));
}

Fixed Fixed::operator/(const Fixed& num) const{
    return(Fixed(toFloat() / num.toFloat()));
}

Fixed& Fixed::operator++( void ){ //prefix increment
    val += 1;
    return(*this);
}

Fixed Fixed::operator++( int ){ //postfix increment
    Fixed origVal;
    origVal.val = val;
    val += 1;
    return(origVal); //return original val after incrementing it
}

Fixed& Fixed::operator--( void ){ //prefix decrement
    val -= 1;
    return(*this);
}

Fixed Fixed::operator--( int ){ //postfix decrement
    Fixed origVal;
    origVal.val = val;
    val -= 1;
    return(origVal); //return original val after decrementing it
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return(a);
    else 
        return(b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() < b.getRawBits())
        return(a);
    else 
        return(b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    else 
        return(b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    if (a.getRawBits() > b.getRawBits())
        return(a);
    else 
        return(b);
}
        
std::ostream& operator<<(std::ostream& stream, const Fixed& fixedToFloat)
{
    return(stream << fixedToFloat.toFloat());
}