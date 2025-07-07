#pragma once
#include <string>

bool check_plagiarism(const std::string& code1, const std::string& code2);

// === src/tokenizer.cpp ===
#include "tokenizer.hpp"
#include <sstream>
#include <unordered_map>

std::vector<int> tokenize(const std::string& code) {
    std::unordered_map<std::string, int> token_map;
    std::vector<int> tokens;
    std::istringstream stream(code);
    std::string token;
    int id = 1;

    while (stream >> token) {
        if (!token_map.count(token)) {
            token_map[token] = id++;
        }
        tokens.push_back(token_map[token]);
    }
    return tokens;
}