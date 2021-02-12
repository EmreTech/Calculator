#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include "calculator.hpp"

struct CMDArgs {

    CMDArgs() {}

    int setFromCommandArgs(int argc, std::string argv);

    bool getVerbose() {
        return verbose;
    }

    private:
    bool verbose;

    std::vector<std::string> all_args;
};