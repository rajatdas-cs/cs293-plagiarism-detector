#include "winnowing.hpp"
#include <deque>
#include <limits>

std::set<int> winnow(const std::vector<int>& tokens, int k, int w) {
    std::vector<int> hashes;
    for (size_t i = 0; i <= tokens.size() - k; ++i) {
        int hash = 0;
        for (size_t j = 0; j < k; ++j) {
            hash = hash * 31 + tokens[i + j];
        }
        hashes.push_back(hash);
    }
    std::set<int> fingerprints;
    std::deque<int> window;
    for (size_t i = 0; i < hashes.size(); ++i) {
        while (!window.empty() && window.front() <= i - w) window.pop_front();
        while (!window.empty() && hashes[window.back()] >= hashes[i]) window.pop_back();
        window.push_back(i);
        if (i >= w - 1) fingerprints.insert(hashes[window.front()]);
    }
    return fingerprints;
}