#ifndef CARTON_H
#define CARTON_H
#include "BaseEntity.h"

class Carton: public BaseEntity
{
public:
    Carton(int id);
    int getNum();
    void setNum(int num);
    bool isOcupado();
    void setOcupado(bool x);
private:
    int num;
    bool ocupado;
};

#endif // CARTON_H
