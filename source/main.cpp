#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "calculator.hpp"
#include "commandLineArgs.hpp"

float moreCalculating() {
    std::string operation;
    std::string val;

    std::cout << "Enter an operator (+, -, *, /): " << std::endl; 
    std::cin >> operation;

    std::cin.get();

    std::cout << "Enter all numbers with a space in-between: " << std::endl;
    std::getline(std::cin, val);

    return Calculator::solve(val, operation);
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
        float answer = moreCalculating();
        std::cout << "The answer is: " << answer << "\n";

        return EXIT_SUCCESS;
    } else if (cmdArgsResult == 2) {
        Calculator::MathCalculator<float> cal;
        std::string operation;

        std::string fullStringInts;

        std::cout << "Enter an operator (+, -, *, /): " << std::endl; std::cin >> operation;
        std::cin.ignore();
        std::cout << "Enter two numbers with a space: " << std::endl; 
        std::getline(std::cin, fullStringInts);

        int pos = fullStringInts.find(" ");
        float a = std::stof(fullStringInts.substr(0, pos));
        float b = std::stof(fullStringInts.substr(pos + 1));

        std::cout << "The answer to " << a << " " << operation << " " << b << " is " << cal.CalculateInt(operation, a, b) << std::endl;

    } else return EXIT_FAILURE;

    return EXIT_FAILURE;
}
  
