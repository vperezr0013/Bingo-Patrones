#pragma once
#ifndef IABSTRACTFACTORYSTRUCT_H
#define IABSTRACTFACTORYSTRUCT_H
#include "IStruct.h"
#include "Pila.h"
#include "Cola.h"
#include "List.h"
class IAbstractFactoryStruct
{
public:
	IStruct* estructuraNueva;
	virtual IStruct* creartEstructura();
};


#endif // !IAbstractFactoryStruct


