#include "commandLineArgs.hpp"

void CMDArgs::setFromCommandArgs(int argc, char** argv) {
    std::string stringArg = std::string(argv);

    for (size_t i{ 1 }; i < argc; i++) {
        std::string currentArg = stringArg[i];

        if (currentArg == "-h" || currentArg == "-help") {
            std::cout << "Calculator program by EmreTech\n\n-h || --help | Show this screen\n-v || --verbose | Prints all functions called (used for debugging)\n
            -a || --addition | Does addition with any arguments called with the program\n-s || --subtraction | Does subtraction with any arguments called with the program\n-m || --mutiplication 
            Does mutiplication with any arguments called with the program\n-d || --division Does division with any arguments called with the program" << "\n";
            return;
        } else if (currentArg == "-v" || currentArg == "--verbose") {
            verbose = true;
            std::cout << "Verbose mode enabled.\n";
        } else if (currentArg == "-a" || currentArg == "--addition") {
            add = true;
            std::cout << "Addition mode with command args enabled.\n";
        } else if (currentArg == "-s" || currentArg == "--subtraction") {
            subtract = true;
            std::cout << "Subtraction mode with command args enabled.\n";
        } else if (currentArg == "-m" || currentArg == "--mutiplication") {
            mutiply = true;
            std::cout << "Mutiplication mode with command args enabled.\n";
        } else if (currentArg == "-d" || currentArg == "--division") {
            divide = true;
            std::cout << "Division mode with command args enabled.\n";
        } else break;
    }
}

int CMDArgs::solveFromArgs(int argc, char** argv, MathCalculator& calculator) {
    std::string stringArg = std::string(argv);

    for (size_t i{ 1 }; i < argc; i++) {
        std::string currentArg = stringArg[i];

        if (currentArg == "-v" || currentArg == "--verbose" || currentArg == "-a" || currentArg == "--addition" || currentArg == "-s" || currentArg == "--subtraction" || 
        currentArg == "-m" || currentArg == "--mutiplication" || currentArg == "-d" || currentArg == "--division") {
            continue;
        } else {
            if (add) return calculator.CalculateMoreInt("+");
            else if (subtract) return calculator.CalculateMoreInt("-");
            else if (mutiply) return calculator.CalculateMoreInt("*");
            else if (divide) return calculator.CalculateMoreInt("/");
            else return 0;
        }
    }
}