#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <exception>
#include <new>
#include <string>
#include "calculator.hpp"

using namespace std;

constexpr void assert_that(bool condition, const char* message) {
    if (!condition) throw std::runtime_error{ message };
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
        cout << "[+] Test " << name << " successful.\n";
    } catch (const std::exception& e) {
        cout << "[-] Test failure in " << name << ". " << e.what() << "\n";
    }
}

int main() {
    MathCalculator calculator{};

    int a{};
    int b{};

    std::string stringA{};
    std::string stringB{};

    cout << "Enter an operator (+, -, *, /): ";
    getline(std::cin, stringA);
    cout << "Enter two numbers with a space in-between them: ";
    getline(std::cin, stringB);

    int pos = stringB.find(" ");

    std::string a_str = stringB.substr(0, pos);
    std::string b_str = stringB.substr(pos + 1);

    a = std::stoi(a_str);
    b = std::stoi(b_str);

    int answer = calculator.CalculateInt(stringA, a, b);

    cout << "The answer to " << a << " " << stringA << " " << b << " is " << answer << "\n";

    return 0;
}