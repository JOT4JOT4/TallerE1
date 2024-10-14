#include "Usuario.h"
#include <iostream>

Usuario::Usuario(string nombre,int id)
{
	this->nombre = nombre;
	this->id = id;

	for (int i = 0; i < 5; i++) {
		materialesPrestados[i] = nullptr;
	}
}
void Usuario::mostrarMaterialesPrestados() {
	bool tieneMateriales = false;

	for (int i = 0; i < 5; i++) {
		if (materialesPrestados[i] != nullptr) {
			std::cout << "nombre" << i + 1 << ": " << materialesPrestados[i]->getNombre() << std::endl;
			tieneMateriales = true;
		}
	}

	if (tieneMateriales == false) {
		std::cout << "El usuario no tiene materiales prestados" << std::endl;
	}
}

bool Usuario::prestarMaterial(MaterialBibliografico* material) {

	for(int i = 0; i < 5; i++) {
		if(materialesPrestados[i] == nullptr) {
			materialesPrestados[i] = material;
			return true;
		}

	}

	std::cout << "El material no se ha agregado dado que tiene todo el cupo de materiales ocupado" << std::endl;
	return false;
}

MaterialBibliografico* Usuario::devolverMaterial(string nombreB) {
	MaterialBibliografico* devolver = nullptr;

	for(int i = 0; i < 5; i++) {
		if(materialesPrestados[i] != nullptr && materialesPrestados[i]->getNombre() == nombreB) {

			devolver = materialesPrestados[i];
			materialesPrestados[i] = nullptr;
			return devolver;
		}

	}

	std::cout << "El material no se puede devolver el material dado que el usuario no lo tiene" << std::endl;
	return nullptr;
}

string Usuario::getNombre(){
	return nombre;
}
int Usuario::getId(){
	return id;
}

Usuario::~Usuario() {

}
