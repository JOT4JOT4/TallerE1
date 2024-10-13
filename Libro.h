#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class Libro: public MaterialBibliografico {

private:

	string fechaP;
	string resumen;

public:

	Libro(string nombre,int isbn,string autor,string fechaP,string resumen);
	void MostrarInformacion() override;

	~Libro();

};
