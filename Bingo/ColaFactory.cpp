#include "ColaFactory.h"

IStruct* ColaFactory::creartEstructura()
{
    estructuraNueva = new Cola();
    return estructuraNueva;
}
