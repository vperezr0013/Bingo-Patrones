#pragma once
#include "Nodo.h"
#ifndef ISTRUCT_H
#define ISTRUCT_H
using namespace std;
class IStruct
{
protected:
	Nodo* head;
	int lenght;
public:
	virtual void agregar(BaseEntity*);
	virtual void eliminar();
	virtual int getLenght();
	virtual void destrurir();
	virtual Nodo* getHead();
	virtual bool isVoid();
};

#endif // !ISTRUCT_H


