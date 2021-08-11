#include "ListFactory.h"

IStruct* ListFactory::creartEstructura()
{
    this->estructuraNueva = new List();
    return this->estructuraNueva;
}
