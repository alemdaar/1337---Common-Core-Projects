/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:50:30 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/30 18:41:09 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Constructors & Destructor
Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const int n) : _value(n << _bits) {}
Fixed::Fixed(const float f) : _value(roundf(f * (1 << _bits))) {}
Fixed::Fixed(const Fixed &other) { *this = other; }
Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// Basic Members
int Fixed::getRawBits(void) const {return this->_value; }
void Fixed::setRawBits(int const raw) { this->_value = raw; }
float Fixed::toFloat(void) const { return (float)this->_value / (1 << _bits); }
int Fixed::toInt(void) const { return this->_value >> _bits; }

// --- Comparison ---
bool Fixed::operator>(const Fixed &other) const { return this->_value > other._value; }
bool Fixed::operator<(const Fixed &other) const { return this->_value < other._value; }
bool Fixed::operator>=(const Fixed &other) const { return this->_value >= other._value; }
bool Fixed::operator<=(const Fixed &other) const { return this->_value <= other._value; }
bool Fixed::operator==(const Fixed &other) const { return this->_value == other._value; }
bool Fixed::operator!=(const Fixed &other) const { return this->_value != other._value; }

// --- Arithmetic ---
// Note: We convert to float to perform the math easily, then convert back
Fixed Fixed::operator+(const Fixed &other) const { return Fixed(this->toFloat() + other.toFloat()); }
Fixed Fixed::operator-(const Fixed &other) const { return Fixed(this->toFloat() - other.toFloat()); }
Fixed Fixed::operator*(const Fixed &other) const { return Fixed(this->toFloat() * other.toFloat()); }
Fixed Fixed::operator/(const Fixed &other) const { return Fixed(this->toFloat() / other.toFloat()); }

// --- Increment/Decrement ---
// Prefix (++a)
Fixed &Fixed::operator++(void) {
    this->_value++;
    return *this;
}

// Postfix (a++)
Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->_value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

// --- Min/Max ---
Fixed &Fixed::min(Fixed &a, Fixed &b) { return (a < b) ? a : b; }
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) { return (a < b) ? a : b; }
Fixed &Fixed::max(Fixed &a, Fixed &b) { return (a > b) ? a : b; }
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) { return (a > b) ? a : b; }

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}