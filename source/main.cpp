#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
#include <string>
#include <vector>
#include "calculator.hpp"
#include "commandLineArgs.hpp"

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

float moreCalculating(Calculator::MathCalculator<float>& calculator) {
    std::string operation;
    std::string number;

    bool inputComplete = false;

    std::cout << "Enter an operator (+, -, *, /): " << "\n";
    getline(std::cin, operation);
    
    while (!inputComplete) {
        std::cout << "Enter one number at a time (or press q to stop):" << "\n";
        std::cin >> number;
        if (number == "q") {
            inputComplete = true;
        } else {
            if (calculator.contains_number(number)) {
                calculator.setVector(std::stof(number));
            } else break;
        }
    }

    return calculator.CalculateMoreInt(operation);
} 

int main(int argc, char* argv[]) {
    CMDArgs cmd{};
    int cmdArgsResult = 1;
   
    for (size_t q{ 1 }; q < argc; q++) {
        std::string argument2 = std::string(argv[q]);
        cmdArgsResult = cmd.setFromCommandArgs(argc, std::move(argument2));
    }
    
    if (cmdArgsResult == 0) return EXIT_SUCCESS;
    else if (cmdArgsResult == 1) {
        std::vector<float> calInt{};
        Calculator::MathCalculator<float> cal{ calInt };

        float answer = moreCalculating(cal);
        std::cout << "The answer is: " << answer << "\n";

        return EXIT_SUCCESS;
    } else if (cmdArgsResult == 2) {
        Calculator::MathCalculator<float> cal;
        std::string operation;

        std::string fullStringInts;

        std::cout << "Enter an operator (+, -, *, /): " << std::endl; std::cin >> operation;
        std::cin.ignore();
        std::cout << "Enter two numbers with a space: " << std::endl; 
        getline(std::cin, fullStringInts);

        int pos = fullStringInts.find(" ");
        float a = std::stof(fullStringInts.substr(0, pos));
        float b = std::stof(fullStringInts.substr(pos + 1));

        std::cout << "The answer to " << a << " " << operation << " " << b << " is " << cal.CalculateInt(operation, a, b) << std::endl;

    } else return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
  
