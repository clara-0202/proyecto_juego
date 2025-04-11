#include <stdio.h>
#include "papeleo.h"
#include "utiles.h"
#include <stdlib.h>
#include <stdbool.h>


#define PRIMER_VECTOR_NIVEL 0
#define SEGUNDO_VECTOR_NIVEL 1
#define TERCER_VECTOR_NIVEL 2
#define PRIMER_NIVEL 1
#define SEGUNDO_NIVEL 2
#define TERCER_NIVEL 3
#define MIKE 'W'
#define MEDIAS 'M'
#define FUEGOS 'F'
#define BOTELLAS_DE_GRITOS 'G'
#define INTERRUPTORES 'I'
#define PAPELEOS 'P'
#define CANT_OBS_NIV_UNO 15
#define CANT_OBS_NIV_DOS 9
#define CANT_OBS_NIV_TRES 6
#define CANT_MEDIAS_PRIMER_NIV 5
#define CANT_MEDIAS_SEGUNDO_NIV 4
#define CANT_MEDIAS_TERCER_NIV 3
#define CANT_FUEGOS_PRIMER_NIV 10
#define CANT_FUEGOS_SEGUNDO_NIV 5
#define CANT_FUEGOS_TERCER_NIV 3
#define CANT_BOTELLAS_GRITOS_PRIMER_NIV 4
#define CANT_BOTELLAS_GRITOS_SEGUNDO_NIV 3
#define CANT_BOTELLAS_GRITOS_TERCER_NIV 2
#define CANT_INTERRUPTORES_PRIMER_NIV 1
#define CANT_INTERRUPTORES_SEGUNDO_NIV 1
#define CANT_INTERRUPTORES_TERCER_NIV 0
#define CANT_PAPELEOS_PRIMER_NIV 2
#define CANT_PAPELEOS_SEGUNDO_NIV 3
#define CANT_PAPELEOS_TERCER_NIV 4
#define CANT_MOV_REALIZADOS 0
#define CANT_MOV_PRIMER_NIV 40
#define CANT_MOV_SEGUNDO_NIV 30
#define CANT_MOV_TERCER_NIV 20
#define CANT_MARTILLOS_PRIMER_NIV 4
#define CANT_MARTILLOS_SEGUNDO_NIV 5
#define CANT_MARTILLOS_TERCER_NIV 6
#define CANT_EXTINTORES_PRIMER_NIV 4
#define CANT_EXTINTORES_SEGUNDO_NIV 2
#define CANT_EXTINTORES_TERCER_NIV 2
#define CANT_MOV_EXTRA_PRIMER_NIVEL 10
#define MARTILLO_EXTRA 1
#define	PISTOLA_EXTRA 1
#define FUEGOS_PRIMER_NIV 2
#define FUEGOS_SEGUNDO_NIV 1
#define DIMENSION_PRIMER_NIV 22
#define DIMENSION_SEGUNDO_NIV 17
#define DIMENSION_TERCER_NIV 12
#define OLAF 'O'
#define STITCH 'S'
#define JASMIN 'J'
#define RAYO 'R'
#define PAREDES '#'
#define VACIO ' '
#define MAX_TERRENO 50
#define DERECHA 'D'
#define IZQUIERDA 'A'
#define MOVIMIENTO 1
#define ROTAR_HORARIA 'E'
#define ROTAR_ANTIHORARIA 'Q'
#define USAR_MARTILLO 'Z'
#define USAR_EXTINTOR 'C'
#define ARRIBA 'W'
#define ABAJO 'S'
#define MOVIMIENTOS_AGREGADOS 7
#define MOVIMIENTOS_PERDIDOS 10
#define SIN_MOVIMIENTOS 0
#define R_NIVEL1 7
#define R_NIVEL2 5
#define R_NIVEL3 3
#define PAREDES_RANDOM_N1 40
#define PAREDES_RANDOM_N2 30
#define PAREDES_RANDOM_N3 20
#define JUGANDO 0
#define GANADO 1
#define PERDIDO -1
#define NUM_TABLA_ASCII 48
#define MENSAJE_MOVIMIENTOS "\n\nCantidad de movimientos: %d\n\n",juego->jugador.movimientos
#define MENSAJE_INTERRUPTOR "\nInterruptores activados = "




//PRE: el numero de nivel tiene que ser 1,2 o 3
//POS:devuelve la dimension,dependiendo del nivel
int devuelve_dimension_matriz(int numero_nivel){
 	
 	int dimension;

	if (numero_nivel == PRIMER_NIVEL){ 
		dimension = DIMENSION_PRIMER_NIV;	
	}else if (numero_nivel == SEGUNDO_NIVEL){
		dimension = DIMENSION_SEGUNDO_NIV;
	}else if (numero_nivel == TERCER_NIVEL){
		dimension =DIMENSION_TERCER_NIV;
	}
	return dimension;
}


