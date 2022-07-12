#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
class user;

using namespace std;

class admin : public user
{
private:
    string admintype;

public:
    admin(string _username, string _pw, string _admintype);
    admin(string, string);
    ~admin(){};
    bool save(string);
};

// Administrador

admin::admin(string _username, string _pw, string _admintype)
{
    id = countlines("admin.txt");
    username = _username;
    pw = _pw;
    admintype = _admintype;
}

admin::admin(string _username, string _pw)
{
}

bool admin::save(string _filename)
{
    string admindata;
    if (this->username != "" and this->pw != "" and user::findByField(_filename, 1, this->username) != true)
    {
        admindata = to_string(this->id) + "," + this->username + "," + this->pw + "," + this->admintype + "\n";
        fstream file(_filename, ios::app);
        if (file.is_open())
        {
            file << admindata;
            file.close();
            cout << "El registro fue exitoso.\n";
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