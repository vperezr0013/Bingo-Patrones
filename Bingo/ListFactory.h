#pragma once
#ifndef LISTFACTORY_H
#define LISTFACTORY_H
#include "IAbstractFactoryStruct.h"
class ListFactory :
    public IAbstractFactoryStruct
{
public:
    virtual IStruct* creartEstructura();
};
#endif // !LISTFACTORY_H