//PRE:el numero de nivel tiene que ser 1,2 o 3
//POS:inicializa el jugador cargando toda la información inicial
// y el personaje solo puede ser stitch, olaf,rayo o jasmin
void inicializar_jugador(jugador_t *jugador,int numero_nivel,char personaje_tp1, coordenada_t pos_inicial_jugador){
	jugador->posicion = pos_inicial_jugador;
	if (numero_nivel == PRIMER_NIVEL){	
		jugador->movimientos = CANT_MOV_PRIMER_NIV;
		jugador->martillos = CANT_MARTILLOS_PRIMER_NIV;
		jugador->extintores = CANT_EXTINTORES_PRIMER_NIV;
		jugador->ahuyenta_randall = false ;
		jugador->movimientos_realizados = CANT_MOV_REALIZADOS;

	}else if (numero_nivel == SEGUNDO_NIVEL){
		jugador->movimientos = CANT_MOV_SEGUNDO_NIV;
		jugador->martillos = CANT_MARTILLOS_SEGUNDO_NIV;
		jugador->extintores = CANT_EXTINTORES_SEGUNDO_NIV;
		jugador->ahuyenta_randall = false ;
		jugador->movimientos_realizados = CANT_MOV_REALIZADOS;

	}else if (numero_nivel == TERCER_NIVEL){
		jugador->movimientos = CANT_MOV_TERCER_NIV;
		jugador->martillos = CANT_MARTILLOS_TERCER_NIV;
		jugador->extintores = CANT_EXTINTORES_TERCER_NIV;
		jugador->ahuyenta_randall = false ;
		jugador->movimientos_realizados = CANT_MOV_REALIZADOS;
	}

}


//PRE: 
//POS:inicializa el terreno cargando la matriz hasta el tope de dicho nivel
void inicializar_terreno(char terreno[MAX_TERRENO][MAX_TERRENO],int tope){
	for (int i = 0; i < tope ; i++){
		for (int j = 0; j < tope ; j++){ 
			terreno[i][j] = VACIO ;
			
		}   
	}

}



//POS: recorre la matriz del juego y carga una pared, las cordenadas de las paredes coinciden con la de la matriz
void colocar_paredes(nivel_t nivel, char terreno[MAX_TERRENO][MAX_TERRENO]){
	for (int i = 0; i < nivel.tope_paredes; i++){	
		terreno[nivel.paredes[i].fil][nivel.paredes[i].col]= PAREDES;
	}

}


//PRE recibe la matriz llena de obstaculos
//POS indica donde poner las paredes en el terreno
bool esta_al_borde_una_pared(char terreno[MAX_TERRENO][MAX_TERRENO],int fila,int columna){
	if (terreno[fila][columna-1] == PAREDES|| terreno[fila][columna+1] == PAREDES || terreno[fila-1][columna] == PAREDES  || terreno[fila+1][columna] == PAREDES){
		return true;
		
	}else{
		return false;
	}


}



//POS recorre la matriz del juego y la imprime por pantalla
void mostrar_terreno(char terreno[MAX_TERRENO][MAX_TERRENO],int tope){
	for (int i = 0; i < tope ; i++){
		for (int j = 0; j < tope ; j++){
			printf(" %c", terreno[i][j]);
		}
	    printf("\n");
	}
}


//PRE el numero de nivel tiene que ser 1,2 o 3
//POS determina los topes de herramientas y obstaculos para cada nivel

void determinar_topes(int nivel,int* tope_medias,int* tope_fuegos, int* tope_botellas_gritos, int* tope_interruptores, int* tope_papeleos){
	if (nivel == PRIMER_NIVEL){
		*tope_medias = CANT_MEDIAS_PRIMER_NIV;
		*tope_fuegos = CANT_FUEGOS_PRIMER_NIV;
		*tope_botellas_gritos = CANT_BOTELLAS_GRITOS_PRIMER_NIV;
	    *tope_interruptores = CANT_INTERRUPTORES_PRIMER_NIV;
		*tope_papeleos = CANT_PAPELEOS_PRIMER_NIV ;
	}else if(nivel == SEGUNDO_NIVEL){
		*tope_medias = CANT_MEDIAS_SEGUNDO_NIV;
		*tope_fuegos = CANT_FUEGOS_SEGUNDO_NIV;
		*tope_botellas_gritos = CANT_BOTELLAS_GRITOS_SEGUNDO_NIV;
	    *tope_interruptores = CANT_INTERRUPTORES_SEGUNDO_NIV;
		*tope_papeleos = CANT_PAPELEOS_SEGUNDO_NIV;

	}else if(nivel == TERCER_NIVEL){
		*tope_medias = CANT_MEDIAS_TERCER_NIV;
		*tope_fuegos = CANT_FUEGOS_TERCER_NIV;
		*tope_botellas_gritos = CANT_BOTELLAS_GRITOS_TERCER_NIV;
	    *tope_interruptores = CANT_INTERRUPTORES_TERCER_NIV;
		*tope_papeleos = CANT_PAPELEOS_TERCER_NIV;
	}
}



