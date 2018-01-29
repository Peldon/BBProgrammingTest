#include "Blackboard.h"


void Blackboard::SetBool(std::string key, bool value) {
    bools[key] = value;
}
bool Blackboard::GetBool(std::string key) {
    if (bools.find(key) == bools.end()) {
        bools[key] = false;
    }
    return bools[key];
}
void Blackboard::SetInt(std::string key, int value) {
    ints[key] = value;
}
int Blackboard::GetInt(std::string key) {
    if (ints.find(key) == ints.end()) {
        ints[key] = 0;
    }
    return ints[key];
}
void Blackboard::SetUInt(std::string key, unsigned int value) {
    uints[key] = value;
}
int Blackboard::GetUInt(std::string key) {
    if (uints.find(key) == uints.end()) {
        uints[key] = 0;
    }
    return uints[key];
}
void Blackboard::SetString(std::string key, std::string value) {
    strings[key] = value;
}
std::string Blackboard::GetString(std::string key) {
    if (strings.find(key) == strings.end()) {
        strings[key] = "";
    }
    return strings[key];
}

