#pragma once
#include <iostream>
#include <string>

using namespace std;

class MaterialBibliografico
{
private:
    /* data */
    string nombre;
    int isbn;
    string autor;
    bool prestado;
public:
    MaterialBibliografico(/* args */);
        virtual void MostrarInformacion();
    ~MaterialBibliografico();
    
};

MaterialBibliografico::MaterialBibliografico(/* args */)
{
}

MaterialBibliografico::~MaterialBibliografico()
{
}

void MaterialBibliografico::MostrarInformacion()
{
}