//POS carga los vectores de obstaculos hasta el tope de dicho nivel y les da una posicion
void asignar_obstaculos(objeto_t obstaculos[MAX_OBSTACULOS],int tope_medias,int tope_fuegos,char terreno[MAX_TERRENO][MAX_TERRENO], int dimension){
	int i, fila, columna;

	for ( i = 0; i < tope_medias ; i++){ 
		 	do{
    			fila = rand() % dimension;
    			columna = rand() % dimension;
			} while(terreno[fila][columna] != VACIO);

			terreno[fila][columna] = MEDIAS;
			obstaculos[i].tipo = MEDIAS ;
			obstaculos[i].posicion.fil = fila ;
			obstaculos[i].posicion.col = columna ;
		}

		for (i = tope_medias; i < tope_fuegos + tope_medias ; i++){
			do{
    			fila = rand() % dimension;
    			columna = rand() % dimension;
			}while(terreno[fila][columna] != VACIO || !esta_al_borde_una_pared(terreno,fila,columna));

			terreno[fila][columna] = FUEGOS;
			obstaculos[i].tipo = FUEGOS ;
			obstaculos[i].posicion.fil = fila ;
			obstaculos[i].posicion.col = columna ;
		
		}
}



//PRE carga los vectores de herramientas hasta el tope de dicho nivel y les da una posicion
void asignar_herramientas(objeto_t herramientas[MAX_HERRAMIENTAS],int tope_interruptores, int tope_botellas_gritos, char terreno[MAX_TERRENO][MAX_TERRENO], int dimension) {
	int i, fila, columna;

	for ( i = 0; i < tope_botellas_gritos; i++){
			do{
    			fila = rand() % dimension;
    			columna = rand() % dimension;
			}while(terreno[fila][columna] != VACIO);

			terreno[fila][columna] = BOTELLAS_DE_GRITOS;
			herramientas[i].tipo = BOTELLAS_DE_GRITOS;
			herramientas[i].posicion.fil = fila ;
			herramientas[i].posicion.col = columna;
		}
		if(tope_interruptores == 1){

			do{
	    		fila = rand() % dimension;
	    		columna = rand() % dimension;
			}while(terreno[fila][columna] != VACIO);

			terreno[fila][columna] = INTERRUPTORES;
			herramientas[i].tipo = INTERRUPTORES;
			herramientas[i].posicion.fil = fila;
			herramientas[i].posicion.col = columna;
		}

}
//PRE:recibe un entero
//POS:convierte un caracter a un entero
char castear_id_papelos(int numero){
	char caracter = (char)(numero + NUM_TABLA_ASCII );

	return caracter;
}


//POS carga el vector papeleo hasta el tope de dicho nivel y le da una posicion
void asignar_papeleo(papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos, char terreno[MAX_TERRENO][MAX_TERRENO], int dimension){
	int fila,columna;

	for (int i = 0; i < tope_papeleos; i++){
		do{
	    		fila = rand() % dimension;
	    		columna = rand() % dimension;
			}while(terreno[fila][columna] != VACIO);

			terreno[fila][columna] = PAPELEOS;
			papeleos[i].id_papeleo = i+1;
			papeleos[i].recolectado = false;
			papeleos[i].posicion.fil = fila;
			papeleos[i].posicion.col = columna;

		
	}

}


//PRE el personaje del tp1 es olaf,stitch,rayo o jasmin
//POS determina el objeto que dara el personaje del tp1
void determinar_obsequios(juego_t *juego, char personaje_tp1){

	if (personaje_tp1 == OLAF){

		juego->niveles[PRIMER_VECTOR_NIVEL].tope_obstaculos -= FUEGOS_PRIMER_NIV;
		juego->niveles[SEGUNDO_VECTOR_NIVEL].tope_obstaculos -= FUEGOS_SEGUNDO_NIV;
	}else if(personaje_tp1  == STITCH){
		juego->niveles[TERCER_VECTOR_NIVEL].tope_papeleos -= PISTOLA_EXTRA;
	}else if(personaje_tp1 == RAYO){
		if (juego->nivel_actual == SEGUNDO_VECTOR_NIVEL){
			juego->jugador.movimientos += CANT_MOV_EXTRA_PRIMER_NIVEL;
		}
	}else if(personaje_tp1 == JASMIN){
		juego->jugador.martillos += MARTILLO_EXTRA;
	}

}


/*
 * Inicializará el nivel, cargando toda la información inicial, los datos de los obstaculos,herramientas y papeleos.
 */
void inicializar_nivel(nivel_t* nivel, int numero_nivel, char personaje_tp1){
	char terreno[MAX_TERRENO][MAX_TERRENO];
	int tope_medias ,tope_fuegos, tope_botellas_gritos, tope_interruptores, tope_papeleos;
	int dimension;


	obtener_paredes(numero_nivel, nivel->paredes, &(nivel->tope_paredes), &(nivel->pos_inicial_jugador));

	dimension = devuelve_dimension_matriz(numero_nivel);

	inicializar_terreno(terreno,dimension);
	colocar_paredes(*nivel,terreno);
	terreno[nivel->pos_inicial_jugador.fil][nivel->pos_inicial_jugador.col] = MIKE ;
	determinar_topes(numero_nivel,&tope_medias,&tope_fuegos, &tope_botellas_gritos, &tope_interruptores, &tope_papeleos);
	nivel->tope_obstaculos = tope_medias + tope_fuegos;
	nivel->tope_herramientas = tope_botellas_gritos +tope_interruptores;
    nivel->tope_papeleos = tope_papeleos;
	asignar_obstaculos( nivel->obstaculos, tope_medias, tope_fuegos, terreno, dimension);	
	asignar_herramientas( nivel->herramientas, tope_interruptores, tope_botellas_gritos, terreno, dimension);
	asignar_papeleo(nivel->papeleos, tope_papeleos, terreno, dimension);
		
}

