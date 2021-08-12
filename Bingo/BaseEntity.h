#pragma once
#ifndef BASEENTITY_H
#define BASEENTITY_H
class BaseEntity
{
protected:
	int id;
	BaseEntity(int id);
public:
	virtual int getID();
};

#endif // !BASEENTITY_H

