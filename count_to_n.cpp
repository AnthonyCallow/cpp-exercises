#include <iostream>
using namespace std;
int main() {
    int numero;
    cout << "Ingrese un numero: ";
    cin >> numero;
    for (int contador = 1; contador <= numero; contador++) {
        cout << contador << " ";
    }
    cout << endl;
    return 0;
}
