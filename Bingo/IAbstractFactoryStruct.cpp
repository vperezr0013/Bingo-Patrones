#include "IAbstractFactoryStruct.h"

IStruct* IAbstractFactoryStruct::creartEstructura() {
	return new IStruct();
}