#include "Gestor.h"


Gestor::Gestor(){
    //Ejemplo para crear una estructura
    IStruct* estructuraPruuebaLista = crearEstructura(1);
    IStruct* estructuraPruuebaPila = crearEstructura(2);
    IStruct* estructuraPruuebaCola = crearEstructura(3);

    //ListaBolitasJugadas
    this->bolitasJugadas = crearEstructura(1);
}

IStruct* Gestor::crearEstructura(int tEstructura)
{
    IAbstractFactoryStruct* factory = nullptr;
    switch (tEstructura)
    {
    case 1:
        factory = new ListFactory();
        break;
    case 2:
        factory = new PilaFactory();
        break;
    case 3:
        factory = new ColaFactory();
        break;
    default:
        break;
    }
    return factory->creartEstructura();
}


void Gestor::agregarBolitaJugadaaLista(BaseEntity* bolitaJugada){
    if(!validarBolitasJugadas(bolitaJugada)){
        bolitasJugadas->agregar(bolitaJugada);
    }
}

bool Gestor::validarBolitasJugadas(BaseEntity *bolitaJugada){
    bool response = false;
    Nodo* aux = nullptr;
    if(!this->bolitasJugadas->isVoid()){
        aux = this->bolitasJugadas->getHead();
        while(aux->getSig() != nullptr){
            if(aux->getInfo()->getID() == bolitaJugada->getID()){
                response = true;
                break;
            }
            aux = aux->getSig();
        }
        if(aux->getInfo()->getID() == bolitaJugada->getID()){
            response = true;
        }
        aux = aux->getSig();
    }
    return response;
}
