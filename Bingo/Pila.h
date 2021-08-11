#pragma once
#include "Nodo.h"
#include "IStruct.h"
#ifndef PILA_H
#define PILA_H

class Pila : public IStruct
{
public:

	Pila();
	~Pila();
	void agregar(BaseEntity*);
	void eliminar();
	int getLenght();
	void destrurir();
	Nodo* getHead();
	bool isVoid();
};



#endif // !PILA_H
