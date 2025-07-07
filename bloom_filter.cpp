#include "bloom_filter.hpp"
#include <functional>

BloomFilter::BloomFilter() {}

void BloomFilter::insert(const std::string& str) {
    bits[hash1(str) % bits.size()] = 1;
    bits[hash2(str) % bits.size()] = 1;
}

bool BloomFilter::possibly_contains(const std::string& str) const {
    return bits[hash1(str) % bits.size()] && bits[hash2(str) % bits.size()];
}

size_t BloomFilter::hash1(const std::string& str) const {
    return std::hash<std::string>{}(str);
}

size_t BloomFilter::hash2(const std::string& str) const {
    std::hash<std::string> hasher;
    return hasher("salt" + str);
}