/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelhasso <oelhasso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:02:20 by oelhasso          #+#    #+#             */
/*   Updated: 2026/04/03 21:02:56 by oelhasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class RobotomyRequestForm {
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        virtual ~RobotomyRequestForm();
}