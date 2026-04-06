/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:20:13 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/06 20:14:38 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
private:
    const std::string _name;
    bool              _signed;
    const int         _gradeToSign;
    const int         _gradeToExec;

public:
    AForm();
    AForm(const std::string name, int gradeToSign, int gradeToExec);
    AForm(const AForm& other);
    virtual ~AForm();
    AForm& operator=(const AForm& other);

    std::string getName() const;
    bool        getIsSigned() const;
    int         getGradeToSign() const;
    int         getGradeToExec() const;

    void beSigned(const Bureaucrat& b);
    
    virtual void execute(Bureaucrat const & executor) const = 0;
    void checkExecutionRequirements(Bureaucrat const & executor) const;

    class GradeTooHighException : public std::exception {
        public: virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        public: virtual const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
        public: virtual const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif