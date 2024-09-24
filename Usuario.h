#pragma once
#include <iostream>
#include <string>
#include "MaterialBibliografico.h"

using namespace std;

class Usuario
{
private:
    /* data */
    string nombre;
    int id;
    MaterialBibliografico* materialesPrestados[5];
public:
    Usuario(/* args */);
    void prestarMaterial();
    void devolverMaterial();
    void mostrarMaterialesPrestados();
    ~Usuario();
};
