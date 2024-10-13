#include <iostream>
#include "Libro.h"
#include "Revista.h"
#include "Usuario.h"
#include "MaterialBibliografico.h"

using namespace std;

int AgregarMaterial() {

	int opcion;

	cout << "Ingrese el material que desee ingresar." << endl;
	cout << "1) Libro" << " 2) Revista" << endl;

	cin>> opcion;

	while(opcion > 2 || opcion < 1) {

		cout<<"opcion invalida"<<endl;
		cout<<"ingrese una opcion correcta"<<endl;
		cin >> opcion;

		
		
	}

		string nombre;
		int isbn;
		string nombreA;
		string fechaP = "";
		string resumen = "";
		int numE;
		string mes = "";
		Libro libro();
		Revista revist();

		cout<<"Ingrese el nombre del libro"<<endl;
		cin >> nombre;
		cout<<"Ingrese el isbn del libro"<<endl;
		cin >> isbn;
		cout<<"Ingrese el nombre del autor del libro"<<endl;
		cin >> nombreA;

		


	switch (opcion)
	{
	case 1:
		

		cout<<"Ingrese la fecha de publicacion del libro"<<endl;
		cin >> fechaP;
		cout<<"Ingrese un resumen del libro"<<endl;
		cin >> resumen;
		//Libro libro = new MaterialBibliografico(nombre,isbn,autor,fechaP,resumen)
		Libro* libro = new Libro(nombre,isbn,nombreA,fechaP,resumen);

		break;

	case 2:

		cout<<"Ingrese el numero de la edicion"<<endl;
		cin >> numE;
		cout<<"Ingrese el mes de publicacion"<<endl;
		cin >> mes;

		revist(nombre,isbn,nombreA,numE,mes);
	
	default:
		break;
	}

return 0;	
}

int main()
{

cout<<"Bienvenido, "<<endl;
cout<<"Las opciones son: "<<endl;

cout << "1) Agregar Material a la Biblioteca" << endl;
cout << "2) Mostrar Información de los Materiales" << endl;
cout << "3) Buscar Material" << endl;
cout << "4) Prestar y Devolver Material" << endl;
cout << "5) Gestión de Usuarios" << endl;

int opcion = 0;
cin >> opcion;

while(opcion > 5 || opcion < 0){

	cout<<"opcion invalida"<<endl;
	cout<<"ingrese una opcion correcta"<<endl;
	cin >> opcion;

	}
switch (opcion)
{
case 1:
	AgregarMaterial();
	break;

default:
	break;
}

}

