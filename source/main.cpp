#include <iostream>
#include <stdexcept>
#include <exception>
#include <new>
#include <string>
#include <vector>
#include "calculator.hpp"
//#include "commandLineArgs.hpp"

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

float moreCalculating(MathCalculator<float>& calculator) {
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
                calculator.setVector(std::stof(number));
            } else break;
        }
    }

    return calculator.CalculateMoreInt(operation);
} 

int main(int argc, char* argv[]) {
    /*CMDArgs cmd{};

    for (size_t q{ 1 }; q < argc; q++) {
        std::string argument = std::string(argv[q]);
        cmd.setFromCommandArgs(argc, argument);
    }*/

    std::vector<float> calInt{};
    MathCalculator<float> calculator{ calInt };

    //if (!cmd.getAdd() && !cmd.getSubtract() && !cmd.getMutiply() && !cmd.getDivide()) {
    float answer = moreCalculating(calculator);
    std::cout << "The answer is: " << answer << "\n";
    //}

    return 0;
}
  
