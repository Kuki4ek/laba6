#ifndef PARSER_H
#define PARSER_H
#include "vechicle.h"
#include "Car.h"
#include "Motorcycle.h"
#include <string>
using namespace std;
class Parser
{
    public:
        static Vehicle ParseStringToVechicle(string data);
        static Car ParseStringToCar(string data);
        static Motorcycle ParseStringToMotorcycle(string data);
        static string* Split(const string &str, const string &delimiter, int &count);
};

#endif
