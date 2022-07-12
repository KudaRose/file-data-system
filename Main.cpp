#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <windows.h>
#include "archivo.cpp"
#include "user.cpp"
#include "product.cpp"
#include "cliente.cpp"
#include "admin.cpp"

using namespace std;

int main()
{
    cout << "Bienvenido al sistema Crackhead\n"
         << endl;

    while (true)
    {
        string access = "";
        cout << "Seleccione como quiere ingresar al sistema:\n";
        cout << "1-Usuario\n2-Administrador\nO en su defecto:\n3-Crear usuario\n4-Salir del programa\nIngrese su opcion:";
        cin >> access;
        if (access == "1")
        {
            string uname;
            string pw;
            cin.ignore();
            cout << "Ingrese su nombre de usuario: ";
            getline(cin, uname);
            cout << "Ingrese su contrasenia: ";
            getline(cin, pw);
            cliente a = cliente(uname, pw);
            if (a.login("user.txt", uname, pw))
            {
                a.~cliente();
                // Acceder como usuario
                // Loop del usuario
            }
        }
        else if (access == "2")
        {
            string uname;
            string pw;
            cin.ignore();
            cout << "Ingrese su nombre de administrador: ";
            getline(cin, uname);
            cout << "Ingrese su contrasenia: ";
            getline(cin, pw);
            admin admn = admin(uname, pw);
            if (admn.login("admin.txt", uname, pw))
            {
                admn.~admin();
                cout << "\nBienvenido Administrador\n"
                     << endl;
                Sleep(1500);
                system("cls");
                do
                {
                    cout << "Menu de Administrador\n";
                    cout << "1-Crear\n2-Borrar\n3-Modificar\n4-Obtener listado\n5-Cargar un nuevo administrador\n6-Salir del programa\nIngrese su opcion:";
                    cin >> access;
                    if (access == "1")
                    {
                    }
                    else if (access == "5")
                    {
                        cout << "\nPorfavor inicie sesion nuevamente para continuar.\n";
                        cin.ignore();
                        cout << "Ingrese su nombre de administrador: ";
                        getline(cin, uname);
                        cout << "Ingrese su contrasenia: ";
                        getline(cin, pw);
                        admin admn = admin(uname, pw);
                        // cout << admn.login("admin.txt", uname, pw) << endl;
                        cout << admn.findByField("admin.txt", 3, "0");
                        if (admn.login("admin.txt", uname, pw) && admn.findByField("admin.txt", 3, "0") == true)
                        {
                            admn.~admin();
                            cout << "\nAsigne el nombre del administrador: ";
                            getline(cin, uname);
                            cout << "Asigne su contrasenia: ";
                            getline(cin, pw);

                            admin admini(uname, pw, "1");
                            admini.save("admin.txt");
                            admini.~admin();
                            // Sleep(1500);
                            // system("cls");
                        }
                        else
                        {
                            cout << "ERROR. No cuenta con los permisos necesarios para crear un nuevo administrador";
                        }
                    }
                    else if (access == "6")
                    {
                        cout << "\nHasta luego" << endl;
                        break;
                    }

                } while (true);
            }

            // Acceder como administrador
            // Loop de administrador
        }
        else if (access == "3")
        {
            string _uname;
            string _pw;
            cin.ignore();
            cout << "Ingrese su nombre de usuario: ";
            getline(cin, _uname);
            cout << "Ingrese su contrasenia: ";
            getline(cin, _pw);
            cliente client = cliente(_uname, _pw, "");
            client.save("user.txt");
            client.~cliente();
            // Sleep(1500);
            // system("cls");
        }
        else if (access == "4")
        {
            cout << "Gracias por usar el sistema";
            exit(0);
        }
        else
        {
            cout << "\nIngrese una opcion valida\n";
            Sleep(1500);
            system("cls");
        }
    }
    return 0;
}
