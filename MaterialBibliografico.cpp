#include <iostream>
#include "MaterialBibliografico.hpp"

using namespace std;

MaterialBibliografico::MaterialBibliografico(string nombre, int isbn,string autor) {

	this->nombre = nombre;
	this->isbn =isbn;
	this->autor=autor;
	this->prestado=false;
}
void MaterialBibliografico::MostrarInformacion() {

	std::cout << nombre<<","<<isbn<<","<<autor<<","<<prestado<< std::endl;

}
string MaterialBibliografico:: getNombre(){
    return nombre;
}

MaterialBibliografico::~MaterialBibliografico() {
	
}