/*
 * Inicializará el juego, cargando toda la información inicial, los datos del jugador, 
 * el personaje resultado del tp anterior, y los 3 niveles. El campo "nivel_actual"
 * comienza en 1.
 */
void inicializar_juego(juego_t* juego, char personaje_tp1){


	juego->nivel_actual =PRIMER_NIVEL;
	juego->personaje_tp1 = personaje_tp1;

	inicializar_nivel(&juego->niveles[PRIMER_VECTOR_NIVEL],PRIMER_NIVEL,juego->personaje_tp1);
	inicializar_nivel(&juego->niveles[SEGUNDO_VECTOR_NIVEL],SEGUNDO_NIVEL,juego->personaje_tp1);
	inicializar_nivel(&juego->niveles[TERCER_VECTOR_NIVEL],TERCER_NIVEL,juego->personaje_tp1);
	
	inicializar_jugador(&juego->jugador,juego->nivel_actual,juego->personaje_tp1, juego->niveles[juego->nivel_actual-1].pos_inicial_jugador);
		
	determinar_obsequios(juego, personaje_tp1);
	
}


/* 
 * Procedimiento que recibe el juego e imprime toda su información por pantalla.
 */
void imprimir_terreno(juego_t juego){

	char terreno[MAX_TERRENO][MAX_TERRENO];
	int dimension;
	int nivel = juego.nivel_actual-1 ;

	dimension = devuelve_dimension_matriz(juego.nivel_actual);
	inicializar_terreno(terreno,dimension);
	colocar_paredes(juego.niveles[nivel],terreno);
	printf("NIVEL: %i\n",juego.nivel_actual);
	printf("cantidad de extintores:%i\n",juego.jugador.extintores);
	printf("cantidad de martillos:%i\n",juego.jugador.martillos);
	printf("cantidad de movimientos:%i\n",juego.jugador.movimientos);
	printf("cantidad de movimientos_realizados:%i\n",juego.jugador.movimientos_realizados);
	printf("\npara moverse a lateralmente a la derecha, ingrese: D");
	printf("\npara moverse a lateralmente a la izquierda, ingrese: A");
	printf("\npara girar el terrreno horariamente, ingrese: E");
	printf("\npara girar el terrreno antihorariamente, ingrese: Q");
	printf("\npara extinguir el fuego, ingrese : C \n");
	printf("para romperla pared, ingrese : Z \n");

	for (int i = 0; i < juego.niveles[nivel].tope_obstaculos; i++){
		terreno[juego.niveles[nivel].obstaculos[i].posicion.fil][juego.niveles[nivel].obstaculos[i].posicion.col] = juego.niveles[nivel].obstaculos[i].tipo ;	
	}
	for (int i = 0; i < juego.niveles[nivel].tope_herramientas; i++){
		terreno[juego.niveles[nivel].herramientas[i].posicion.fil][juego.niveles[nivel].herramientas[i].posicion.col] = juego.niveles[nivel].herramientas[i].tipo ;	
	}
	for (int i = 0; i < juego.niveles[nivel].tope_papeleos; i++){
		if(!juego.niveles[nivel].papeleos[i].recolectado)
			terreno[juego.niveles[nivel].papeleos[i].posicion.fil][juego.niveles[nivel].papeleos[i].posicion.col] = castear_id_papelos(juego.niveles[nivel].papeleos[i].id_papeleo) ;	
	}

	terreno[juego.jugador.posicion.fil][juego.jugador.posicion.col]= MIKE;
	 mostrar_terreno(terreno,dimension);

}



//PRE:la funcion recibe un caracter 
//POS: devuelve true si el movimiento recibido es igual a la convencion,sino flase
// Q-> la matriz rota antihoraria 
// E-> la matriz rota horariamente
// A-> el jugador se mueve hacia la izquierda
// D->el jugador se mueve hacia la derecha
// Z->el jugador utiliza el martillo 
// C->el jugador utiliza el extintor

bool es_caracter_valido(char tecla){
	return (tecla==ROTAR_HORARIA|| tecla==ROTAR_ANTIHORARIA || tecla==IZQUIERDA || tecla==DERECHA || tecla== USAR_MARTILLO || tecla== USAR_EXTINTOR);
}


//PRE: ingresa tecla valida
//POS: le pide al iusario que ingrese un movimiento hasta que este sea valido.

void ingresar_movimientos(char* tecla){
    printf("Ingrese un caracter:(D(DERECHA),A(Ingrese),Z(USAR_MARTILLO),C(USAR_EXTINTOR))\n");
    scanf(" %c", tecla);
    while(!es_caracter_valido(*tecla)){
        printf("El caracter ingresado no es valido, por favor vuelva a intentarlo\n");
        scanf(" %c", tecla);
    }

}


