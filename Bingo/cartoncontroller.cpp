#include "cartoncontroller.h"
#include <algorithm>
#include <chrono>
#include <random>
#include "carton.h"
#include <vector>
#include <iostream>

CartonController::CartonController()
{
    this->generarCartones();
}

void CartonController::generarCartones() {
    this->carton1 = this->crearEstructura(1);
    this->carton2 = this->crearEstructura(1);
    populate(this->carton1);
    populate(this->carton2);
}


IStruct* CartonController::crearEstructura(int tEstructura)
{
    IAbstractFactoryStruct* factory = nullptr;
    switch (tEstructura)
    {
    case 1:
        factory = new ListFactory();
        break;
    case 2:
        factory = new PilaFactory();
        break;
    case 3:
        factory = new ColaFactory();
        break;
    default:
        break;
    }
    return factory->creartEstructura();
}

void CartonController::populate(IStruct* list) {
    vector<int> vector;

    for(int i = 0; i  < 100; i++) {
        vector.push_back(i);
    }

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(vector.begin(), vector.end(), g);

    for(int i = 0; i  < 100; i++) {
        Carton *c = new Carton(1);
        c->setNum(vector.at(i));
        list->agregar(c);
    }
}

IStruct* CartonController::getCarton1() {
    return this->carton1;
}

IStruct* CartonController::getCarton2() {
    return this->carton2;
}
