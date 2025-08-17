//UNIVERSIDAD ESTATAL A DISTANCIA
//C.U: PURISCAL
//ESTUDIANTE: ANTHONY CALLOW MONGE
//PROYECTO 2 INTRODUCCION A LA PROGRAMACION
//CEDULA: 117150085
#include <iostream> // Input, output y stream
#include <iomanip> // Se incluye para dar formato de 2 decimales utilizando setprecision y tambien darle formato al reporte
#include <limits> // Se incluye para que el programa no corra cada que vez que se ingresa una letra
#include <fstream> // Libreria para poder leer archivos
using namespace std;
//Prototipos de las funciones
void ingresarProductos(string, string, float);
void buscarProductos(string);
void agregarAsociaciones (string,string);
void registrarRecetas (string, string, string, string, string);
void reporteProductos ();
void reporteRecetas ();
bool asociacionValida (string, string);
int main()
{
int opcion;
// Bucle que controla el menu
    do  {
//Opciones del menu principal
    cout << "Interfase para ingresar recetas" << endl;
    cout << "1. Ingresar productos." << endl;
    cout << "2. Ingresar asociaciones con productos." << endl;
    cout << "3. Registrar una receta." << endl;
    cout << "4. Reporte de catalogo de productos" << endl;
    cout << "5. Reporte impresion de la receta" << endl;
    cout << "6. Salir" << endl;
    cout << "Por favor ingrese una opcion (1-6):" << endl;
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
            {
            string codigoProducto, nombreProducto, confirmarIngreso;
            float cantidadProducto;
            cout <<"Ingrese el codigo del producto"<< endl;
            cin >> codigoProducto;
            cout <<"Ingrese el nombre del producto"<< endl;
            cin >> nombreProducto;
            cout <<"Ingrese la cantidad del producto"<< endl;
            cin >> cantidadProducto;
            cout << "Ingresar el medicamento? (S/N)" << endl;
            cin>> confirmarIngreso;
            if (confirmarIngreso == "S" || confirmarIngreso == "s") {
                         ingresarProductos(codigoProducto, nombreProducto, cantidadProducto);
                         break;
            } else if (confirmarIngreso == "N" || confirmarIngreso == "n") {
                        cout << "El medicamento no fue ingresado";
                    break;
            } else {
                        cout << "La opcion ingresada no es valida, debe ser S o N";
            }
            }
        case 2:
            {
             string busquedaProducto, productoEncontrado, asociacionProducto, confirmarAsociacion, nombreProducto;
             cout <<"Ingrese el codigo del producto"<< endl;
             cin >> busquedaProducto;
             //Se desplega el producto
                buscarProductos(busquedaProducto);
             cout <<"Ingrese la palabra asociativa"<< endl;
             cin >> asociacionProducto;
            cout << "Ingresar la asociacion? (S/N)" << endl;
            cin>> confirmarAsociacion;
            if (confirmarAsociacion == "S" || confirmarAsociacion == "s") {
              agregarAsociaciones(busquedaProducto,asociacionProducto);
                         break;
            } else if (confirmarAsociacion == "N" || confirmarAsociacion == "n") {
                        cout << "El medicamento no fue ingresado";
                    break;
            } else {
                        cout << "La opcion ingresada no es valida, debe ser S o N";
            }
            break;
            }
       case 3:
           {
           string numeroReceta, nombrePaciente,busquedaProducto,nombreProducto, productoEncontrado, indicacionProducto;
           float cantidadProducto; // Este fue declarado como float para poder restar y aumentar al inventaria
           cout << "Ingrese el numero de receta" << endl;
           cin >> numeroReceta; //utilizar while para validar el codigo,
           cout << "Ingrese el nombre del paciente" << endl;
           cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Permite agregar espacios para los apellidos, \n significa enter
                getline(cin, nombrePaciente);
          while (true) {
                cout << "Ingrese el codigo del producto" << endl;
           cin >> busquedaProducto;
           buscarProductos(busquedaProducto);
           cout << "Ingrese la indicacion" << endl;
cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Permite agregar espacios para los apellidos, \n significa enter
                getline(cin, indicacionProducto);
          if(asociacionValida(busquedaProducto, indicacionProducto)) {
            cout << "Asociacion encontrada ",'\n';
            break;
          } else {
          cout << "Indicacion no valida, por favor volver a ingresar.";
          }
          }
           cout << "Ingrese la cantidad" << endl;
           cin >> cantidadProducto; //Se limpia por el cambio de string and float
           registrarRecetas(numeroReceta, nombrePaciente, busquedaProducto, nombreProducto, indicacionProducto);
           break;
            }
        case 4:
            cout << "Reporte de catalogo de productos" << endl;
            break;
        case 5:
            cout << "Reporte impresion de receta" << endl;
            break;
        case 6:
                cout << "Presione cualquier tecla para salir del programa" << endl; // Mensaje de finalizacion
                break; // Permite salirse del bucle de cada opcion
            default:
            cout << "Opcion invalida, vuelva a intentarlo." << endl; //Mensaje de error al ingresar una opcion incorrecta en el menu
    }
} while (opcion != 6); //Repite el bucle hasta que el usuario ingrese la opcion salir (5)"
    return 0;
}
//Funciones del programa
void ingresarProductos (string codigoProducto, string nombreProducto, float cantidadProducto)
{
string nombreArchivo = "MEDICAMENTOS.txt";
ofstream archivo;
// Abrir el archivo de forma que no sobreesciba datos
archivo.open(nombreArchivo.c_str(), fstream::app);
//Modificamos el archivo
archivo << codigoProducto << endl;
archivo <<nombreProducto << endl;
archivo <<cantidadProducto << endl;
//Cerramos el archivo
archivo.close();
cout <<"Ejecutado de forma correcta";
}
//Funcion para buscar productos por medio de sus codigos
void buscarProductos(string busquedaProducto)
{
string nombreArchivo = "MEDICAMENTOS.txt";
ifstream archivo(nombreArchivo.c_str());
string linea, nombreProducto;
// Obtener linea;
bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea == busquedaProducto) {
            // Leer la siguiente línea
            if (getline(archivo, linea)) { //agarra el archivo y busca el siguiente salto linea y lo que encontro antes del siguiente salto de linea
                cout << "Producto encontrado: " << linea << endl;
                string linea = nombreProducto;
                encontrado = true;
            } else {
                cout << "No hay más información sobre el producto encontrado." << endl;
            }
            break;
        }
    }
    if (!encontrado) {
        cout << "Producto no encontrado." << endl;
    }
    archivo.close();
}
void agregarAsociaciones (string busquedaProducto, string asociacionProducto )
{
string nombreArchivo = "CLAVES.txt";
ofstream archivo;
// Abrir el archivo de forma que no sobreesciba datos
archivo.open(nombreArchivo.c_str(), fstream::app);
//Modificamos el archivo
archivo << busquedaProducto << endl;
archivo <<asociacionProducto << endl;
//Cerramos el archivo
archivo.close();
cout <<"Ejecutado de forma correcta";
}

