#include "Nodo.h"

Nodo::Nodo()
{
	this->info = nullptr;
	this->siguiente = nullptr;
}

Nodo::Nodo(BaseEntity* infoFampo, Nodo* newNodo) : info(infoFampo), siguiente(newNodo)
{
}

BaseEntity* Nodo::getInfo()
{
	return this->info;
}

void Nodo::setInfo(BaseEntity* info)
{
	this->info = info;
}

Nodo* Nodo::getSig()
{
	return this->siguiente;
}

void Nodo::setSig(Nodo* siguiente)
{
	this->siguiente = siguiente;
}
