#include <iostream>
#include <string>

class SocioClub {
private:
    int numeroSocio;
    std::string nombreSocio;
    std::string domicilio;
    int anioIngreso;

public:
    SocioClub(){
        numeroSocio = 0;
        nombreSocio = " ";
        domicilio = " ";
        anioIngreso = 0;
    }

    SocioClub(int num, std::string nombre, std::string dom, int anio){
            numeroSocio = num;
            nombreSocio = nombre;
            domicilio = dom;
            anioIngreso = anio;
    }


    ~SocioClub() {}


    int getNumeroSocio() const { return numeroSocio; }
    std::string getNombreSocio() const { return nombreSocio; }
    std::string getDomicilio() const { return domicilio; }
    int getAnioIngreso() const { return anioIngreso; }


    void setNumeroSocio(int num) { numeroSocio = num; }
    void setNombreSocio(std::string nombre) { nombreSocio = nombre; }
    void setDomicilio(std::string dom) { domicilio = dom; }
    void setAnioIngreso(int anio) { anioIngreso = anio; }

 
    bool operator<(const SocioClub& otro) const {
        return numeroSocio < otro.numeroSocio;
    }

    bool operator==(const SocioClub& otro) const {
        return numeroSocio == otro.numeroSocio;
    }


    friend std::ostream& operator<<(std::ostream& os, const SocioClub& sc) {
        os << "Numero de Socio: " << sc.numeroSocio << std::endl;
        os << "Nombre de Socio: " << sc.nombreSocio << std::endl;
        os << "Domicilio: " << sc.domicilio << std::endl;
        os << "Anio de Ingreso: " << sc.anioIngreso << std::endl;
        return os;
    }


    void imprimir() const {
        std::cout << "Numero de Socio: " << numeroSocio << " | ";
        std::cout << "Nombre de Socio: " << nombreSocio << " | ";
        std::cout << "Domicilio: " << domicilio << " | ";
        std::cout << "Anio de Ingreso: " << anioIngreso << std::endl;
    }
};
