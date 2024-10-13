#include "Libro.h"
#include <iostream>

Libro::Libro(string nombre,int isbn,string autor,string fechaP,string resumen)
	:MaterialBibliografico(nombre,isbn,autor)
{
	this->fechaP = fechaP;
	this->resumen= resumen;
}

void  Libro::MostrarInformacion() {

	MaterialBibliografico::MostrarInformacion();
	std::cout << fechaP<<","<<resumen << std::endl;

}

Libro::~Libro() {

}
