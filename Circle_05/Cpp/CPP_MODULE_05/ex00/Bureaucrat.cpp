/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 17:01:42 by oelhasso          #+#    #+#             */
/*   Updated: 2026/03/05 01:33:45 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
    std::cout << "paramerized constructor called !\n";
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade = grade;
}

void Bureaucrat::incrementGrade() {
    if (this->_grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->_grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat grade is too high (above 1)!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low (below 150)!";
}

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {
    std::cout << "default constructor called !\n";
}

Bureaucrat::~Bureaucrat() {
    std::cout << "destructor called !\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
    std::cout << "copy constructor called !\n";
    *this = other;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    std::cout << "copy assignement operator called !\n";
    if (this != &other)
        this->_grade = other._grade;
    return *this;
}

std::string Bureaucrat::getName() const { return _name; }
int Bureaucrat::getGrade() const { return _grade; }

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
    o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return o;
}