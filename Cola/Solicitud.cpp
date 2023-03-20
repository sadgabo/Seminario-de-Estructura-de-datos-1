#include"Solicitud.h"



Solicitud::Solicitud(){}


Solicitud::Solicitud(std::string name , std::string carrer, int mat, float prom){
    Nombre = name;
    Carrera = carrer;
    MateriasAprobadas = mat;
    Promedio = prom;
}


void Solicitud::setNombre(std::string name){
    Nombre = name;
}

void Solicitud::setCarrera(std::string carr){
    Carrera = carr;
}

void Solicitud::setMaterias(int mat){
    MateriasAprobadas  = mat;
}

void Solicitud::setPromedio(float prom){
    Promedio = prom;
}

std::string Solicitud::getNombre(){return Nombre;}

std::string Solicitud::getCarrera(){return Carrera;}

int Solicitud::getMaterias(){return MateriasAprobadas;}

float Solicitud::getPromedio(){return Promedio;}



bool Solicitud::operator==(const Solicitud& dat)const{
    return Nombre == dat.Nombre;
    return Carrera == dat.Carrera;
    return MateriasAprobadas == dat.MateriasAprobadas;
    return Promedio == dat.Promedio;
}