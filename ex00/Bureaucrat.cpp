/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crmorale <crmorale@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 20:32:55 by crmorale          #+#    #+#             */
/*   Updated: 2026/04/12 20:37:57 by crmorale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//CONSTRUCTORS
Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
	std::cout << "Bureaucrat called " << _name << " has been created" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
		if (this != &other) {
			_grade = other._grade;
			std::cout << "Bureaucrat assignment operator called" << std::endl;
		}
			return (*this);
}

//GETTERS

std::string	Bureaucrat::getName() const {
	return (this->_name);
}

int	Bureaucrat::getGrade() const {
	return (this->_grade);	
}

//INCREMENT - DECREMENT GRADE

void	Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	else
		_grade--;  
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Exception: Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Exception: Grade is too low");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &b) {
	os << b.getName() << " bureaucrat grade " << b.getGrade() << std::endl;
	return (os);
}
