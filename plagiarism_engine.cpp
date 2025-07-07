#include "plagiarism_engine.hpp"
#include "tokenizer.hpp"
#include "kmp.hpp"
#include "lcs.hpp"
#include "winnowing.hpp"
#include "bloom_filter.hpp"

bool check_plagiarism(const std::string& code1, const std::string& code2) {
    auto tokens1 = tokenize(code1);
    auto tokens2 = tokenize(code2);

    int lcsScore = lcs_length(tokens1, tokens2);
    if (lcsScore > 0.7 * std::min(tokens1.size(), tokens2.size())) return true;

    auto fingerprints1 = winnow(tokens1, 5, 4);
    auto fingerprints2 = winnow(tokens2, 5, 4);
    int match = 0;
    for (int h : fingerprints2)
        if (fingerprints1.count(h)) ++match;
    if (match > 0.5 * fingerprints2.size()) return true;

    BloomFilter bf;
    for (int h : fingerprints1) bf.insert(std::to_string(h));
    for (int h : fingerprints2)
        if (!bf.possibly_contains(std::to_string(h))) return false;

    return true;
}