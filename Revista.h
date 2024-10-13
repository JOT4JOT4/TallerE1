#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class Revista: public MaterialBibliografico {

private:

	int numEdicion;
	string mesPublic;

public:

	Revista(string nombre,int isbn,string autor,int numEdicion,string mesPublic);
	void MostrarInformacion() override;

	~Revista();
};
