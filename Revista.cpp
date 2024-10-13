#include "Revista.h"
#include <iostream>

Revista::Revista(string nombre,int isbn,string autor,int numEdicion,string mesPublic)
	:MaterialBibliografico(nombre,isbn,autor)
{
	this->numEdicion = numEdicion;
	this->mesPublic = mesPublic;
}
void Revista::MostrarInformacion() {

	MaterialBibliografico::MostrarInformacion();
	std::cout << numEdicion << mesPublic << std::endl;
}

Revista::~Revista() {

}
