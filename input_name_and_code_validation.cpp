#include <iostream>

#include <string>

using namespace std;




int main() {

    int NomUsuario;

    do {

        cout << "Ingrese el nombre del usuario" << endl;

        cin, NomUsuario;


    return 0;

}


 Ejemplo 2:

#include <iostream>

using namespace std;




int main() {

    int CodUsuario;

    cout <<"Ingrese el c�digo del usuario"<<endl;




    while (!(cin >> CodUsuario)) {

        system("cls");

        try {

            throw "Opci�n no v�lida, ingrese solo n�meros.";

        }

        catch(const char* s) {

            cerr << s << endl;

            cin.clear();

            cin.ignore(100, '\n');

        }

    }

    cout << "El c�digo de usuario ingresado es: " << CodUsuario << endl;

    return 0;
