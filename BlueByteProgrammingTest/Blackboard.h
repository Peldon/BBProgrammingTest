#pragma once
#include <map>

/* Data holder for information shared between nodes and iterations of a behavior tree
 * Stores data in maps and returns default values if no data was found
 */
class Blackboard {
public:
    void SetBool(std::string key, bool value);
    bool GetBool(std::string key);
    void SetInt(std::string key, int value);
    int GetInt(std::string key);
    void SetUInt(std::string key, unsigned int value);
    int GetUInt(std::string key);
    void SetString(std::string key, std::string value);
    std::string GetString(std::string key);
private:
    std::map<std::string, bool> bools;
    std::map<std::string, int> ints;
    std::map<std::string, unsigned int> uints;
    std::map<std::string, std::string> strings;
};

