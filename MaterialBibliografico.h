#pragma once
#include <iostream>
#include <string>
using namespace std;

class MaterialBibliografico
{
private:

	string nombre;
	int isbn;
	string autor;
	bool prestado;
public:
	MaterialBibliografico(string nombre,int isbn,string autor);
	virtual void MostrarInformacion();
	string getNombre();
	~MaterialBibliografico();

};