//
//POS: rota las coordenas de la fila y columnas y te devuelve la rotacion
void rotar_coordenada(coordenada_t* coordenada,int dimension, char tecla){
	
	coordenada_t aux_coordenada;
	aux_coordenada.fil = 0;
	aux_coordenada.col = 0;
	if(tecla == ROTAR_HORARIA){
		aux_coordenada.fil = coordenada->col;
        aux_coordenada.col = abs(coordenada->fil - (dimension - 1));	
		coordenada->fil= aux_coordenada.fil;
		coordenada->col = aux_coordenada.col;
	}else if(tecla == ROTAR_ANTIHORARIA){
	    aux_coordenada.fil = abs(coordenada->col-(dimension-1));
	    aux_coordenada.col = coordenada->fil;	
	    coordenada->fil= aux_coordenada.fil;
		coordenada->col = aux_coordenada.col;
		
	}
		(*coordenada)=aux_coordenada;
}
	
//PRE:
//POS:rota las posiciones del jugador,obstaculos,herramientas y paredes.
void realizar_rotacion(nivel_t* niveles ,jugador_t* jugador,int dimension, char tecla){

	rotar_coordenada(&(jugador->posicion),dimension,tecla);
	

	for (int i = 0; i < niveles->tope_obstaculos; i++){ 
		 	rotar_coordenada(&(niveles->obstaculos[i].posicion),dimension,tecla);
	}

	
	for (int i = 0; i < niveles->tope_papeleos; i++){
		 rotar_coordenada(&(niveles->papeleos[i].posicion),dimension,tecla);
	}


	for (int i = 0; i < niveles->tope_herramientas; i++){
		 rotar_coordenada(&(niveles->herramientas[i].posicion),dimension,tecla);
	}
	for (int i = 0; i < niveles->tope_paredes; i++){
		 rotar_coordenada(&(niveles->paredes[i]),dimension,tecla);
	}	
}

//POS:indica si la posicion se superpone con una posicion donde hay pared.
bool coincide_con_pared(int col,int fil, coordenada_t paredes){
	return(col == paredes.col && fil  == paredes.fil);
}

//PRE:Recibe coordenadas validas
 //POS:Indica si esas coordenadas se superponen 
bool coordenadas_iguales(coordenada_t coor1, coordenada_t coor2){
	bool esta_arriba=false;
	if(coor1.fil==coor2.fil && coor1.col==coor2.col){
		esta_arriba=true;
	}
	return esta_arriba;
}

//PRE:
//POS:corrobora la cantidad de objetos en la coordenada
int coordenada_a_corroborar(juego_t juego, coordenada_t coordenada){
	int i, cantidad = 0;
	i = 0;
	while(i < juego.niveles[juego.nivel_actual - 1].tope_obstaculos && cantidad < 2){
		if(coordenadas_iguales(coordenada, juego.niveles[juego.nivel_actual - 1].obstaculos[i].posicion))
			cantidad++;
		i++;
	}
	i = 0;
	while(i < juego.niveles[juego.nivel_actual - 1].tope_herramientas && cantidad < 2){
		if(coordenadas_iguales(coordenada, juego.niveles[juego.nivel_actual - 1].herramientas[i].posicion))
			cantidad++;
		i++;
	}
	i = 0;
	while(i < juego.niveles[juego.nivel_actual - 1].tope_paredes && cantidad < 2){
	if(coordenadas_iguales(coordenada, juego.niveles[juego.nivel_actual - 1].paredes[i]))
			cantidad++;
		i++;
	}
	i = 0;
	while(i < juego.niveles[juego.nivel_actual - 1].tope_papeleos && cantidad < 2){
		if(coordenadas_iguales(coordenada, juego.niveles[juego.nivel_actual - 1].papeleos[i].posicion))
			cantidad++;
		i++;
	}
	return cantidad;
}


//PRE: recibe el nivel.
//POS: devuelve un entero divisible por r para cada nivel.
int divisor_del_nivel(int nivel){
	int divisor;
	if(nivel == PRIMER_NIVEL)
		divisor = R_NIVEL1;
	else if(nivel == SEGUNDO_NIVEL)
		divisor = R_NIVEL2;
	else
		divisor = R_NIVEL3;
	return divisor;
}



//PRE: el tope debe estar inicializado
//POS:verifica si hay pared cuando el jugador se mueve lateralmente.
bool hay_pared (coordenada_t movimiento, nivel_t nivel, char tecla){
	int i=0;
	int j=0;
	bool es_pos_pared= false;

	if(tecla== DERECHA){
		while(i<nivel.tope_paredes && !es_pos_pared){
			if (coincide_con_pared(movimiento.col+1, movimiento.fil, nivel.paredes[i])){
				es_pos_pared = true;
			}
			i++;
		}
	}
	if(tecla== IZQUIERDA){
		while(j<nivel.tope_paredes && !es_pos_pared){
			if (coincide_con_pared(movimiento.col-1, movimiento.fil, nivel.paredes[j])){
				es_pos_pared = true;
			}
			j++;
		}			
	}
	return es_pos_pared;
}

//
//POS:suma uno a los movimientos realizados y resta uno a los movimientos

void actualiza_movimientos(jugador_t* jugador){
	(jugador->movimientos_realizados) += 1;
	(jugador->movimientos) -= 1;
}
 

