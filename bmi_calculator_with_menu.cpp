// UNED I Cuatrimestre
// Introduccion a la programacion
// Proyecto 1
// Estudiante: Anthony Callow Monge
// Cedula 117150085
// 25 de febrero de 2024

//Fuentes referenciadas:
//C++ Library - . (s. f.). https://www.tutorialspoint.com/cpp_standard_library/iomanip.htm
//C++ Switch. (s. f.). https://www.w3schools.com/cpp/cpp_switch.asp
//Cátedra Tecnología de Sistemas /Informática UNED CR. (2024, 16 febrero). Sesión Virtual #1_Introducción a la Programación_IC2024 [Vídeo]. YouTube. https://www.youtube.com/watch?v=1Chz1DrMhnw
//cin.ignore(numeric_limits::max(), ’\n’). (s. f.). Stack Overflow. https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n
//IBM documentation. (s. f.). https://www.ibm.com/docs/en/debug-for-zos/14.2?topic=commands-break-command-c-c


#include <iostream> // Input, output y stream
#include <iomanip> // Se incluye para dar formato de 2 decimales utilizando setprecision y tambien darle formato al reporte
#include <limits> // Se incluye para que el programa no corra cada que vez que se ingresa una letra
using namespace std;

int main()
{
// Se declaran las variables segun su tipo
    int cedula, opcion;
    string nombre, diagnostico;
    float peso, talla, imc;
    cedula=0; //Se declara la cedula a 0 para que no se pueda acceder el reporte sin antes haber ingresado la cedula y nombre

// Bucle principal del programa
    do  {
//Opciones del menu principal
    cout << "****************************************" << endl;
    cout << "Calculadora de Indice de Masa Corporal" << endl;
    cout << "****************************************" << endl;
    cout << "1. Ingresar datos de la persona." << endl;
    cout << "2. Ingresar datos fisicos" << endl;
    cout << "3. Calcular el indice de masa corporal." << endl;
    cout << "4. Reporte de informacion del paciente." << endl;
    cout << "5. Salir." << endl;
    cout << "________________________________________" << endl;
    cout << "Por favor ingrese una opcion (1-5):" << endl;
    cin >> opcion;

// Manejo de error en caso de ingresar un valor no numerico en el menu
    if(cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); //se utiliza numeric_limits<streamsize>::max() para que el programa no vuelva a correr por cada caracter

    }

// Switch que maneja las opciones del menu
    switch (opcion) {

        case 1:
            do {
                cout << "Ingrese la cedula del paciente" << endl; // Bucle para verificar que la cedula se ingrese correctamente
                cin >> cedula;
            if(cin.fail())
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "El valor debe ser numerico y de 9 digitos" << endl;

                }
            //Condicional para que la cedula sea un dato valido
            else if (cedula < 100000000 || cedula > 999999999) {
                cout << "El valor debe ser numerico y de 9 digitos." << endl;
                }
            } while (cedula < 100000000 || cedula > 999999999);
                cout << "Ingrese el nombre del paciente" << endl;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Permite agregar espacios para los apellidos, \n significa enter
                getline(cin, nombre);
            //Reinicia el peso, talla e imc cada que vez se ingresa un nuevo paciente
                peso = 0;
                talla = 0;
                imc = 0;
                break; // Permite salirse del bucle de cada opcion

        case 2:

            do {
                cout << "Ingrese la talla en metros del paciente" << endl;
                cin >> talla;
             if(cin.fail()) // Maneja errores si se ingresan letras
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "El valor debe ser numerico, vuelva a intentarlo." << endl;

                }
            //Condicional para que la talla sea entre 0.30 y 3
            else if (talla < 0.30 || talla > 3.00) {
                cout << "Valor de talla fuera de rango" << endl;
                }
            } while (talla < 0.30 || talla > 3.00);

            do {
                cout << "Ingrese el peso en kilogramos del paciente" << endl;
                cin >> peso;
             if(cin.fail()) // Maneja errores si se ingresan letras
                {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "El velor debe ser numerico, vuelva a intentarlo." << endl;

                }
            //Condicional para que el peso sea entre 30 y 350
           else if (peso < 30 || peso > 350) {
                cout << "Valor del peso fuera de rango" << endl;


                peso = 0;
            }
            } while (peso < 30 || peso > 350);
            break; // Permite salirse del bucle de cada opcion

        case 3:
            cout << "Calculo del indice masa corporal" << endl;
            imc = peso / (talla * talla); // Calculo del IMC, se multiplica la talla por si misma para elevarla a la 2
            cout << fixed << setprecision(2); // Formato de 2 decimales
            cout << "El indice de masa corporal del paciente es: " << imc << endl; //Diagnostica al paciente segun el rango en que se encuentre
        if (imc < 18.5) {
            cout << "Se encuentra dentro del rango de peso insuficiente." << endl;
    } else if (imc >= 18.5 && imc < 25) { // Se podria eliminar el rango, es un check inecesario
            cout << "Se encuentra dentro del rango de peso normal o saludable" << endl;
    } else if (imc >= 25 && imc < 29.9) {
            cout << "Se encuentra dentro del rango de sobrepeso" << endl;
    } else {
            cout << "Se encuentra dentro del rango de obesidad" << endl;
            }
            break; // Permite salirse del bucle de cada opcion

        case 4:
            if (cedula==0) {
                cout << "Debe ingresar primero la informacion del paciente." << endl; // No permite acceder esta opcion hasta que la cedula sea diferente a 0, por lo tanto el usuario debio haber ingresado su nombre tambien
                break;
                } else {

                cout << "****************************************" << endl;
                cout << setw(34) << "Control del peso del paciente" << endl; // Uso de setw para dar formato al agregar caracteres
                cout << "****************************************" << endl;
                cout << setw(15) <<"Cedula: " << setw(10) << cedula << endl;
                cout << setw(15) <<"Nombre: " << setw(10) << nombre << endl;
                cout << fixed << setprecision(2); // Formato de 2 decimales
                cout << setw(15) << "Peso: " << setw(10) << peso << endl;
                cout << setw(15) << "Talla: " << setw(10) << talla << endl;
                cout << setw(15) << "IMC: " << setw(10) << imc << endl;
                cout << "----------------------------------------"<< endl;
                cout << setw(25) <<"Diagnostico"<< endl;
                cout << "----------------------------------------"<< endl; //Diagnostica al paciente segun el rango en que se encuentre
            if (imc < 18.5) {
            cout << "Se encuentra dentro del rango de peso insuficiente." << endl;
            } else if (imc >= 18.5 && imc < 25) {
                cout << "Se encuentra dentro del rango de peso normal o saludable" << endl;
            } else if (imc >= 25 && imc < 29.9) {
                cout << "Se encuentra dentro del rango de sobrepeso" << endl;
            } else {
                cout << "Se encuentra dentro del rango de obesidad" << endl;
                }
                break;
                        }

        case 5:
                cout << "Presione cualquier tecla para salir del programa" << endl; // Mensaje de finalizacion
                break; // Permite salirse del bucle de cada opcion

            default:
            cout << "Opcion invalida, vuelva a intentarlo." << endl; //Mensaje de error al ingresar una opcion incorrecta en el menu
    }

} while (opcion != 5); //Repite el bucle hasta que el usuario ingrese la opcion salir (5)"

    return 0;
}
