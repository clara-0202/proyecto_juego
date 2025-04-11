#include <stdio.h>
#include "tp1.h"
#include "papeleo.h"
#include "utiles.h"
#include <time.h>
#include <stdlib.h>
#include "controlador.h"
#define JUGANDO 0
#define GANADO 1
#define PERDIDO -1


/* 
 * Muestra informacion  del juego con respecto a los identificadores y su tipo
 */
void mostrar_informacion_juego(){
    printf("el jugador es representado con la 'W', tiene que recolectar los papeleos de los tres niveles que se encuentran dentro del terreno.");
    printf(" \nOJO! Cada vez que te mueves se agregan paredes y depende de la cantidad de movimientos que haga los papeleos cambian de lugar, por lo que piensa bien tus movimientos!");
    printf("\nAdemas hay objetos que pueden perjudicarte, 'F'(FUEGO) si caes en uno de ellos perdes todos los movimientos ,'M'(MEDIAS) si chocas con una de ella perdes 10 movimientos.");
    printf("\nPEROOOOO HAY UN OBJETO QUE TE AYUDARA,'G'(BOTELLAS_GRITOS) estas te sumaran 7 movimientos.");
    printf("\nPuedes evitar perjudicarte con las siguientes ayudas, el MARTILLO 'Z' que te rompera las paredes adyacentes pero no las que estan en el borde del terreno.");
    printf("\ny el EXTINTOR 'C' este extinguira los fuegos.");
    printf("\nQUE EMPIECE EL JUEGO,Buena suerte! :)\n");
}

/*precondiciones: El juego ya tiene que haber terminado
 *postcondiciones: Mostrara el resultado
 */
void mostrar_estado_juego(juego_t juego){
    if (estado_juego(juego)==GANADO){
        printf("Felicitaciones, ha ganado el juego! \n");
    }
    else if(estado_juego(juego)==PERDIDO){
        printf("Ha perdido el juego :( \n");
    }
}

int main() {

 srand((unsigned)time(NULL));
 
 char personaje = ' ';
 determinar_personaje_tp1(&personaje);
 juego_t juego;
 inicializar_controlador();
 inicializar_juego(&juego, personaje);
 mostrar_informacion_juego();
 imprimir_terreno(juego);
 while(estado_juego(juego)==JUGANDO){
    realizar_jugada(&juego);
    imprimir_terreno(juego);
 }
 terminar_controlador();
 mostrar_estado_juego(juego);

	return 0;
}




