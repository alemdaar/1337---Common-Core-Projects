/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:50:30 by oelhasso          #+#    #+#             */
/*   Updated: 2026/01/31 22:53:45 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}
Fixed::Fixed(const int n) : _value(n << _bits) {}
Fixed::Fixed(const float f) : _value(roundf(f * (1 << _bits))) {}
Fixed::Fixed(const Fixed &other) {
    *this = other;
}
Fixed::~Fixed() {}

Fixed &Fixed::operator=(const Fixed &other) {
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}
int Fixed::getRawBits(void) const {
    return this->_value;
}
void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}
float Fixed::toFloat(void) const {
    return (float)this->_value / (1 << _bits);
}
int Fixed::toInt(void) const {
    return this->_value >> _bits;
}
bool Fixed::operator>(const Fixed &other) const {
    return this->_value > other._value;
}
bool Fixed::operator<(const Fixed &other) const {
    return this->_value < other._value;
}
bool Fixed::operator>=(const Fixed &other) const {
    return this->_value >= other._value;
}
bool Fixed::operator<=(const Fixed &other) const {
    return this->_value <= other._value;
}
bool Fixed::operator==(const Fixed &other) const {
    return this->_value == other._value;
}
 bool Fixed::operator!=(const Fixed &other) const {
    return this->_value != other._value;
}
Fixed Fixed::operator+(const Fixed &other) const {
    return Fixed(this->toFloat() + other.toFloat());
}
Fixed Fixed::operator-(const Fixed &other) const {
    return Fixed(this->toFloat() - other.toFloat());
}
Fixed Fixed::operator*(const Fixed &other) const {
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const {
    return Fixed(this->toFloat() / other.toFloat());
}
Fixed &Fixed::operator++(void) {
    this->_value++;
    return *this;
}
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
Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    else
        return b;
}
Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}
const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    else
        return b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &i) {
    o << i.toFloat();
    return o;
}