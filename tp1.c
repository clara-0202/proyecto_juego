
#include "tp1.h"
#include <stdio.h>

const char TRINEO = 'T';
const char NAVE_ESPACIAL= 'N';
const char CAMION = 'C';
const char ALFOMBRA = 'A';
const char BOLAS_DE_NIEVE = 'B';
const char PIUM_PIUM = 'P';
const char KUCHAU = 'K';
const char GENIO = 'G';
const int HORA_LIMITE_MENOR = 0;
const int HORA_LIMITE_MAYOR = 23;
const float MINUTO_LIMITE_MENOR = 0.00f;
const float MINUTO_LIMITE_MAYOR = 0.60f;
const int NOTA_LIMITE_MENOR = 1;
const int NOTA_LIMITE_MAYOR = 10;
const int PUNTAJE_BOLAS_NIEVE = 3;
const int PUNTAJE_PIUM_PIUM = 6;
const int PUNTAJE_KUCHAU = 9;
const int PUNTAJE_GENIO = 12;
const int PUNTAJE_TRINEO_NAVE = 10;
const int PUNTAJE_CAMION_ALFOMBRA = 20;
const int APLAZO = 1;
const int REGULAR = 3;
const int INTERMEDIO = 4;
const int SUFICENTE = 6;
const int AVANZADO = 7;
const int DESTACADO = 8;
const int MULTIPLICADOR_MIN = 1;
const int MULTIPLICADOR_BAJO = 2;
const int MULTIPLICADOR_INTERMEDIO = 3;
const int MULTIPLICADOR_MAX = 4;
const int PUNTAJE_MIN_STITCH_OLAF = 13;
const int PUNTAJE_MAX_STITCH_OLAF = 41;
const float HORA_DE_EXAMEN = 15.30f;
const char PERSONAJE_STICH = 'S';
const char PERSONAJE_JASMIN = 'J';
const char PERSONAJE_OLAF = 'O';
const char PERSONAJE_RAYO = 'R';

//PRE:
//POS: pide al usuario que ingrese un valor 
//(los validos son: 'T','N','C','A'.)
//hasta que cumpla con la condicion. 
void indicar_transporte (char* transporte) { 
	do {

		printf("salis de tu casa y te enteras que hay un paro de trenes,¿que otro transporte elegis?\n");
		printf("ingrese un tipo de transporte: ('T'(trineo), 'N'(nave espacial), 'C'(camion) ,'A'(alfombra)) \n");
		scanf (" %c",transporte);
	 } while (*transporte != TRINEO && *transporte != NAVE_ESPACIAL && *transporte != CAMION && *transporte != ALFOMBRA); 

	 	
	 }

//PRE:
//POS: pide al usuario que ingrese un valor tipo caracter 
// (los validos son: 'B','P','K','G'.)
// hasta que cumpla con la condicion.

void indicar_arma (char* arma) {
	do {
		printf("upss, hay una manifestacion!!!!!; ¿que arma utilizas para deshacerte de la manifestacion?\n");
		printf("elija una arma:('B'(bolas de nieve),'P'(pium pium),'K'(kuchau),'G'(genio)\n");
		scanf(" %c",arma);
	} while(*arma != BOLAS_DE_NIEVE && *arma != PIUM_PIUM && *arma != KUCHAU && *arma != GENIO);
}

//PRE:
//POST: pide al usuario que ingrese un 
//(los validos son: La hora no puede ser > a hora_limite_mayor,ni < a hora limite menor
//Los minutos no pueden ser > minuto limite mayor)
// hasta que cumpla con la condicion.

void indicar_hora (float* horario_facultad) {

	          printf ("perfectooo lograste superar la manifestacion,¿ a que hora llegaste a la universidad?\n");
             printf ("ingrese la hora de llegada:\n");
             scanf ("%f",horario_facultad);

		          int hora = (int) (*horario_facultad);
		          float minutos = *horario_facultad - (float)(hora);
		 

        while ((hora < HORA_LIMITE_MENOR || hora > HORA_LIMITE_MAYOR) || (minutos < MINUTO_LIMITE_MENOR || minutos > MINUTO_LIMITE_MAYOR)) {

	          printf ("chee ojooo, estas ingresando una hora no valida!!!\n");
             printf ("ingrese la hora de llegada:\n");
             scanf ("%f",horario_facultad);

                 hora = (int) (*horario_facultad);
	              minutos = *horario_facultad - (float)(hora);

	}	
		
} 

//PRE:
//POS: pide al usuario que ingrese un valor. 
// (los validos son: del nota limite menor al nota limite mayor)
// hasta que se cumpla la condicon.

