#include "Gestor.h"


Gestor::Gestor(){
    //Ejemplo para crear una estructura
    IStruct* estructuraPruuebaLista = crearEstructura(1);
    IStruct* estructuraPruuebaPila = crearEstructura(2);
    IStruct* estructuraPruuebaCola = crearEstructura(3);
}

IStruct* Gestor::crearEstructura(int tEstructura)
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
