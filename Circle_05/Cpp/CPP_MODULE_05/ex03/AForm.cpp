/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:19:54 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/06 20:15:52 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
    if (gradeToSign < 1 || gradeToExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) 
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {}

AForm& AForm::operator=(const AForm& other) {
    if (this != &other) {
        this->_signed = other._signed;
    }
    return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

void AForm::checkExecutionRequirements(Bureaucrat const & executor) const {
    if (!_signed)
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > _gradeToExec)
        throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw() { return "AForm grade is too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "AForm grade is too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "AForm cannot be executed because it is not signed!"; }

std::ostream& operator<<(std::ostream& o, const AForm& f) {
    o << "Form " << f.getName() << " [Signed: " << (f.getIsSigned() ? "Yes" : "No") 
      << " | Sign Grade: " << f.getGradeToSign() << " | Exec Grade: " << f.getGradeToExec() << "]";
    return o;
}

