#include <iostream>
#include <fstream>
#include "Libro.cpp"
#include "Revista.cpp"
#include "Usuario.cpp"
#include "MaterialBibliografico.cpp"

using namespace std;

void dividirLinea(const string& linea, string& tipo, string& nombre, string& isbn, 
                  string& nombreAutor, string& fechaP, string& resumen, 
                  string& numE, string& mes) {
    size_t pos = 0;
    size_t next_pos = 0;

    // Obtener tipo (Libro o Revista)
    pos = linea.find(',', next_pos);
    tipo = linea.substr(next_pos, pos - next_pos);
    next_pos = pos + 1;

    // Dependiendo del tipo, obtener los otros valores
    if (tipo == "Libro") {
        pos = linea.find(',', next_pos);
        nombre = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        pos = linea.find(',', next_pos);
        isbn = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        pos = linea.find(',', next_pos);
        nombreAutor = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        pos = linea.find(',', next_pos);
        fechaP = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        resumen = linea.substr(next_pos); // El resto es el resumen
    } 
    else if (tipo == "Revista") {
        pos = linea.find(',', next_pos);
        nombre = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        pos = linea.find(',', next_pos);
        isbn = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        pos = linea.find(',', next_pos);
        numE = linea.substr(next_pos, pos - next_pos);
        next_pos = pos + 1;

        mes = linea.substr(next_pos); // El resto es el mes
    }
}