bool asociacionValida (string codigoMedicamento, string propuesta)
{
string nombreArchivo = "CLAVES.txt";
ifstream archivo(nombreArchivo.c_str());
string linea, codigoProducto;
// Obtener linea;
bool encontrado = false;
    while (getline(archivo, linea)) {
        if (linea == codigoMedicamento) {
            // Leer la siguiente línea
            if (getline(archivo, linea)) { //agarra el archivo y busca el siguiente salto linea y lo que encontro antes del siguiente salto de linea
                if (propuesta.find(linea)!=std::string::npos){
                encontrado = true;
                break;
                } else {
                encontrado = false;
                break;
                }
            }
            break;
        }
    }

    archivo.close();
 return encontrado;
}
void registrarRecetas (string numeroReceta, string nombrePaciente, string busquedaProducto, string indicacionProducto, float cantidadProducto)
{
string nombreArchivo = "RECETA.txt";
ofstream archivo;
// Abrir el archivo de forma que no sobreesciba datos
archivo.open(nombreArchivo.c_str(), fstream::app);
//Modificamos el archivo
archivo <<numeroReceta << endl;
archivo <<nombrePaciente << endl;
archivo <<busquedaProducto << endl;
archivo <<indicacionProducto << endl;
archivo <<cantidadProducto << endl;
//Cerramos el archivo
archivo.close();
cout <<"Ejecutado de forma correcta";
}
void reporteProductos ()
{

}
void reporteRecetas ()
{
}
