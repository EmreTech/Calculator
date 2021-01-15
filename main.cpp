#include <iostream>
#include <chrono>
#include <thread>
#include <stdexcept>
#include <exception>
#include <new>
#include <string>
#include "calculator.hpp"

<<<<<<< HEAD
using namespace std;

=======
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803
constexpr void assert_that(bool condition, const char* message) {
    if (!condition) throw std::runtime_error{ message };
}

void run_test(void(*unit_test)(), const char* name) {
    try {
        unit_test();
<<<<<<< HEAD
        cout << "[+] Test " << name << " successful.\n";
    } catch (const std::exception& e) {
        cout << "[-] Test failure in " << name << ". " << e.what() << "\n";
=======
        std::cout << "[+] Test " << name << " successful.\n";
    } catch (const std::exception& e) {
        std::cout << "[-] Test failure in " << name << ". " << e.what() << "\n";
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803
    }
}

void additionTest() {
    MathCalculator calculator{};

    std::string one_str = "1";
    std::string ten_str = "10";
    std::string hundred_str = "100";

    int one = std::stoi(one_str);
    int ten = std::stoi(ten_str);
    int hundred = std::stoi(hundred_str);

<<<<<<< HEAD
    cout << one << " " << ten << " " << hundred << "\n";
=======
    std::cout << one << " " << ten << " " << hundred << "\n";
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803

    assert_that(calculator.CalculateInt("+", 1, 1) == 2, "The Calculation failed.");
    assert_that(calculator.CalculateInt("+", 10, 10) == 20, "The Calculation failed.");
    assert_that(calculator.CalculateInt("+", 100, 100) == 200, "The Calculation failed.");

    assert_that(calculator.CalculateInt("+", one, one) == 2, "The Calculation failed.");
    assert_that(calculator.CalculateInt("+", ten, ten) == 20, "The Calculation failed.");
    assert_that(calculator.CalculateInt("+", hundred, hundred) == 200, "The Calculation failed.");
}

void subtractionTest() {
    MathCalculator calculator{};

    std::string one_str = "1";
    std::string ten_str = "10";
    std::string hundred_str = "100";

    int one = std::stoi(one_str);
    int ten = std::stoi(ten_str);
    int hundred = std::stoi(hundred_str);

<<<<<<< HEAD
    cout << one << " " << ten << " " << hundred << "\n";
=======
    std::cout << one << " " << ten << " " << hundred << "\n";
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803

    assert_that(calculator.CalculateInt("-", 1, 1) == 0, "The Calculation failed.");
    assert_that(calculator.CalculateInt("-", 10, 10) == 0, "The Calculation failed.");
    assert_that(calculator.CalculateInt("-", 100, 100) == 0, "The Calculation failed.");

    assert_that(calculator.CalculateInt("-", one, one) == 0, "The Calculation failed.");
    assert_that(calculator.CalculateInt("-", ten, ten) == 0, "The Calculation failed.");
    assert_that(calculator.CalculateInt("-", hundred, hundred) == 0, "The Calculation failed.");
}

int main() {
    MathCalculator calculator{};

    int a{};
    int b{};

    std::string stringA{};
    std::string stringB{};

<<<<<<< HEAD
    cout << "Enter an operator (+, -, *, /): ";
    getline(std::cin, stringA);
    cout << "Enter two numbers with a space in-between them: ";
=======
    std::cout << "Enter an operator (+, -, *, /): ";
    getline(std::cin, stringA);
    std::cout << "Enter two numbers with a space in-between them: ";
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803
    getline(std::cin, stringB);

    int pos = stringB.find(" ");

    std::string a_str = stringB.substr(0, pos);
    std::string b_str = stringB.substr(pos + 1);

    a = std::stoi(a_str);
    b = std::stoi(b_str);

    int answer = calculator.CalculateInt(stringA, a, b);

<<<<<<< HEAD
    cout << "The answer to " << a << " " << stringA << " " << b << " is " << answer << "\n";
=======
    std::cout << "The answer to " << a << " " << stringA << " " << b << " is " << answer << "\n";
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803

    //run_test(additionTest, "Adding two numbers together");
    //run_test(subtractionTest, "Subtracting two numbers together");

    return 0;
}