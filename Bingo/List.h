#pragma once
#include "BaseEntity.h"
#include "Nodo.h"
#include "IStruct.h"
#ifndef LIST_H
#define LIST_H

class List : public IStruct
{
public:
	List();
	~List();
	void agregar(BaseEntity*);
	void eliminarByIndice(int);
	int getLenght();
	void destrurir();
	Nodo* getHead();
	bool isVoid();
	void updateByReferencia(int);
};

#endif // !LIST_H


