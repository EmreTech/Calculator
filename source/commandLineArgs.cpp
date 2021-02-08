#include "commandLineArgs.hpp"

void CMDArgs::setFromCommandArgs(int argc, std::string argv) {
    for (size_t i{ 1 }; i < argc; i++) {
        all_args.emplace_back(argv[i]);
    }

    for (size_t x { 1 }; x < all_args.size(); x++) {
        if (all_args[x] == "-h" || all_args[x] == "-help") {
            std::cout << "Calculator program by EmreTech\n\n-h || --help | Show this screen\n-v || --verbose | Prints all functions called (used for debugging)\n" <<
            "-a || --addition | Does addition with any arguments called with the program\n-s || --subtraction | Does subtraction with any arguments called with the program\n-m || --mutiplication" << 
            "Does mutiplication with any arguments called with the program\n-d || --division Does division with any arguments called with the program" << "\n";
            return;
        } else if (all_args[x] == "-v" || all_args[x] == "--verbose") {
            verbose = true;
            std::cout << "Verbose mode enabled.\n";
        } else if (all_args[x] == "-a" || all_args[x]  == "--addition") {
            add = true;
            std::cout << "Addition mode with command args enabled.\n";
        } else if (all_args[x] == "-s" || all_args[x]  == "--subtraction") {
            subtract = true;
            std::cout << "Subtraction mode with command args enabled.\n";
        } else if (all_args[x] == "-m" || all_args[x]  == "--mutiplication") {
            mutiply = true;
            std::cout << "Mutiplication mode with command args enabled.\n";
        } else if (all_args[x] == "-d" || all_args[x] == "--division") {
            divide = true;
            std::cout << "Division mode with command args enabled.\n";
        } else break;
    }
}

int CMDArgs::solveFromArgs(int argc, MathCalculator& calculator) {
    for (size_t i{ 1 }; i < all_args.size(); i++) {
        if (all_args[i] == "-v" || all_args[i] == "--verbose" || all_args[i] == "-a" || all_args[i] == "--addition" || all_args[i] == "-s" || all_args[i] == "--subtraction" || 
        all_args[i] == "-m" || all_args[i] == "--mutiplication" || all_args[i] == "-d" || all_args[i] == "--division") {
            continue;
        } else {
            if (add) return calculator.CalculateMoreInt("+");
            else if (subtract) return calculator.CalculateMoreInt("-");
            else if (mutiply) return calculator.CalculateMoreInt("*");
            else if (divide) return calculator.CalculateMoreInt("/");
            else return 0;
        }
    }

    return 0;
}