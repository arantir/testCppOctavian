// structs.h
#ifndef STRUCTS_H
#define STRUCTS_H

#include <string>

using namespace std;

struct DrawData {
    std::string color;
    std::string shape;
    
    // Конструктор
    DrawData(const std::string& c, const std::string& s) : color(c), shape(s) {}
};

#endif // STRUCTS_H
