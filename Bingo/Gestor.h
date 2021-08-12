#pragma once
#include <string>
#include "List.h"
#include "Pila.h"
#include "IStruct.h"
#include "IAbstractFactoryStruct.h"
#include "ListFactory.h"
#include "ColaFactory.h"
#include "PilaFactory.h"
#include "BaseEntity.h"
#ifndef GESTOR_H
#define GESTOR_H

using namespace std;

class Gestor
{
private:
    IStruct* bolitasJugadas;
	IStruct* crearEstructura(int);
    void agregarBolitaJugadaaLista(BaseEntity* bolitaJugada);
    bool validarBolitasJugadas(BaseEntity* bolitaJugada);
public:
	Gestor();
    ~Gestor();

};
#endif // !GESTOR_H



