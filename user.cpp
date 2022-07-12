#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <vector>
#include <windows.h>
class archivo;

using namespace std;

class user : public archivo
{
protected:
    int id;
    string username;
    string pw;

public:
    int countlines(string);
    bool findByField(string _filename, int _column, string _field);
    bool login(string _filename, string _username, string _pw);
};

int user::countlines(string _filename)
{
    string filename = _filename;
    string lines;
    int count = 0;
    fstream file(filename, ios::in);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, lines);
            count++;
        }
        file.close();
        return count;
    }
    else if (!file.is_open())
    {
        file.open(filename, ios::out | ios::app | ios::in);
        while (!file.eof())
        {
            getline(file, lines);
            count++;
        }
        file.close();
        return count;
    }
    else
    {
        cout << "ERROR: No se pudo abrir el archivo";
        return 0;
    }
}

bool user::findByField(string _filename, int _column, string _field)
{
    string row_content, field_content; // To read each line from code, to store every field in the line

    int row = 0; // Variable to keep count of each line
    int column = 0;

    fstream file(_filename);
    file.open(_filename);
    while (getline(file, row_content))
    {
        cout << "whole row   " << row_content << endl;
        column = 0;
        while (row_content, field_content, ',')
        {
            cout << "field value   " << field_content << endl;

            if (column == _column)
            {
                if (field_content == _field)
                {
                    file.close();
                    return true;
                }
            }
            column++;
        }
        row++;
    }
    file.close();
    return false;
}

bool user::login(string _filename, string _username, string _pw)
{

    cout << "findByField(_filename, 1, _username)    " << findByField(_filename, 1, _username) << endl;
    cout << "findByField(_filename, 2, _pw)    " << findByField(_filename, 2, _pw) << endl;
    if (findByField(_filename, 1, _username))
    {
        if (findByField(_filename, 2, _pw))
        {
            return true;
        }
    }
    else
    {
        cout << "\nERROR. El nombre de usuario que ingreso no fue encontrado.\n";
        return false;
    }
}
