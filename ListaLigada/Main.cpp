#include <iostream>
#include <string>
#include "ListaLigada.cpp"
#include "SocioClub.cpp"

void registrarSocio(LSLSE<SocioClub>&);
void bajaSocio(LSLSE<SocioClub>&);
void generarReporte(LSLSE<SocioClub>&);
void buscarSocio(LSLSE<SocioClub>&);
int calcularTotal(const LSLSE<SocioClub>&);

int main()
{
    int totatl;
    LSLSE<SocioClub> lista_socios;

    int opcion_menu = 0;
    do {
        std::cout << "------------------- MENU --------------------" << std::endl;
        std::cout << "[1] - Registrar nuevo socio" << std::endl;
        std::cout << "[2] - Dar de baja un socio" << std::endl;
        std::cout << "[3] - Generar reporte de socios" << std::endl;
        std::cout << "[4] - Buscar socio por nombre o domicilio" << std::endl;
        std::cout << "[5] - Calcular total de socios registrados" << std::endl;
        std::cout << "[6] - Salir" << std::endl;
        std::cout << "--------------------------------------------" << std::endl;
        std::cin >> opcion_menu;
        switch(opcion_menu) {
            case 1:
                registrarSocio(lista_socios);
                break;
            case 2:
                bajaSocio(lista_socios);
                break;
            case 3:
                generarReporte(lista_socios);
                break;
            case 4:
                buscarSocio(lista_socios);
                break;
            case 5:
                totatl = calcularTotal(lista_socios);
                std::cout<<"Total se socios: "<<totatl<<std::endl;
                break;
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opcion invalida" << std::endl;
        }
    } while(opcion_menu != 6);

    return 0;
}


void registrarSocio(LSLSE<SocioClub>& lista)
{
    int num_socio;
    std::string nombre, domicilio;
    int anio_ingreso;

    std::cin.ignore();
    std::cout << "Ingrese el numero de socio: ";
    std::cin >> num_socio;

    if(lista.primero() != nullptr && lista.primero()->getData().getNumeroSocio() == num_socio) {
        std::cout << "Ya existe un socio registrado con ese numero." << std::endl;
        return;
    }

    std::cout << "Ingrese el nombre del socio: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);

    std::cout << "Ingrese el domicilio del socio: ";
    std::getline(std::cin, domicilio);

    std::cout << "Ingrese el anio de ingreso del socio: ";
    std::cin >> anio_ingreso;

    SocioClub socio(num_socio, nombre, domicilio, anio_ingreso);
    lista.insertar(socio);

    std::cout << "Socio registrado exitosamente." << std::endl;
}


void bajaSocio(LSLSE<SocioClub>& lista) {
    int numSocio;
    std::cin.ignore();
    std::cout << "Ingrese el numero de socio a dar de baja: ";
    std::cin >> numSocio;
    node<SocioClub>* pos = lista.primero();
    while(pos != nullptr && pos->getData().getNumeroSocio() != numSocio) {
        pos = pos->getSiguiente();
    }
    if(pos != nullptr) {
        lista.eliminar(pos);
        std::cout << "Socio con numero " << numSocio << " dado de baja exitosamente.\n";
    } else {
        std::cout << "No se encontro un socio con el numero " << numSocio << ".\n";
    }
}

void generarReporte(LSLSE<SocioClub>& lista) {
    std::cin.ignore();
    std::cout << "Reporte de Socios:\n";
    std::cout << "-------------------\n";
    if (lista.vacia()) {
        std::cout << "No hay socios registrados\n";
        return;
    }
    node<SocioClub>* aux = lista.primero();
    while (aux != nullptr) {
        std::cout << "Numero de socio: " << aux->getData().getNumeroSocio() << std::endl;
        std::cout << "Nombre: " << aux->getData().getNombreSocio() << std::endl;
        std::cout << "Domicilio: " << aux->getData().getDomicilio() << std::endl;
        std::cout << "Anio de ingreso: " << aux->getData().getAnioIngreso() << std::endl;
        std::cout << "-------------------\n";
        aux = aux->getSiguiente();
    }
}

void buscarSocio(LSLSE<SocioClub>& lista){
    std::cin.ignore();
    std::string busqueda;
    std::cout << "Ingrese el nombre o domicilio del socio a buscar: ";
    std::getline(std::cin, busqueda);
    
    node<SocioClub>* aux = lista.primero();
    int contador = 0;
    
    while(aux != nullptr){
        if(aux->getData().getNombreSocio() == busqueda || aux->getData().getDomicilio() == busqueda){
            std::cout << "Socio encontrado:\n";
            std::cout << aux->getData() << std::endl;
            contador++;
        }
        aux = aux->getSiguiente();
    }
    
    if(contador == 0){
        std::cout << "No se encontro ningun socio con el nombre o domicilio ingresado.\n";
    }
}


int calcularTotal(const LSLSE<SocioClub>& lista_socios) {
    int contador = 0;
    node<SocioClub>* actual = lista_socios.primero();
    while (actual != nullptr) {
        contador++;
        actual = actual->getSiguiente();
    }
    return contador;
}