//PRE: movimientos realizados tienen que ser diferenciable por:
//nivel1: divisible por 7
//nivel2: divisible por 5
//nivel3: divisible por 3
//POS:inserta paredes random en lugares vacios y cambia de lugar los papeleos mientras el ahuyenta randall este desactivo.
void agregar_obstaculos(juego_t* juego, char tecla){
	int papeleo_sorteado;
	coordenada_t nueva_pared;
	if(juego->jugador.movimientos_realizados % divisor_del_nivel(juego->nivel_actual) == 0 && !juego->jugador.ahuyenta_randall){
		do{
			papeleo_sorteado = rand() % juego->niveles[juego->nivel_actual - 1].tope_papeleos;
		}while(juego->niveles[juego->nivel_actual - 1].papeleos[papeleo_sorteado].recolectado);
		do{
			juego->niveles[juego->nivel_actual - 1].papeleos[papeleo_sorteado].posicion.col = rand() % (devuelve_dimension_matriz(juego->nivel_actual) - 1) + 1;
			juego->niveles[juego->nivel_actual - 1].papeleos[papeleo_sorteado].posicion.fil = rand() % (devuelve_dimension_matriz(juego->nivel_actual) - 1) + 1;
		}while(coordenada_a_corroborar(*juego, juego->niveles[juego->nivel_actual - 1].papeleos[papeleo_sorteado].posicion) > 1);
	}
	if((juego->nivel_actual == PRIMER_NIVEL &&  juego->jugador.movimientos_realizados < PAREDES_RANDOM_N1 ) || (juego->nivel_actual == SEGUNDO_NIVEL && juego->jugador.movimientos_realizados < PAREDES_RANDOM_N2)  || (juego->nivel_actual == TERCER_NIVEL && juego->jugador.movimientos_realizados < PAREDES_RANDOM_N3 )){
		do{
			nueva_pared.col = rand() % (devuelve_dimension_matriz(juego->nivel_actual) - 1) + 1;
			nueva_pared.fil = rand() % (devuelve_dimension_matriz(juego->nivel_actual) - 1) + 1;
		}while(coordenada_a_corroborar(*juego, nueva_pared) > 0 );
		juego->niveles[juego->nivel_actual - 1].paredes[juego->niveles[juego->nivel_actual - 1].tope_paredes] = nueva_pared;
		juego->niveles[juego->nivel_actual - 1].tope_paredes++;
	}
}

//PRE: tiene que ingresar un caracter valido('D'(DERECHA) o 'A'(IZQUIERDA))
//POS: si nohay pared actualiza los movimientos del jugador Y agrega obstaculos, en caso contrario no los actualiza y no agrega obstaculo.
void nuevas_coordenadas_movimientos(juego_t* juego , char tecla){
	if (tecla == DERECHA){
		if(!hay_pared(juego->jugador.posicion,juego->niveles[juego->nivel_actual-1],tecla)){
			juego->jugador.posicion.col = juego->jugador.posicion.col +1;
			agregar_obstaculos(juego,tecla);
			actualiza_movimientos(&(juego->jugador));
		}
	}
	if (tecla== IZQUIERDA){
		if(!hay_pared(juego->jugador.posicion,juego->niveles[juego->nivel_actual-1],tecla)){
			juego->jugador.posicion.col= juego->jugador.posicion.col -1;
			agregar_obstaculos(juego,tecla);
			actualiza_movimientos(&(juego->jugador));
		}
	}	
}



//PRE:
//POS:verifica que las cordenadas sean iguales,elimina un fuego del vector de obstaculos y elimina un extintor al jugador
void extinguir_fuego(juego_t* juego, coordenada_t pos){
	int i=0;
	while(i<juego->niveles[juego->nivel_actual-1].tope_obstaculos){
		if(juego->niveles[juego->nivel_actual-1].obstaculos[i].tipo == FUEGOS && coordenadas_iguales(pos,juego->niveles[juego->nivel_actual-1].obstaculos[i].posicion)){
			i++;
			juego->jugador.extintores-= 1;
			while(i<juego->niveles[juego->nivel_actual-1].tope_obstaculos){
				juego->niveles[juego->nivel_actual-1].obstaculos[i - 1] = juego->niveles[juego->nivel_actual-1].obstaculos[i];
				i++;
			}
			juego->niveles[juego->nivel_actual-1].tope_obstaculos--;
		}	
		i++;
	}
}

//PRE:
//POS:verifica que las cordenadas sean iguales,elimina una pared del vector de paredes y elimina un martillo al jugador
void martillar_pared(juego_t* juego, coordenada_t pared_a_martillar){
	int dimension = devuelve_dimension_matriz(juego->nivel_actual);
	int i=0;
	if(pared_a_martillar.col > 0 && pared_a_martillar.col < dimension - 1 && pared_a_martillar.fil > 0 && pared_a_martillar.fil < dimension - 1){
		i = 0;
		while(i < juego->niveles[juego->nivel_actual-1].tope_paredes){
			if(coordenadas_iguales(juego->niveles[juego->nivel_actual-1].paredes[i], pared_a_martillar)){
				i++;
				juego->jugador.martillos-= 1;
				while(i < juego->niveles[juego->nivel_actual-1].tope_paredes){
					juego->niveles[juego->nivel_actual-1].paredes[i - 1] = juego->niveles[juego->nivel_actual-1].paredes[i];
					i++;
				}
				juego->niveles[juego->nivel_actual-1].tope_paredes--;
			}
			i++;
		}
	}
}


//PRE:se tiene que ingresar una tecla valida.
//POS:recibe la coordenada del personaje y la tecla, y actualiza la la posicion de acuerdo a la tecla recibida o elimina objeto.

