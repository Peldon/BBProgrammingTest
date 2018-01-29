#pragma once
#include <map>

/* Data holder for information shared between nodes and iterations of a behavior tree
 * Stores data in maps and returns default values if no data was found
 */
class Blackboard {
public:
    void SetBool(std::string key, bool value) {
        bools[key] = value;
    }
    bool GetBool(std::string key) {
        if (bools.find(key) == bools.end()) {
            bools[key] = false;
        }
        return bools[key];
    }
    void SetInt(std::string key, int value) {
        ints[key] = value; 
    }
    int GetInt(std::string key) {
        if (ints.find(key) == ints.end()) {
            ints[key] = 0;
        }
        return ints[key];
    }
    void SetUInt(std::string key, unsigned int value) { 
        uints[key] = value; 
    }
    int GetUInt(std::string key) {
        if (uints.find(key) == uints.end()) {
            uints[key] = 0;
        }
        return uints[key];
    }
    void SetString(std::string key, std::string value) {
        strings[key] = value;
    }
    std::string GetString(std::string key) {
        if (strings.find(key) == strings.end()) {
            strings[key] = "";
        }
        return strings[key];
    }
private:
    std::map<std::string, bool> bools;
    std::map<std::string, int> ints;
    std::map<std::string, unsigned int> uints;
    std::map<std::string, std::string> strings;
};

