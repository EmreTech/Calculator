#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <exception>
#include <new>
#include <string>
#include "calculator.hpp"

constexpr void assert_that(bool condition, const char* message) {
    if (!condition) throw std::runtime_error{ message };
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
        std::cout << "[+] Test " << name << " successful.\n";
    } catch (const std::exception& e) {
        std::cout << "[-] Test failure in " << name << ". " << e.what() << "\n";
    }
}
 

int main() {
    MathCalculator calculator{};

    int a{};
    int b{};

    std::string stringA{};
    std::string stringB{};

    std::cout << "Enter an operator (+, -, *, /): ";
    getline(std::cin, stringA);
    std::cout << "Enter two numbers with a space in-between them: ";
    getline(std::cin, stringB);

    int pos = stringB.find(" ");

    std::string a_str = stringB.substr(0, pos);
    std::string b_str = stringB.substr(pos + 1);

    bool a_result = calculator.contains_number(a_str);
    bool b_result = calculator.contains_number(b_str);

    if (a_result && b_result){
    	a = std::stoi(a_str);
    	b = std::stoi(b_str);
    }
    else {
        std::cout << "Any letters or symbols are not numbers. Please use numbers." << "\n";
    }

    int answer = calculator.CalculateInt(stringA, a, b);

    std::cout << "The answer to " << a << " " << stringA << " " << b << " is " << answer << "\n";

    return 0;
}
  
