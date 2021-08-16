#ifndef CARTONCONTROLLER_H
#define CARTONCONTROLLER_H

#include "List.h"
#include "Pila.h"
#include "IStruct.h"
#include "IAbstractFactoryStruct.h"
#include "ListFactory.h"
#include "ColaFactory.h"
#include "PilaFactory.h"
#include "BaseEntity.h"
#include <algorithm>
#include "carton.h"
#include <vector>
#include <iostream>

class CartonController
{
public:
    CartonController();
    IStruct* getCarton1();
    IStruct* getCarton2();

private:
    IStruct* carton1;
    IStruct* carton2;
    IStruct* crearEstructura(int);
    void generarCartones();
    void populate(IStruct* list);
    void shuffle_array(vector<int> vector);
};

#endif // CARTONCONTROLLER_H
