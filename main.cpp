#include "plagiarism_engine.hpp"
#include <iostream>
#include <fstream>

std::string read_file(const std::string& path) {
    std::ifstream in(path);
    return std::string((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <file1> <file2>\n";
        return 1;
    }
    std::string code1 = read_file(argv[1]);
    std::string code2 = read_file(argv[2]);
    bool result = check_plagiarism(code1, code2);
    std::cout << (result ? "Plagiarism Detected" : "No Plagiarism") << std::endl;
    return 0;
}
