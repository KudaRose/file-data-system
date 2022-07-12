#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
class user;

using namespace std;

class cliente : public user
{
private:
    string auxatrib;

public:
    cliente(string, string, string);
    cliente(string, string);
    ~cliente(){};
    bool save(string);
};

// Cliente
cliente::cliente(string _uname, string _pw, string _auxatrib)
{
    id = countlines("user.txt");
    username = _uname;
    pw = _pw;
    auxatrib = _auxatrib;
}

cliente::cliente(string _username, string _pw)
{
}

bool cliente::save(string _filename)
{
    string userdata;
    if (this->username != "" and this->pw != "" and user::findByField(_filename, 1, this->username) != true)
    {
        userdata = to_string(this->id) + "," + this->username + "," + this->pw + "\n";
        fstream file(_filename, ios::app);
        if (file.is_open())
        {
            file << userdata;
            file.close();
            cout << "Su registro fue exitoso, porfavor inicie sesion.";
            return true;
        }
        else if (!file.is_open())
        {
            return false;
        }
    }
    else
    {
        cout << "El nombre o la contrasenia que ingreso estan ocupados o no son validos. Porfavor vuelva a intentarlo\n";
        return false;
    }
}
