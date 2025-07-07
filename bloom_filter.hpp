#pragma once
#include <bitset>
#include <string>

class BloomFilter {
public:
    BloomFilter();
    void insert(const std::string& str);
    bool possibly_contains(const std::string& str) const;
private:
    std::bitset<10000> bits;
    size_t hash1(const std::string& str) const;
    size_t hash2(const std::string& str) const;
};