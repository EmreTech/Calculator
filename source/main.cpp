#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
#include <string>
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

int moreCalculating(MathCalculator& calculator) {
    std::string operation;
    std::string number;

    bool inputComplete = false;

    std::cout << "Enter an operator (+, -, *, /): " << "\n";
    getline(std::cin, operation);
    
    while (!inputComplete) {
        std::cout << "Enter one number at a time (or press q to stop):" << "\n";
        getline(std::cin, number);
        if (number == "q") {
            inputComplete = true;
        } else {
            if (calculator.contains_number(number)) {
                calculator.setVector(std::stoi(number));
            } else break;
        }
    }

    int answer = calculator.CalculateMoreInt(operation);

    return answer;
} 

int main(int argc, char** argv) {
    CMDArgs cmd{};
    cmd.setFromCommandArgs(argc, argv);

    std::vector<int> calInt{};
    MathCalculator calculator{ calInt };

    if (!cmd.getAdd() && !cmd.getSubtract() && !cmd.getMutiply() && !cmd.getDivide()) {
        int answer = moreCalculating(calculator);
        std::cout << "The answer is: " << answer << "\n";
    } 

    return 0;
}
  
