#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

enum TRaza{Orco=1, Humano=2, Mago=3, Enano=4, Elfo=5};
char Nombres[6][10]={"Lala", "Lele", "Lili", "Lolo", "Lulu"};
char Apellidos[6][10]={" Fa", " Fe", " Fi", " Fo", " Fu"};

struct TDatos {
TRaza Raza; //nota 1
char *ApellidoNombre; //nota 2
int edad; //entre 0 a 300
double Salud;//100
};
struct TCaracteristicas{
int velocidad;// 1 a 10
int destreza; //1 a 5
int fuerza;//1 a 10
int Nivel; //1 a 10
int Armadura; //1 a 10
};
struct TPersonaje {
TDatos * DatosPersonales;
TCaracteristicas * Caracteristicas;
};
void choice( int num, TPersonaje *pj );
void mostrartag( int num, TPersonaje *pj );
void CargarDatos(struct TPersonaje *pj);
void MostrarDatos(struct TPersonaje *pj);
void cargar_stats(struct TPersonaje *pj);
void mostrar_stats(struct TPersonaje *pj);
void batalla( int j1, int j2, TPersonaje *pj );
int main(){
	int n,j1,j2;
	printf("cant de personajes a generar: ");
    char *p, s[100];
    while (fgets(s, sizeof(s), stdin)) {
        n = strtol(s, &p, 10);
        if (p == s || *p != '\n' || n==0 || n<2) {
            printf("Porfavor solo numeros naturales mayores a dos: ");
        } else break;
    }
   srand(time(NULL));
   struct TPersonaje *pj = (struct TPersonaje*)malloc(sizeof(struct TPersonaje) * n);
   for(int i=0;i<n;i++){
   	   	(pj+i)->Caracteristicas = (struct TCaracteristicas*)malloc(sizeof(struct TCaracteristicas));
   		(pj+i)->DatosPersonales = (struct TDatos*)malloc(sizeof(struct TDatos));
		CargarDatos(pj+i);
   		cargar_stats(pj+i);
   }
   mostrartag( n, pj );
   for(int i=1;i!=0;){
	   	printf("N%c de personaje que desea mostrar (pulse 0 para finalizar): ",167);
		while (fgets(s, sizeof(s), stdin)) {
	        i = strtol(s, &p, 10);
	        if (p == s || *p != '\n') {
	            printf("Porfavor solo enteros: ");
	        } else break;
	    }
	   	if(i!=1){
	   		if(i>n){
	   			printf("acaso quieres que el programa explote?!\n\n");
		    }
			else if(i==0){
			}
		    else{
		    	i--;
   				MostrarDatos(pj+i);
	   			mostrar_stats(pj+i);
	   			mostrartag( n, pj );
			}
	   	
		}
		else if(i==1){
			i=0;
			MostrarDatos(pj+i);
	   		mostrar_stats(pj+i);
	   		mostrartag( n, pj );
	   		i++;
		}

   	}
   	printf("\n\nseleccione jugador 1: ");
	while (fgets(s, sizeof(s), stdin)) {
        j1 = strtol(s, &p, 10);
        if (p == s || *p != '\n' || j1==0 || j1>n) {
            printf("Porfavor solo la cantidad de personajes creados: ");
        } else break;
    }
   printf("\nseleccione jugador 2: ");
    while (fgets(s, sizeof(s), stdin)) {
        j2 = strtol(s, &p, 10);
        if (p == s || *p != '\n' || j2==0 || j2==j1 || j2>n) {
            printf("Seleccione un dentro de los creados y pj distinto al 1%c : ",167);
        } else break;
    }
   batalla( j1,j2,pj );
   
   
   return 0;
}
void batalla( int j1, int j2, TPersonaje *pj ){
	int pdj1,mdp=50000,pdj2,edj1,edj2;
	double saludj1,saludj2,dpj1,dpj2,vaj2,pdefj2,vaj1,pdefj1;
	if(j1==1){
		pdj1=(pj->Caracteristicas->destreza)*(pj->Caracteristicas->fuerza)*(pj->Caracteristicas->Nivel);
		pdefj1=(pj->Caracteristicas->Armadura)*(pj->Caracteristicas->velocidad);
		saludj1=pj->DatosPersonales->Salud;
	}
	else{
		j1--;
		pdj1=((pj+j1)->Caracteristicas->destreza)*((pj+j1)->Caracteristicas->fuerza)*((pj+j1)->Caracteristicas->Nivel);
		pdefj1=((pj+j1)->Caracteristicas->Armadura)*((pj+j1)->Caracteristicas->velocidad);
		saludj1=(pj+j1)->DatosPersonales->Salud;
	}
	if(j2==1){
		pdj2=(pj->Caracteristicas->destreza)*(pj->Caracteristicas->fuerza)*(pj->Caracteristicas->Nivel);
		pdefj2=(pj->Caracteristicas->Armadura)*(pj->Caracteristicas->velocidad);
		saludj2=pj->DatosPersonales->Salud;
	}
	else{
		j2--;
		pdj2=((pj+j2)->Caracteristicas->destreza)*((pj+j2)->Caracteristicas->fuerza)*((pj+j2)->Caracteristicas->Nivel);
		pdefj2=((pj+j2)->Caracteristicas->Armadura)*((pj+j2)->Caracteristicas->velocidad);
		saludj2=(pj+j2)->DatosPersonales->Salud;
	}
	for (int i=0;i<3;i++){
		printf("\n=================RONDA %d=====================\n",i+1);
		edj1=((rand()%(100-1+1))+1);
		edj2=((rand()%(100-1+1))+1);
		vaj1=pdj1*edj1;
		vaj2=pdj2*edj2;
		dpj1=((vaj1-pdefj2)/mdp)*100;
		dpj2=((vaj2-pdefj1)/mdp)*100;
		if(dpj1<0){
			dpj1=0;
		}
		if(dpj2<0){
			dpj2=0;
		}
		saludj1-=dpj2;
		saludj2-=dpj1;
		printf("Salud actual jugador 1: %.2f\n",saludj1);
		printf("Salud actual jugador 2: %.2f\n",saludj2);
		if(saludj1<=0){
			printf("\n==============================================\n");
			printf("EN ESTA BATALLA EL JUGADOR 2 DIO UN GOLPE MUY FUERTE AL JUGADOR 1.\n");
			printf("EL GOLPE FUE TAN FUERTE QUE ELIMINO AL JUGADOR 1 (que mal jugador 1) \n\n ||FIN DEL JUEGO||\n");
			i=3;
		}
		if(saludj2<=0){
			printf("\n==============================================\n");
			printf("EN ESTA BATALLA EL JUGADOR 1 DIO UN GOLPE MUY FUERTE AL JUGADOR 2.\n");
			printf("EL GOLPE FUE TAN FUERTE QUE ELIMINO AL JUGADOR 2 (que mal jugador 2) \n\n ||FIN DEL JUEGO||\n");
			i=3;
		}
	}	
	if ( saludj1==saludj2 ){
		printf("\n==============================================\n");
		printf("LAMENTABLEMENTE ESTA BATALLA TERMINO EN EMPATE");
	}
	else if( saludj1>saludj2 ){
		if(saludj2<=0){
		}
		else{
			printf("\n==============================================\n");
			printf("EN ESTA BATALLA GANO EL JUGADOR 1 \n\n ||FIN DEL JUEGO||\n");
		}
	}
	else{
		if(saludj2>saludj1){
			if (saludj1<=0){
			}
			else{
				printf("\n==============================================\n");
				printf("EN ESTA BATALLA GANO EL JUGADOR 2 \n\n ||FIN DEL JUEGO||\n");
			}
		}
	}
}
void cargar_stats(struct TPersonaje *pj){	
	pj->Caracteristicas->velocidad=(rand()%(10-1+1))+1;
	pj->Caracteristicas->destreza=(rand()%(5-1+1))+1;
	pj->Caracteristicas->fuerza=(rand()%(10-1+1))+1;
	pj->Caracteristicas->Nivel=(rand()%(10-1+1))+1;
	pj->Caracteristicas->Armadura=(rand()%(10-1+1))+1;
}
void mostrar_stats(struct TPersonaje *pj){
	printf("\n\n   ||Caracteristicas del personaje||\n\n");
	printf("Nivel: %d\n",pj->Caracteristicas->Nivel);
	printf("Fuerza: %d\n",pj->Caracteristicas->fuerza);
	printf("Destreza: %d\n",pj->Caracteristicas->destreza);
	printf("Velocidad: %d\n",pj->Caracteristicas->velocidad);
	printf("Armadura: %d\n",pj->Caracteristicas->Armadura);
}
void choice( int num, TPersonaje *pj ){
	mostrar_stats(pj+num);
	MostrarDatos(pj+num);
}
void mostrartag( int num, TPersonaje *pj ){
	printf("======================================\n");
	for (int i=0;i<num;i++){
		printf("%d: Raza: ",i+1);
   		switch((pj+i)->DatosPersonales->Raza){
		      case 1: printf("Orco; ");
		      break;
		      case 2: printf("Humano;");
		      break;
		      case 3: printf("Mago; ");
		      break;
		      case 4: printf("Enano; ");
		      break;
		      case 5: printf("Elfo; ");
		      break;
		      default: printf("Error\n");
   		}
	
   		printf("Nombre: ");
   		puts((pj+i)->DatosPersonales->ApellidoNombre);
	}
	printf("======================================\n");

}
void CargarDatos(struct TPersonaje *pj){
   int var;
   var=1+rand()% 5;
   pj->DatosPersonales->Raza=(TRaza)var;

   pj->DatosPersonales->ApellidoNombre=(char *)malloc(sizeof(50));
   var=rand()% 5;
   strcpy(pj->DatosPersonales->ApellidoNombre,Nombres[var]);
   var=rand()% 5;
   strcat(pj->DatosPersonales->ApellidoNombre,Apellidos[var]);

   pj->DatosPersonales->edad=rand() % 310;
   pj->DatosPersonales->Salud=100;
}
void MostrarDatos(struct TPersonaje *pj){
	printf("======================================\n");
   puts("    Datos del Personaje \n ");
   printf("Raza: ");
   switch(pj->DatosPersonales->Raza){
      case 1: printf("Orco");
      break;
      case 2: printf("Humano");
      break;
      case 3: printf("Mago");
      break;
      case 4: printf("Enano");
      break;
      case 5: printf("Elfo");
      break;
      default: printf("Error\n");
   }
	
   printf("\nNombre y Apellido : ");
   puts(pj->DatosPersonales->ApellidoNombre);

   printf("Edad: %d",pj->DatosPersonales->edad);

   printf("\nSalud: %.3f",pj->DatosPersonales->Salud);
}






