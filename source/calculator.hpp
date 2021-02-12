#pragma once

#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include <utility>
#include <type_traits>

namespace Calculator {
template <typename T>
struct MathCalculator {

    MathCalculator () {}
    MathCalculator (std::vector<T> Vector) : VectorCalculator{ Vector } {
        static_assert(std::is_arithmetic<T>(), "Type must support Math operations");
        static_assert(std::is_default_constructible<T>(), "Type must be Default Constructible");
    }
    
    // Smaller functions for solving problems. Used mostly in the function below
    static T Addition(T a, T b) {
        T answer{};
        answer = a + b;
        return answer;
    }
    static T Subtraction(T a, T b) {
        T answer{};
        answer = a - b;
        return answer;
    }
    static T Mutiplication(T a, T b) {
        T answer{};
        answer = a * b;
        return answer;
    }
    static T Division(T a, T b) {
        T answer{};
        answer = a / b;
        return answer;
    }

    // Function for solving a problem for addition, subtraction, mutiplication, and division
    T CalculateInt(std::string Operator, T a, T b) {
        // Find out what operator the user is using, then solve
        if (Operator == "+" || Operator == "addition") return this->Addition(a, b);
        if (Operator == "-" || Operator == "subtraction") return this->Subtraction(a, b);
        if (Operator == "*" || Operator == "mutiplication") return this->Mutiplication(a, b);
        if (Operator == "/" || Operator == "division") return this->Division(a, b);

        // Returns the answer for another variable
        return 0;
    }

    T CalculateMoreInt(std::string_view Operator) {
        T answer = VectorCalculator[0];
        VectorCalculator.erase(VectorCalculator.begin());

        while (!VectorCalculator.empty()) {
            switch (turnStringToIntOperator(Operator)) {
            case 1:
            answer += VectorCalculator[0];
            break;

            case 2:
            answer -= VectorCalculator[0];
            break;

            case 3:
            answer *= VectorCalculator[0];
            break;

            case 4:
            answer /= VectorCalculator[0];
            break;

            default:
            break;
            }

            VectorCalculator.erase(VectorCalculator.begin());
        }

        return answer;
    }

    bool contains_number(std::string str) {
    	return (str.find_first_of("0123456789") != std::string::npos);
    }

    int turnStringToIntOperator (std::string_view string) {
        if (string == "+" || string == "-" || string == "*" || string == "/") {
            if (string == "+") return 1;
            if (string == "-") return 2;
            if (string == "*") return 3;
            if (string == "/") return 4;
        } else return 0;

        return 0; 
    }

    void setVector(T newInt){
        VectorCalculator.emplace_back(newInt);
    }

    private:
    std::vector<T> VectorCalculator;
};
}
