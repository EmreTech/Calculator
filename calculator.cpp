#include "calculator.hpp"

int MathCalculator::Addition(int a, int b) {
        int answer{ 0 };
        answer = a + b;
        return answer;
}

int MathCalculator::Subtraction(int a, int b) {
    int answer{ 0 };
    answer = a - b;
    return answer;
}

int MathCalculator::Mutiplication(int a, int b) {
    int answer{ 0 };
    answer = a * b;
    return answer;
}

int MathCalculator::Division(int a, int b) {
    int answer{ 0 };
    answer = a / b;
    return answer;
}

int MathCalculator::CalculateInt (std::string Operator, int a, int b) {
    // Define the variable for the answer
    int answer{ 0 };

    // Find out what operator the user is using, then solve
    if (Operator == "+" || Operator == "addition") answer = Addition(a, b);
    if (Operator == "-" || Operator == "subtraction") answer = Subtraction(a, b);
    if (Operator == "*" || Operator == "mutiplication") answer = Mutiplication(a, b);
    if (Operator == "/" || Operator == "division") answer = Division(a, b);

    // Returns the answer for another variable
    return answer;
}
