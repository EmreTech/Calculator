#include "commandLineArgs.hpp"

int CMDArgs::setFromCommandArgs(int argc, std::string argv) {
    if (!argv.empty()) all_args.emplace_back(argv);
    else return 1;
    
    
    for (size_t x { 0 }; x < all_args.size(); x++) {
        if (all_args[x] == "-h" || all_args[x] == "-help") {
            std::cout << "Calculator program by EmreTech\n\t-h || --help | Show this screen\n\t-v || --verbose | Prints all functions called (used for debugging)\n" << 
            "\t-2 || --Calculate2Nums | Uses the older method which calculates only up to two ints\n" << std::endl;
            return 0;
        } else if (all_args[x] == "-v" || all_args[x] == "--verbose") {
            verbose = true;
            std::cout << "Verbose mode enabled.\n";
            return 1;
        } else if (all_args[x] == "-2" || all_args[x] == "--Calculate2Nums") {
            return 2;
        } else return 1;
    }

    return -1;
}