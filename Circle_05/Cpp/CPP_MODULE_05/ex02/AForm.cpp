/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:19:54 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/05 22:44:25 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {}

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute) 
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& src) 
    : _name(src._name), _signed(src._signed), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute) {}

AForm::~AForm() {}

AForm& AForm::operator=(const AForm& rhs) {
    if (this != &rhs)
        _signed = rhs._signed;
    return *this;
}

std::string AForm::getName() const { return _name; }
bool AForm::getSigned() const { return _signed; }
int AForm::getGradeToSign() const { return _gradeToSign; }
int AForm::getGradeToExecute() const { return _gradeToExecute; }

void AForm::beSigned(const Bureaucrat& b) {
    if (b.getGrade() > _gradeToSign)
        throw AForm::GradeTooLowException();
    _signed = true;
}

const char* AForm::GradeTooHighException::what() const throw() { return "Grade is too high!"; }
const char* AForm::GradeTooLowException::what() const throw() { return "Grade is too low!"; }
const char* AForm::FormNotSignedException::what() const throw() { return "Form is not signed!"; }

std::ostream& operator<<(std::ostream& o, const AForm& i) {
    o << "Form " << i.getName() << " | Signed: " << (i.getSigned() ? "Yes" : "No") 
      << " | Grade to Sign: " << i.getGradeToSign() 
      << " | Grade to Exec: " << i.getGradeToExecute();
    return o;
}