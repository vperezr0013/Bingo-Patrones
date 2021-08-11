#include "List.h"

List::List() {
	this->head = nullptr;
	this->lenght = 0;
}

List::~List()
{
}

void List::agregar(BaseEntity* info) {
	Nodo* newNodo = new Nodo(info, nullptr);
	if (isVoid()) {
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

void List::eliminarByIndice(int index) {
	if (index >= 0 && index < lenght) {
		if (index == 0) {
			this->head = this->head->getSig();
		}
		else {
			Nodo* aux = this->head;
			for (int i = 0; i < index; i++) {
				aux = aux->getSig();
			}

			Nodo* nextNodo = aux->getSig();
			aux->setSig(nextNodo->getSig());
		}
		lenght--;
	}
}

int List::getLenght() {
	return this->lenght;
}

void List::destrurir() {
	this->~List();
}

Nodo* List::getHead() {
	return this->head;
}

bool List::isVoid() {
	return this->lenght == 0;
}

void List::updateByReferencia(int)
{
}
