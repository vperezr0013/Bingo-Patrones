#pragma once
#ifndef COLAFACTORY_H
#define COLAFACTORY_H
#include "IAbstractFactoryStruct.h"
class ColaFactory :
    public IAbstractFactoryStruct
{
public:
    virtual IStruct* creartEstructura();
};

#endif // !FACTORYCOLA_H