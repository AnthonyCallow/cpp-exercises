#include <iostream>

using namespace std;



int totalSalarios = 1;  // Almacena los salarios ingresados por el usuario


unsigned int contadorSalarios = 1;  // Suma la cantidad de salarios ingresados // Se utiliza el unsigned debido a que la cantidad de salarios siempre va ser un numero positivo





int main() {


    cout << "Bienvenido a la calculadora de aguinaldos" << endl;


        cout << "Indicacion: Ingrese su salario bruto y redondeado que a devengado en cada mes" << endl;





    // Bucle prinicipal que se repite hasta que contadorSalarios sea mayor o igual que 12


        while (contadorSalarios <= 12) {


        cout << "Escriba su salario recibido en el mes " << contadorSalarios << ": " << endl;


        int salario = 0;  // Variable para almacenar el salario ingresado


        cin >> salario;  // Se lee el salario ingresado por el usuario


        totalSalarios = totalSalarios + salario;  // Se suma el salario al total


        contadorSalarios = contadorSalarios + 1;  // Se incrementa el contador de meses


    }





    int aguinaldo = totalSalarios / 12;  // Se calcula el aguinaldo como el total de salarios dividido entre 12





    // Se muestra en muestra la suma de salarios recibidos y el aguinaldo acumulado


    cout << "Su salario total recibido es : " << totalSalarios << endl;


    cout << "Su aguinaldo acumulado es:  " << aguinaldo << endl;





    return 0;


}
