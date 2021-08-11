#include "PilaFactory.h"

IStruct* PilaFactory::creartEstructura()
{
    this->estructuraNueva = new Pila();
    return this->estructuraNueva;
}
