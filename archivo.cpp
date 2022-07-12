#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>

using namespace std;

class archivo
{
public:
    bool save(string);
    readOne();
    readAll();
    findByField(string, int, string);
    bool deleteOne();
    bool update();
    int countlines();
    bool login(string, string, string);
};
