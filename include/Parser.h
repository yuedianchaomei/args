#pragma once

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <vector>

class Parser{
private:
    std::unordered_map<std::string, std::string> _args;
    std::vector<std::string> _positionalArgs;
    std::string _programName;

public:
    Parser(int argc, char* argv[]);
    bool has(const std::string &name) const;
    std::string get(const std::string &name, const std::string &defaultValue) const;
    std::vector<std::string> getPositionalArgs() const;
    void printHelp() const;

};