/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:42:08 by oelhasso          #+#    #+#             */
/*   Updated: 2026/03/11 17:42:09 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExec) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw Form::GradeTooLowException();
}

void Form::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

// Exception messages
const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade requirements are too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Bureaucrat grade is too low to sign this form!";
}

// Getters
std::string Form::getName() const { return _name; }
bool Form::getIsSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExec() const { return _gradeToExec; }

// Orthodox Canonical Form
Form::Form() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}
Form::~Form() {}
Form::Form(const Form& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

Form& Form::operator=(const Form& other) {
    if (this != &other)
        this->_signed = other._signed; // Only non-const member can be assigned
    return *this;
}

std::ostream& operator<<(std::ostream& o, const Form& f) {
    o << "Form: " << f.getName() << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Sign-Grade: " << f.getGradeToSign() << " | Exec-Grade: " << f.getGradeToExec();
    return o;
}