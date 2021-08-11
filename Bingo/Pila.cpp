#include "Pila.h"
#include <iostream>

Pila::Pila() {
	this->head = nullptr;
	this->lenght = 0;
}

Pila::~Pila()
{
}

void Pila::agregar(BaseEntity* info) {
	Nodo* newNodo = new Nodo(info, nullptr);
	if (isVoid())
	{
		this->head = newNodo;
		this->lenght++;
	}
	else {

		newNodo->setSig(head);
		this->head = newNodo;
		this->lenght++;

	}
}

void Pila::eliminar() {
	if (!isVoid()) {
		head = head->getSig();
		this->lenght--;
	}
	else {
		cout << "Stack Underflow" << endl;
	}
}

int Pila::getLenght() {
	return this->lenght;
}

void Pila::destrurir() {
	this->~Pila();
}

Nodo* Pila::getHead() {
	return this->head;
}

bool Pila::isVoid() {
	return this->lenght == 0;
}