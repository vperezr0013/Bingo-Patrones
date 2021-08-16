#include "carton.h"

Carton::Carton(int id): BaseEntity(id)
{
    this->ocupado = false;
}

int Carton::getNum() {
    return this->num;
}

void Carton::setNum(int num) {
    this->num = num;
}

bool Carton::isOcupado() {
    return this->ocupado;
}

void Carton::setOcupado(bool x) {
    this->ocupado = x;
}