void leerDatos(const string& nombreArchivo,MaterialBibliografico* biblioteca[],int cont) {

    ifstream archivo(nombreArchivo);
    string linea;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            string tipo, nombre, isbn, nombreAutor, fechaP, resumen, numE, mes;
            dividirLinea(linea, tipo, nombre, isbn, nombreAutor, fechaP, resumen, numE, mes);

            // Procesar según el tipo
            if (tipo == "Libro") {
                
                biblioteca[cont++] = new Libro(nombre,stoi(isbn),nombreAutor,fechaP,resumen);

                
            } else if (tipo == "Revista") {
                
                biblioteca[cont++]  = new Revista(nombre,stoi(isbn),nombreAutor,stoi(numE),mes);
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void MostrarMaterial(MaterialBibliografico* biblioteca[],int cont){
    
    for(int i = 0; i < cont;i++){
        biblioteca[i]->MostrarInformacion();
    }

}


void IngresarUsuario(Usuario* arrayUsuario[], int& contUsuario, int N) {

    if (contUsuario == N) {
        cout << "-CAPACIDAD MAXIMA ALCANZADA-" << endl;
        return;
    }
    string nombre;
    int id;
    cout << "Ingrese el nombre del usuario: ";
    cin >> nombre;
    cout << endl << "Ingrese el id: ";
    cin >> id;
    arrayUsuario[contUsuario++] = new Usuario(nombre, id);
    cout << "Agregado correctamente :)" << endl;
}

void BuscarUsuario(Usuario* arrayUsuario[], int contUsuario) {

    int id;
    cout << "Ingrese el id del usuario a buscar: ";
    cin >> id;
    bool encontrado = false;
    for(int i=0; i<contUsuario; i++) {
        if(arrayUsuario[i]->getId() == id) {
            encontrado = true;
            cout << "Nombre Usuario: " << arrayUsuario[i]->getNombre() << endl;
            cout << "Materiales Prestados: " << endl;
            arrayUsuario[i]->mostrarMaterialesPrestados();
        }
    }
    if(!encontrado) {
        cout << "-USUARIO NO ENCONTRADO-" << endl;
    }
}

void EliminarUsuario(Usuario* arrayUsuario[], int& contUsuario) {

    int id;
    cout << "Ingrese el id del usuario a eliminar: ";
    cin >> id;

    int i;
    for (i = 0; i < contUsuario; i++)
        if (arrayUsuario[i]->getId() == id)
        {
            break;
        }
    if (i == contUsuario) {
        cout << "-USUARIO NO ENCONTRADO-" << endl;
        return;
    }

    int j;
    for (j= i; j <(contUsuario - 1); j++){
        arrayUsuario[j] = arrayUsuario[j + 1];
    }
    contUsuario--;
}

void GestionUsuarios(Usuario* arrayUsuario[], int& contUsuario, int N) {

    int opc = 0;
    cout << "--GESTION DE USUARIOS--" << endl;
    cout << "1) Ingresar un Usuario" << endl;
    cout << "2) Buscar un Usuario" << endl;
    cout << "3) Eliminar un Usuario" << endl;
    cout << "Ingrese un opcion: ";
    cin >> opc;
    cout << endl;

    switch (opc)
    {
    case 1:
        IngresarUsuario(arrayUsuario, contUsuario, N);
        break;
    case 2:
        BuscarUsuario(arrayUsuario, contUsuario);
        break;
    case 3:
        EliminarUsuario(arrayUsuario, contUsuario);
        break;

    default:
        cout << "OPCION INVALIDA" << endl;
        break;
    }
}

void BusquedaMaterialPorAutor(MaterialBibliografico* array[], int contMaterial) {
    string autor = "";
    cout << "Ingrese al autor: ";
    cin >> autor;
    cout << endl << "-------------" << endl;
    bool flag = false;
    for(int i=0; i<contMaterial; i++) {
        if(array[i]->getAutor() == autor){
            array[i]->MostrarInformacion();
            flag = true;

        }
    }
    if(!flag){
        cout << "BUSQUEDA SIN RESULTADOS" << endl;
    }
    cout << "--------------" << endl;
}

void BusquedaMaterialPorTitulo(MaterialBibliografico* array[], int contMaterial) {
    string titulo = "";
    cout << "Ingrese el titulo: ";
    cin >> titulo;
    bool flag = false;
    cout << endl << "-------------" << endl;
    for(int i=0; i<contMaterial; i++) {
        if(array[i]->getNombre() == titulo){
            array[i]->MostrarInformacion();
            flag = true;

        }
    }
    if(!flag){
        cout << "BUSQUEDA SIN RESULTADOS" << endl;
    }
    cout << "--------------" << endl;
}
void BusquedaMaterialPorAutorTitulo(MaterialBibliografico* array[], int contMaterial) {
    string titulo = "";
    string autor = "";
    cout << "Ingrese el titulo: ";
    cin >> titulo;
    cout << endl << "Ingrese el autor: ";
    cin >> autor;
    cout << endl << "-------------" << endl;
    bool flag = false;
    for(int i=0; i<contMaterial; i++) {
        if(array[i]->getNombre() == titulo && array[i]->getAutor() == autor){
            array[i]->MostrarInformacion();
            flag = true;
        }
    }
    if(!flag){
        cout << "BUSQUEDA SIN RESULTADOS" << endl;
    }
    cout << "--------------" << endl;
}
void BuscarMaterial(MaterialBibliografico* array[], int  conMaterial) {

    int opc = 0;
    cout << "Busqueda de materiales bibliograficos; Escoga una opcion de busqueda" << endl;
    cout << "1) Autor" << endl;
    cout << "2) Titulo" << endl;
    cout << "3) Autor y Titulo" << endl;
    cout << "--Seleccione una opcion: ";
    cin  >> opc;

    switch(opc){
        case 1:
            BusquedaMaterialPorAutor(array, conMaterial);
            break;
        case 2:
            BusquedaMaterialPorTitulo(array, conMaterial);
            break;
        case 3:
            BusquedaMaterialPorAutorTitulo(array, conMaterial);
            break;
        default:
            cout << "Opcion invalida ..." << endl;
            break;
    }
}
//---------------------------------------------------------------------------------------------//




Usuario* DevolverUsuario(Usuario* arrayUsuario[], int contUsuario) {

    int id;
    cout << "Ingrese el id del usuario a buscar: ";
    cin >> id;
    bool encontrado = false;
    for(int i=0; i<contUsuario; i++) {
        if(arrayUsuario[i]->getId() == id) {
            encontrado = true;
            return arrayUsuario[i];
            cout << "-USUARIO ENCONTRADO-" << endl;
        }
    }
    if(!encontrado) {
        cout << "-USUARIO NO ENCONTRADO-" << endl;
    }
    return nullptr;
}


void cambiarEstadoMaterial(MaterialBibliografico* array[], Usuario* usuario,int contMaterial, bool pedirDevolver) {
    string titulo = "";
    cout << "Ingrese el titulo: ";
    cin >> titulo;
    bool flag = false;
    cout << endl << "-------------" << endl;
    for(int i=0; i<contMaterial; i++) {
        if(array[i]->getNombre() == titulo){
            array[i]->MostrarInformacion();
            flag = true;
            //Pedir Prestado Material
            if(pedirDevolver == true)
            {
                if(array[i]->getPrestado() == false)
            {
                cout << "Prestamo Exitoso" << endl;
                array[i] ->cambiarEstado();
                usuario->prestarMaterial(array[i]);
            }
            else{ cout << "Material no se Encuentra Disponible" << endl;}
            }
            //Devolver Material Prestado
            else{
                if(array[i]->getPrestado() == true)
             {
                cout << "Devolución Exitosa" << endl;
                array[i] ->cambiarEstado();
                usuario -> devolverMaterial(array[i] -> getNombre());
            }
            else{ cout << "Material ya se encuentra en biblioteca" << endl;}
}
            
        }
    }
    if(!flag){
        cout << "BUSQUEDA SIN RESULTADOS" << endl;
    }
    cout << "--------------" << endl;
}




int PedirODevolverMaterial(MaterialBibliografico* arrayBiblioteca[],int conMaterial,Usuario* arrayUsuarios[], int contUsuario) {

    Usuario* usuario = DevolverUsuario(arrayUsuarios, contUsuario);

    if(usuario == nullptr)
    {
        cout << "No se puede, usuario no existente" << endl;
        return -1;
    }

    int opcion2;
    
    cout << "Que desea hacer." << endl;
    cout << "1) Pedir Prestado" << " 2) Devolver Prestado" << endl;

    cin>> opcion2;

    switch(opcion2){
        case 1:
        //Pedir Prestado
            cambiarEstadoMaterial(arrayBiblioteca,usuario,conMaterial,true);
            break;
        case 2:
        //Devolver Prestado
            cambiarEstadoMaterial(arrayBiblioteca,usuario,conMaterial,false);
            break;
        default:
            cout << "Opcion invalida ..." << endl;
            break;
    }
    return 0;
}

//------------------------------------------------------------------------------------------//
int AgregarMaterial(MaterialBibliografico* biblioteca[],int cont,int N) {

    if(cont >= N)
    {
        cout << "SE EXCEDIO EL ESPACIO EN BIBLIOTECA" << endl;
        return -1;
    }

    int opcion;

    cout << "Ingrese el material que desee ingresar." << endl;
    cout << "1) Libro" << " 2) Revista" << endl;

    cin>> opcion;

    while(opcion > 2 || opcion < 1) {

        cout<<"opcion invalida"<<endl;
        cout<<"ingrese una opcion correcta"<<endl;
        cin >> opcion;



    }

        string nombre;
        int isbn;
        string nombreA;
        string fechaP = "";
        string resumen = "";
        int numE;
        string mes = "";

        cout<<"Ingrese el nombre del libro"<<endl;
        cin >> nombre;
        cout<<"Ingrese el isbn del libro"<<endl;
        cin >> isbn;
        cout<<"Ingrese el nombre del autor del libro"<<endl;
        cin >> nombreA;




    switch (opcion)
    {
    case 1:


        cout<<"Ingrese la fecha de publicacion del libro"<<endl;
        cin >> fechaP;
        cout<<"Ingrese un resumen del libro"<<endl;
        getline(cin,resumen);
        getline(cin,resumen);
        //Libro libro = new MaterialBibliografico(nombre,isbn,autor,fechaP,resumen)
        biblioteca[cont++] = new Libro(nombre,isbn,nombreA,fechaP,resumen);

        break;

    case 2:

        cout<<"Ingrese el numero de la edicion"<<endl;
        cin >> numE;
        cout<<"Ingrese el mes de publicacion"<<endl;
        cin >> mes;
        biblioteca[cont++] = new Revista(nombre, isbn, nombreA, numE, mes);
        break;

    default:
        break;
    }

return 0;
}





int main()
{
    string nombreArchivo = "Biblioteca.txt";
    int tamano = 100;
    MaterialBibliografico* biblioteca[tamano] = {nullptr};
    int contMaterial = 0;
    Usuario* usuarios[tamano] = {nullptr};
    int contUs = 0;

    leerDatos(nombreArchivo,biblioteca,contMaterial);

    int opcion = 0;
    while(opcion != 6) {
        cout<<"Bienvenido, "<<endl;
        cout<<"Las opciones son: "<<endl;

        cout << "1) Agregar Material a la Biblioteca" << endl;
        cout << "2) Mostrar Informacion de los Materiales" << endl;
        cout << "3) Buscar Material" << endl;
        cout << "4) Prestar y Devolver Material" << endl;
        cout << "5) Gestion de Usuarios" << endl;
        cout << "6) SALIR" << endl;
        cin >> opcion;

        while(opcion > 6 || opcion < 0){
            cout<<"opcion invalida"<<endl;
            cout<<"ingrese una opcion correcta"<<endl;
            cin >> opcion;
        }
        cout << "-------------------------" << endl;
        switch (opcion)
        {
            case 1:
                AgregarMaterial(biblioteca,contMaterial,tamano);
                break;
            case 2:
                MostrarMaterial(biblioteca,contMaterial);
                break;
            case 3: 
                BuscarMaterial(biblioteca, contMaterial);
                break;
            case 4:
                PedirODevolverMaterial(biblioteca, contMaterial,usuarios, contUs);
                break;
            case 5:
                GestionUsuarios(usuarios, contUs, tamano);
                break;
            case 6:
                cout << "SE HA SALIDO DE LA SESION..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        cout << "-------------------------" << endl;
        cout << "-----------------------" << endl;
    }

}