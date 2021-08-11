#pragma once
#ifndef PILAFACTORY_H
#define PILAFACTORY_H
#include "IAbstractFactoryStruct.h"
class PilaFactory :
    public IAbstractFactoryStruct
{
public:
	
	virtual IStruct* creartEstructura();
};
#endif // !PILAFACTORY_H

