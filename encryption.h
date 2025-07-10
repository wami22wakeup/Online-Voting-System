#pragma once
#include <string>

std::string encrypt(std::string data, char key = '#') {
    for (auto &ch : data)
        ch ^= key;
    return data;
}