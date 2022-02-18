#ifndef LITTVECMANGER
#define LITTVECMANGER
#include <iostream>
#include "Vector.hpp"
#include <string>

using std::endl;
using std::cout;

class VecManager
{
public:
    int Run();

    static double CustomInput(std::string);
    static void help();
};

#endif // LITTVECMANGER
