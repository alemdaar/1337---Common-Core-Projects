/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:19:54 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/04 22:01:43 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > this->_gradeToSign)
        throw AForm::GradeTooLowException();
    this->_signed = true;
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "grade requirements are too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "grade requirements are too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is Not Signed";
}


// Getters
std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

// Orthodox Canonical AForm
AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}
AForm::~AForm() {}
AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), 
      _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other)
        this->_signed = other._signed; // Only non-const member can be assigned
    return *this;
}

std::ostream& operator<<(std::ostream& o, const AForm& f) {
    o << "AForm: " << f.getName() << " | Signed: " << (f.getIsSigned() ? "Yes" : "No")
      << " | Sign-Grade: " << f.getGradeToSign() << " | Exec-Grade: " << f.getGradeToExec();
    return o;
}