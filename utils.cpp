// utils.cpp
#include "utils.h"

bool hasVoted(const std::string &voterID) {
    std::ifstream file("voted_users.txt");
    std::string id;
    while (file >> id) {
        if (id == voterID) return true;
    }
    return false;
}

void markVoted(const std::string &voterID) {
    std::ofstream file("voted_users.txt", std::ios::app);
    file << voterID << std::endl;
}
