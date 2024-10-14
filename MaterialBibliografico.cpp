#include <iostream>
#include "MaterialBibliografico.h"

using namespace std;

MaterialBibliografico::MaterialBibliografico(string nombre, int isbn,string autor) {

	this->nombre = nombre;
	this->isbn =isbn;
	this->autor=autor;
	this->prestado=false;
}
void MaterialBibliografico::MostrarInformacion() {

	std::cout << nombre<<","<<isbn<<","<<autor<<","<<(prestado ? "prestado:si" : "prestado:no") << std::endl;

}
string MaterialBibliografico::getNombre(){
    return nombre;
}
string MaterialBibliografico::getAutor(){
    return autor;
}
bool MaterialBibliografico::getPrestado(){
    return prestado;
}
void MaterialBibliografico::cambiarEstado(){
	if(this->prestado == false){
		this->prestado = true;
	}else if(this->prestado == true){
		this->prestado = false;
	}
}

MaterialBibliografico::~MaterialBibliografico() {
	
}
