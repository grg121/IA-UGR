#ifndef COMPORTAMIENTOJUGADOR_H
#define COMPORTAMIENTOJUGADOR_H

#include "comportamientos/comportamiento.hpp"
#include<queue>
using namespace std;

class ComportamientoJugador : public Comportamiento{

public:
    ComportamientoJugador(unsigned int size) : Comportamiento(size){
        f2 = c2 = 0 ;
        abierta = 0;
        fil = col = 99 ;
        ultimaAccion = actIDLE;
        brujula = 0;
        tiempo = 0 ;

        for(int i = 0 ; i < 4 ; i++)
            lotengo[i] = false ;
        for(int i = 0 ; i < 200 ; i++)
            for(int j = 0 ; j < 200 ; j++){
                mapaAUX[i][j] = '?';
                memoriaAUX[i][j] = 0 ;
            }

        situado = false;
        int nobjetos = 0;

    }

    ComportamientoJugador(const ComportamientoJugador & comport) : Comportamiento(comport){}
    ~ComportamientoJugador(){}

    Action think(Sensores sensores);

    int interact(Action accion, int valor);


    ComportamientoJugador * clone(){return new ComportamientoJugador(*this);}

private:
    void NoPisar();
    int nobjetos ;
    int f2,c2;
    int delante, izquierda, derecha ;
    char encimade;
    Action accion;

    void Reinicio();
    int abierta ;
    bool situado;

    char mapaAUX[200][200];
    int memoriaAUX[200][200];
    int memoria[100][100];

    int brujula;
    int fil, col ;
    int tiempo;
    Action ultimaAccion;

    bool lotengo[4];

    bool PuedoPisar(char c);
    void Giro();

};

#endif
