#include "kmp.hpp"

static std::vector<int> compute_lps(const std::vector<int>& pattern) {
    std::vector<int> lps(pattern.size(), 0);
    int len = 0;
    for (size_t i = 1; i < pattern.size(); ) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else if (len != 0) {
            len = lps[len - 1];
        } else {
            lps[i++] = 0;
        }
    }
    return lps;
}

bool kmp_match(const std::vector<int>& text, const std::vector<int>& pattern) {
    auto lps = compute_lps(pattern);
    size_t i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            ++i; ++j;
        }
        if (j == pattern.size()) return true;
        else if (i < text.size() && text[i] != pattern[j]) {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }
    }
    return false;
}
