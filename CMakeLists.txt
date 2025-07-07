cmake_minimum_required(VERSION 3.10)
project(PlagiarismDetector)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(plagiarism_detector
    src/main.cpp
    src/tokenizer.cpp
    src/kmp.cpp
    src/lcs.cpp
    src/winnowing.cpp
    src/bloom_filter.cpp
    src/plagiarism_engine.cpp
    src/thread_pool.cpp
)