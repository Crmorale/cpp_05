#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

static void printLine(const std::string& title) {
    std::cout << "\n=== " << title << " ===" << std::endl;
}

int	main(void) {

    // Test an invalid grade above the maximum allowed value.
    printLine("Constructor grade = 151 (expects TooLow)");
    try {
        Bureaucrat l("Over", 151);
        std::cout << l << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test a normal increment from 2 to 1.
    printLine("Normal increment 2 -> 1");
    try {
        Bureaucrat inc("Inc", 2);
        std::cout << "Before: " << inc;
        inc.incrementGrade();
        std::cout << "After: " << inc;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    // Test incrementing the highest possible grade.
    printLine("Increment at 1 (expects TooHigh)");
    try {
        Bureaucrat top("Top", 1);
        top.incrementGrade();
        std::cout << "ERROR: no exception was thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test a normal decrement from 149 to 150.
    printLine("Normal decrement 149 -> 150");
    try {
        Bureaucrat dec("Dec", 149);
        std::cout << "Before: " << dec;
        dec.decrementGrade();
        std::cout << "After: " << dec;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    // Test decrementing the lowest possible grade.
    printLine("Decrement at 150 (expects TooLow)");
    try {
        Bureaucrat low("Low", 150);
        low.decrementGrade();
        std::cout << "ERROR: no exception was thrown" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // Test the copy constructor.
    printLine("Copy constructor");
    try {
        Bureaucrat base("Base", 42);
        Bureaucrat copy(base);
        std::cout << "Base: " << base;
        std::cout << "Copy: " << copy;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    // Test the assignment operator.
    printLine("Operator=");
    try {
        Bureaucrat lhs("Lhs", 120);
        Bureaucrat rhs("Rhs", 3);
        std::cout << "Before lhs: " << lhs;
        std::cout << "Before rhs: " << rhs;
        lhs = rhs;
        std::cout << "After lhs = rhs, lhs: " << lhs;
        std::cout << "After rhs: " << rhs;
    } catch (const std::exception& e) {
        std::cout << "Unexpected error: " << e.what() << std::endl;
    }

    return 0;
}
