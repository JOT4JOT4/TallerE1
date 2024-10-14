#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class Usuario
{
private:
    
    string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];
    
public:

    Usuario(string nombre,int id);
    bool prestarMaterial(MaterialBibliografico* material);
    MaterialBibliografico* devolverMaterial(string nombreB);
    void mostrarMaterialesPrestados();
    string getNombre();
    int getId();
    ~Usuario();
};
