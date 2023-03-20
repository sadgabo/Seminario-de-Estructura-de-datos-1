#include<iostream>
#include<string>


class Solicitud{
    private:
        std::string Nombre;
        std::string Carrera;
        int  MateriasAprobadas;
        float Promedio;


    public:
        Solicitud();
        Solicitud(std::string, std::string, int, float);

        void setNombre(std::string);
        void setCarrera(std::string);
        void setMaterias(int);
        void setPromedio(float);


        std::string getNombre();
        std::string getCarrera();
        int getMaterias();
        float getPromedio();

        bool operator == (const Solicitud&)const;

        friend std::ostream& operator<<(std::ostream& os, Solicitud& solicitud){
            os << "Nombre del alumno: " << solicitud.getNombre() << std::endl;
            os << "Nombre de la carrera: " << solicitud.getCarrera() << std::endl;
            os << "Materias aprobadas: " << solicitud.getMaterias() << std::endl;
            os << "Promedio general: " << solicitud.getPromedio() << std::endl;
            return os;
        };

        friend std::istream& operator>>(std::istream& is ,  Solicitud& solicitud ){
            std::cout << "Nombre del alumno: ";
            is.ignore();
            getline(is, solicitud.Nombre);
            std::cout << "Nombre de la carrera: ";
            is.ignore();
            getline(is, solicitud.Carrera);
            std::cout << "Materias aprobadas: ";
            is.ignore();
            is >> solicitud.MateriasAprobadas;
            std::cout << "Promedio general: ";
            is.ignore();
            is >> solicitud.Promedio;
            return is;
            
        };
        
        int BusquedaLineal(Solicitud&);

};