/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 16:43:59 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/04 22:10:02 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
    std::cout << "default constructor\n";
    _name = "default";
    _signed = false;
    _gradeToSign = 145;
    _gradeToExec = 137;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name)
{
    std::cout << "parameterized constructor\n";
    _name = name;
    _signed = false;
    _gradeToSign = 145;
    _gradeToExec = 137;
    
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
{
    std::cout << "copy constructor\n";
    *this = other;
}
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << "copy assignemet operator\n";
    if (this == &other)
    {
        _name = other._name;
        _signed = other._signed;
        _gradeToSign = other._gradeToSign;
        _gradeToExec = other._gradeToExec;
    }
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "destructor\n";
}
// Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it.
void ShrubberyCreationForm::operation(Bureaucrat const & executor)
{
    // 1. First, check if the form is signed and grade is high enough
    // 1.1. Check if the form is signed
    // We use the getter because _isSigned is private in AForm
    if (this->getIsSigned() == false)
        throw AForm::FormNotSignedException();
    // 1.2. Check if the executor's grade is high enough
    // Numerically: 150 (Low) > 137 (Required) -> THROW
    if (executor.getGrade() > this->getGradeToExec())
        throw AForm::GradeTooLowException();

    // 2. Create the filename string
    std::string filename = target + "_shrubbery";

    // 3. Open the file (using .c_str() for C++98 compatibility)
    std::ofstream outfile(filename.c_str());

    // 4. Error handling: check if the file actually opened
    if (!outfile.is_open()) {
        throw std::runtime_error("Could not create file");
    }

    // 5. Write the ASCII trees
    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << "      ||      " << std::endl;

    // 6. Close the file
    outfile.close();
}