void indicar_nota (int* nota_parcial) {
          printf("LLEGO LA NOTA DEL PARCIAL, ¿que nota sacaste?\n");
          printf("ingrese su nota:\n");
	       scanf(" %i",nota_parcial);

	while(*nota_parcial < NOTA_LIMITE_MENOR || *nota_parcial > NOTA_LIMITE_MAYOR) {

	    printf("eyyy, la nota tiene que estar entre 1 y 10!!!\n");
	    printf("ingrese su nota:\n");
	    scanf(" %i",nota_parcial);

	}
		
}

//PRE:el valor que recibe la funcion tiene que ser : 'T','N','C','A'
//POS:si el valor de transporte: es'T' O 'N' la funcion devuelve el puntaje trineo nave
// si es 'C' o 'A' la funcion devuelve el puntaje camion alfombra


int calculo_puntaje_1 (char transporte) {

	if ((transporte == TRINEO) || (transporte == NAVE_ESPACIAL)) {
		return (PUNTAJE_TRINEO_NAVE);
	} else {
		return (PUNTAJE_CAMION_ALFOMBRA);
	}
}

//PRE: el valor que recibe la funcion tiene que ser : 'B','P','K','G'
//POS: si el valor de arma: es'B' la funcion devuelve el puntaje bolas de nieve
// si es 'P' la funcion devuelve el puntaje pium pium
// si es 'K' la funcion devuelve el puntaje kuchau
// si es 'G' la funcion devuelve el puntaje genio
int calculo_puntaje_2 (char arma) {

	if (arma == BOLAS_DE_NIEVE) {
	      return (PUNTAJE_BOLAS_NIEVE);

         } else if (arma == PIUM_PIUM) {
	      return (PUNTAJE_PIUM_PIUM);

         } else if (arma == KUCHAU) {
	      return (PUNTAJE_KUCHAU);

         } else {
	      return (PUNTAJE_GENIO);
         }
}

//PRE: el valor que recibe la funcion tienen que ser : numeros positivos y menores o iguales a 10.
//POS: si el valor de nota: esta entre aplazo y regular la funcion devuelve el multiplicador min
// si esta entre intermedio y suficiente la funcion devuelve el multiplicador bajo
// si esta entre avanzado y destacado la funcion devuelve el multiplicador intermedio
// sino es ninguno de los anteriores la funcion devuelve el multiplicador max
int calculo_puntaje_4 (int nota_parcial) {

	if (nota_parcial >= APLAZO && nota_parcial <= REGULAR) {
	      return (MULTIPLICADOR_MIN);

         } else if (nota_parcial >= INTERMEDIO &&  nota_parcial <= SUFICENTE) {
	      return (MULTIPLICADOR_BAJO); 

         } else if (nota_parcial >= AVANZADO && nota_parcial <= DESTACADO) {
	      return (MULTIPLICADOR_INTERMEDIO);

         } else {
	      return (MULTIPLICADOR_MAX);
         }
}

//PRE:
//POS:calcula el puntaje final e imprime por pantalla el personaje resultante.
void indicar_personaje (int puntaje_total, float horario_facultad, char* personaje) {
	
	  printf("tu puntaje final es: %d\n", puntaje_total);
    
if ( (puntaje_total >= PUNTAJE_MIN_STITCH_OLAF) && (puntaje_total <= PUNTAJE_MAX_STITCH_OLAF) ) {
     
    if ( horario_facultad <= HORA_DE_EXAMEN ) {
    	(*personaje) = PERSONAJE_STICH ;
          printf ("Tu personaje es:-Stitch-\n");
       } else {
       	(*personaje) = PERSONAJE_OLAF ;
          printf("Tu personaje es: -Olaf-\n");
        }


   } else {

    if ( horario_facultad <= HORA_DE_EXAMEN ) {
    	(*personaje) = PERSONAJE_JASMIN ;
        printf("Tu personaje es: -Jasmín-\n");
       } else {
       	(*personaje) = PERSONAJE_RAYO ;
        printf("Tu personaje es: -Rayo McQueen-\n"); 
        }
     }


}

void determinar_personaje_tp1 (char* personaje) {

char transporte;
indicar_transporte(&transporte);

char arma;
indicar_arma(&arma);

float horario_facultad;
indicar_hora(&horario_facultad);

int nota_parcial;
indicar_nota(&nota_parcial);

int puntaje_1 = calculo_puntaje_1 (transporte);
int puntaje_2 = calculo_puntaje_2 (arma);
int puntaje_4 = calculo_puntaje_4 (nota_parcial);

int puntaje_total = (puntaje_1 + (puntaje_2 * puntaje_4));
indicar_personaje(puntaje_total, horario_facultad, personaje);


}


	