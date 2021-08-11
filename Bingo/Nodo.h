#pragma once
#ifndef NODO_H
#define NODO_H
#include "BaseEntity.h"
class Nodo
{
public:
	Nodo();
	Nodo(BaseEntity*, Nodo*);
	BaseEntity* getInfo();
	void setInfo(BaseEntity*);
	Nodo* getSig();
	void setSig(Nodo*);
private:
	BaseEntity* info;
	Nodo* siguiente;
};

#endif // !NODO_H

