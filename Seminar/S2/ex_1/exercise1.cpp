//
// Created by Luca Tudor on 19.03.2023.
//
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " inputfile outputfile" << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input) {
        std::cerr << "Error: cannot open input file '" << argv[1] << "'" << std::endl;
        return 1;
    }

    std::ofstream output(argv[2]);
    if (!output) {
        std::cerr << "Error: cannot open output file '" << argv[2] << "'" << std::endl;
        return 1;
    }

    std::string line;
    int count = 0;
    while (getline(input, line) && count < 5) {
        std::cout << line << std::endl;
        output << line << std::endl;
        count++;
    }

    input.close();
    output.close();

    return 0;
}

