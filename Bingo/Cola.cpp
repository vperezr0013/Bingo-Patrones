#include "Cola.h"
#include <iostream>

Cola::Cola() {
	this->head = nullptr;
	this->lenght = 0;
}

Cola::~Cola()
{
}

void Cola::agregar(BaseEntity* info) {
	Nodo* newNodo = new Nodo(info, nullptr);
	if (isVoid())
	{
		this->head = newNodo;
		this->lenght++;
	}
	else {

		Nodo* aux = this->head;
		while (aux->getSig() != nullptr)
		{
			aux = aux->getSig();
		}
		aux->setSig(newNodo);
		this->lenght++;
	}
}

void Cola::eliminar() {
	if (!isVoid()) {
		head = head->getSig();
		this->lenght--;
	}
	else {
		cout << "Stack Underflow" << endl;
	}
}

int Cola::getLenght() {
	return this->lenght;
}

void Cola::destrurir() {
	this->~Cola();
}

Nodo* Cola::getHead() {
	return this->head;
}

bool Cola::isVoid() {
	return this->lenght == 0;
}