void realizar_movimientos(juego_t* juego,char tecla,int dimension){
	char dir_fuego;
	coordenada_t pos_a_extinguir = juego->jugador.posicion;
	char dir_pared;
	coordenada_t pos_a_martillar = juego->jugador.posicion;
	


	if(tecla==ROTAR_ANTIHORARIA || tecla==ROTAR_HORARIA){
		realizar_rotacion(&(juego->niveles[juego->nivel_actual-1]),&(juego->jugador),dimension,tecla);
		agregar_obstaculos(juego,tecla);
		actualiza_movimientos(&juego->jugador);
	}
	else if (tecla==DERECHA || tecla==IZQUIERDA){
		nuevas_coordenadas_movimientos(juego, tecla);
		
	}
	else if(tecla == USAR_EXTINTOR){
		if(juego->jugador.extintores > 0){
			printf("\nIngrese la dirección en la que se encuentra el fuego:(D(DERECHA),A(Ingrese),W(ARRIBA))\n");
			scanf(" %c",&dir_fuego);
			while(dir_fuego != IZQUIERDA && dir_fuego != DERECHA && dir_fuego != ARRIBA){
				printf("\nIngrese una dirección válida en la que se encuentra el fuego:(D(DERECHA),A(Ingrese),W(ARRIBA))\n");
				scanf(" %c",&dir_fuego);
				
			}
			if(dir_fuego == DERECHA)
				pos_a_extinguir.col++;
			else if(dir_fuego == IZQUIERDA)
				pos_a_extinguir.col--;
			else if(dir_fuego == ABAJO)
				pos_a_extinguir.fil--;
			extinguir_fuego(juego, pos_a_extinguir); 
		}
	}
	else if(tecla== USAR_MARTILLO){
		if(juego->jugador.martillos > 0){
			printf("\n ingrese la direccion para romper la pared:(D(DERECHA),A(Ingrese),W(ARRIBA),S(ABAJO))\n");
			scanf(" %c",&dir_pared);
			while(dir_pared != IZQUIERDA && dir_pared != DERECHA && dir_pared != ARRIBA && dir_pared != ABAJO){
				
				printf("\nIngrese una dirección válida en la que se encuentra la pared:(D(DERECHA),A(Ingrese),W(ARRIBA),S(ABAJO))\n");
				scanf(" %c",&dir_pared);
			}
			if(dir_pared == DERECHA){
				pos_a_martillar.col++;   
			}
			else if(dir_pared == IZQUIERDA){
				pos_a_martillar.col--;    
			}
			else if(dir_pared == ARRIBA){
				pos_a_martillar.fil--;
			}
			else if(dir_pared== ABAJO){
				pos_a_martillar.fil++;
			}
			martillar_pared(juego, pos_a_martillar);
		}

		
	}
}



//PRE:recibe el juego y la posicion del obstaculo
//POS: Buscara si el jugador piso algun obstaculo, en caso de que si, devuelve su posicion en el vector
 
bool coinciden_con_obstaculos(juego_t juego,int *posicion_obstaculo){
	(*posicion_obstaculo)=-1;
	bool encontro_obstaculo=false;
	int i=0;
	while(i<juego.niveles[juego.nivel_actual-1].tope_obstaculos && encontro_obstaculo==false){
		if(coordenadas_iguales(juego.jugador.posicion,juego.niveles[juego.nivel_actual-1].obstaculos[i].posicion)){		
			encontro_obstaculo=true;
			(*posicion_obstaculo)=i;
		}
		i++;
	}
	return encontro_obstaculo;
}

//PRE: recibe el juego y la posicion de herramientas
//POS:Buscara si el jugador piso alguna herramienta, en caso de que si, devuelve su posicion en el vector

bool coinciden_con_herramientas(juego_t juego,int *posicion_herramientas){
	(*posicion_herramientas)=-1;
	bool encontro_herramientas=false;
	int i=0;
	while(i<juego.niveles[juego.nivel_actual-1].tope_herramientas && encontro_herramientas==false){
		if(coordenadas_iguales(juego.jugador.posicion,juego.niveles[juego.nivel_actual-1].herramientas[i].posicion)){		
			encontro_herramientas=true;
			(*posicion_herramientas)=i;
		}
		i++;
	}
	return encontro_herramientas;
}
//PRE:recibe el juego y la posocion de papeleo
//POS:Buscara si el jugador piso algun papeleo, en caso de que si, devuelve su posicion en el vector
 
bool coinciden_con_papeleo(juego_t juego,int *posicion_papeleo){
	(*posicion_papeleo)=-1;
	bool encontro_papeleo=false;
	int i=0;
	while(i<juego.niveles[juego.nivel_actual-1].tope_papeleos && encontro_papeleo==false){
		if(coordenadas_iguales(juego.jugador.posicion,juego.niveles[juego.nivel_actual-1].papeleos[i].posicion)){		
			encontro_papeleo=true;
			(*posicion_papeleo)=i;
		}
		i++;
	}
	return encontro_papeleo;
}


