#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include <conio.h>

#include<string.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo))
using namespace std;
struct nodo{
	int id;
	char nombre_peli[40];
	char autor_peli[40];
	int puntos;
	struct nodo *izquierda;
	struct nodo *derecha;
}*pelicula=NULL;

FILE *arpeliculas;
int identificador=0;
int cont=0;
char nombre[40];
char autor[40];
void menu1();
struct nodo *crear_pelicula(int id, char nombrepeli, char autorpeli, int puntos);
void insertar_pelicula(nodo *&pelicula, int id, char nombrepeli, char autorpeli, int puntos);
void mostrar_peliculas(nodo *pelicula, int contador);

nodo *crear_pelicula(int id, char nombrepeli, char autorpeli, int puntos){
	nodo *nuevo = reservar_memoria;
	nuevo -> id = id;
	strcpy(nuevo -> nombre_peli,nombre);
	strcpy(nuevo -> autor_peli,autor);
	nuevo -> puntos=puntos;
	nuevo -> izquierda = NULL ;
	nuevo -> derecha = NULL;
	return nuevo;
}

void insertar_pelicula(nodo *&pelicula, int id, char nombrepeli, char autorpeli, int puntos){
	if(pelicula==NULL){
		
		nodo *nueva_pelicula=crear_pelicula(id, nombrepeli, autorpeli, puntos);
		pelicula=nueva_pelicula;
		arpeliculas=fopen("pelis.txt","w+b");
		fwrite(&pelicula, sizeof(pelicula), 1, arpeliculas);
		rewind(arpeliculas);
		fclose(arpeliculas);
		
	} else {
	  int raiz=pelicula->id;
	  if(id<raiz){
  	
	     insertar_pelicula(pelicula->izquierda,id,nombrepeli,autorpeli,puntos);
 	    arpeliculas=fopen("pelis.txt","a+b");
		fwrite(&pelicula, sizeof(pelicula), 1, arpeliculas);
		rewind(arpeliculas);
		fclose(arpeliculas);
	 }else{
	 	   
	  	 insertar_pelicula(pelicula->derecha,id,nombrepeli,autorpeli,puntos);
	     arpeliculas=fopen("pelis.txt","a+b");
			fwrite(&pelicula, sizeof(pelicula), 1, arpeliculas);
			rewind(arpeliculas);
			fclose(arpeliculas);
	  }
	}
	rewind(arpeliculas);
	fclose(arpeliculas);
}

void mostrar_peliculas(nodo *pelicula, int contador){
	int i;
	if(pelicula==NULL){
		return;
	}else{
		mostrar_peliculas(pelicula->derecha,contador+1);
		for(i=0;i<contador;i++){
			printf("");
		}
		printf("id pelicula: %d\nnombre pelicula: %s\nautor: %spuntos al cliente: %d\n\n",pelicula->id,pelicula->nombre_peli,pelicula->autor_peli,pelicula->puntos);
		
		mostrar_peliculas(pelicula->izquierda,contador+1);
	}
}
void leer_Archivo(){
	 


}
void menu1(){
	int op, num, i,punto;
	 do{
	 	system("cls");
	 printf("--------MENU--------\n");
	 printf("1. insertar peliculas\n");
	 printf("2. mostrar peliculas\n");
	 printf("0. salir\n");
	using namespace std;
	 scanf ("%d",&op);
	 
		switch(op){
			case 0:{
				exit(0);
				break;
			}
			case 1:{
				identificador=identificador+1;
				int id=identificador;
				printf("ingrese nombre de la pelicula\n");
				fflush( stdin );
				cin.getline(nombre, 40);
				
				printf("ingrese nombre del autor\n");
				fflush( stdin );
				fgets(autor, 40, stdin);
				
				printf("puntaje que dara al cliente por alquilar la pelicula\n");
				fflush( stdin );
				scanf("%d",&punto);
				fflush( stdin );
				printf("los datos que se enviaran a la tabla de datos seran:\n\nid pelicula: %d\nnombre pelicula: %s\nautor: %spuntos al cliente: %d\n\n",id,nombre,autor,punto);
				system("pause");
				insertar_pelicula(pelicula,id,nombre[40],autor[40],punto);
				break;
			}
			case 2:{
				mostrar_peliculas(pelicula,cont);
				system("pause");
				break;
			}
			default :
			printf("Opcion Invalida\n")	 ;	
		}
	}while(op!=0);
}

int main(int argc, char** argv) {
	menu1();
	return 0;
}
