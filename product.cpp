#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
class archivo;

using namespace std;

class product : public archivo
{
private:
    const string filename = "products.txt";
    int id;
    int precio;
    string brand;
    string model;
    string coleccion;
    string genero;
    string type;
    string usage;
    string color;
    string size;
    string material;
    string reseller;
    string url;

public:
    product(int _precio, string _brand, string _model, string _coleccion, string _genero, string _type, string _usage, string _color, string _size, string _material, string _reseller, string _url)
    {
        precio = _precio;
        brand = _brand;
        model = _model;
        coleccion = _coleccion;
        genero = _genero;
        type = _type;
        usage = _usage;
        color = _color;
        size = _size;
        material = _material;
        reseller = _reseller;
        url = _url;
    }
};