//PRE:verifica que el jugador este arriba de un obstaculo,herramienta,papeleo, por lo que recibe una posicion valida
//POS:dependiendo de donde este arriba el jugador, se llevan a cabo diferentes acciones:
//botellas de gritos-> gana 7 movimientos
//interruptores-> se activa el interruptor
//medias-> pierde 10 movimientos
//fuegos-> se queda sin movimientos, pierde el juego
//papeleo-> recolecta papeleos

void verificar_coincidencias(juego_t* juego){
	int posicion_cosa, i; 
	bool papeleos__anteriores_recolectados;
	if(coinciden_con_obstaculos(*juego, &posicion_cosa)){
		if(juego->niveles[juego->nivel_actual-1].obstaculos[posicion_cosa].tipo==MEDIAS){
			juego->jugador.movimientos-=MOVIMIENTOS_PERDIDOS;
			
		}else if (juego->niveles[juego->nivel_actual-1].obstaculos[posicion_cosa].tipo== FUEGOS){
			juego->jugador.movimientos = SIN_MOVIMIENTOS;
		}
	}else if (coinciden_con_herramientas(*juego, &posicion_cosa)){	
		 if(juego->niveles[juego->nivel_actual-1].herramientas[posicion_cosa].tipo == BOTELLAS_DE_GRITOS){
			juego->jugador.movimientos+=MOVIMIENTOS_AGREGADOS;		
		}else if(juego->niveles[juego->nivel_actual-1].herramientas[posicion_cosa].tipo == INTERRUPTORES){
			juego->jugador.ahuyenta_randall = !juego->jugador.ahuyenta_randall;
		}
		
	}else if(coinciden_con_papeleo(*juego, &posicion_cosa)){
		papeleos__anteriores_recolectados = true;
		i = 0;
		while(i < posicion_cosa && papeleos__anteriores_recolectados){
			if(!juego->niveles[juego->nivel_actual-1].papeleos[i].recolectado)
				papeleos__anteriores_recolectados = false;
			i++;
		}
		if(papeleos__anteriores_recolectados)
			juego->niveles[juego->nivel_actual-1].papeleos[posicion_cosa].recolectado = true;
	}
 }


//PRE: recibe dos coordenadass validas
//POS:indica si estas coordenadas se superponen
bool tiene_pared_arriba(coordenada_t jugador, coordenada_t objeto){
	bool tiene_pared_arriba = false;
	if(jugador.fil++ == objeto.fil && jugador.col == objeto.col ){
			tiene_pared_arriba= true;
	}
	return tiene_pared_arriba;

}
//PRE: recibe dos coordenas validas y el tope ya inicializado
//POS: verifica que el personaje caiga sobre una pared
bool cae_jugador(coordenada_t jugador, int tope_paredes, coordenada_t paredes[MAX_PAREDES]){
	bool cae = false;
	for (int i = 0; i <tope_paredes ; i++){
		if(tiene_pared_arriba(jugador, paredes[i])==true){
			cae =true;
		}
	}
	return cae;
}



//PRE:
//POS:mientras no hay pared el jugador va a caer 
//y chequea por cada posicion que cae verifica que si hay un objeto este cumpla su accion.
void agregar_gravedad(juego_t* juego){
	
	while(!cae_jugador(juego->jugador.posicion,juego->niveles[juego->nivel_actual - 1].tope_paredes,juego->niveles[juego->nivel_actual - 1].paredes) ){
		juego->jugador.posicion.fil++;
		verificar_coincidencias(juego);
	}

	juego->jugador.posicion.fil--;
}

/*
 * El nivel se dará por terminado, si se reolectan todos los papeleos en el mismo.
 * Devolverá:
 * -> 0 si el estado es jugando.
 * -> 1 si el estado es ganado.
 */

int estado_nivel(papeleo_t papeleos[MAX_PAPELEOS], int tope_papeleos){
	int i = 0, resultado = 1;
	while(i < tope_papeleos && resultado == GANADO){
		if(!papeleos[i].recolectado)
			resultado = JUGANDO;
		i++;
	}
	return resultado;
}

/*
 * Recibe un juego con todas sus estructuras válidas.
 *
 * El juego se dará por ganado, si terminó todos los niveles. O perdido, si el personaje queda
 * sin movimientos. 
 * Devolverá:
 * -> 0 si el estado es jugando. 
 * -> -1 si el estado es perdido.
 * -> 1 si el estado es ganado.
 */

int estado_juego(juego_t juego){
	int resultado = JUGANDO;
	if(juego.jugador.movimientos <= 0)
		resultado = PERDIDO;
	if(juego.nivel_actual == TERCER_NIVEL && estado_nivel(juego.niveles[juego.nivel_actual-1].papeleos, juego.niveles[juego.nivel_actual-1].tope_papeleos) == GANADO)
		resultado = GANADO;
	return resultado;
}


/*
 * Moverá el personaje, y realizará la acción necesaria en caso de chocar con un elemento
 */

void realizar_jugada(juego_t* juego){

	int dimension = devuelve_dimension_matriz(juego->nivel_actual);
 	char tecla = VACIO;
	ingresar_movimientos(&tecla);
	realizar_movimientos(juego,tecla,dimension);
	verificar_coincidencias(juego);
	agregar_gravedad(juego);
	printf(MENSAJE_MOVIMIENTOS);
	printf(MENSAJE_INTERRUPTOR);	
}




