#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "calculator.hpp"

struct CMDArgs {

    CMDArgs() {}

    void setFromCommandArgs(int argc, std::string argv);
    int solveFromArgs(int argc, MathCalculator& calculator);

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

    std::vector<std::string> all_args;
};