#include <chrono>
#include <thread>
#include <iostream>

struct MathCalculator {

    MathCalculator () {}

    int Addition(int a, int b);
    int Subtraction(int a, int b);
    int Mutiplication(int a, int b);
    int Division(int a, int b);

    // Function for solving a problem for addition, subtraction, mutiplication, and division
<<<<<<< HEAD
    int CalculateInt (std::string Operator, int a, int b);
=======
    int CalculateInt (std::string_view Operator, int a, int b);
>>>>>>> 855e2dbac0a181ecd751f8e22f7bea48c06f0803
};