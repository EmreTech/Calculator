#include <iostream>
#include <string>
#include "calculator.hpp"

struct CMDArgs {

    CMDArgs() {}

    void setFromCommandArgs(int argc, char** argv);
    int solveFromArgs(int argc, char** argv, MathCalculator& calculator);

    bool getVerbose() {
        return verbose;
    }

    bool getAdd() {
        return add;
    }

    bool getSubtract() {
        return subtract;
    }

    bool getMutiply() {
        return mutiply;
    }

    bool getDivide() {
        return divide;
    }

    private:
    bool verbose;
    bool add;
    bool subtract;
    bool mutiply;
    bool divide;
};