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

    cout <<"Ingrese el código del usuario"<<endl;




    while (!(cin >> CodUsuario)) {

        system("cls");

        try {

            throw "Opción no válida, ingrese solo números.";

        }

        catch(const char* s) {

            cerr << s << endl;

            cin.clear();

            cin.ignore(100, '\n');

        }

    }

    cout << "El código de usuario ingresado es: " << CodUsuario << endl;

    return 0;
