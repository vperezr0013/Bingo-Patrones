#pragma once
#include "BaseEntity.h"
#include "Nodo.h"
#include"IStruct.h"
#ifndef COLA_H
#define COLA_H
class Cola: public IStruct
{
public:
	Cola();
	~Cola();
	void agregar(BaseEntity*);
	void eliminar();
	int getLenght();
	void destrurir();
	Nodo* getHead();
	bool isVoid();
};



#endif // !COLA_H

