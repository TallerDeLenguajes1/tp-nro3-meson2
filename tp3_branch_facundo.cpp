//============================================================================
// Name        : tp3_engrupo.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <stdio.h>
#include <stdlib.h>

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

void CargarDatos(struct TDatos *datos);
void MostrarDatos(struct TDatos *datos);
void cargar_stats(struct TCaracteristicas *Caracteristicas);
void mostrar_stats(struct TCaracteristicas *Caracteristicas);
double cargarAtaque(struct TPersonaje *pj ,int indice );
void batalla(double AtaqueP1,double vidaP1 ,double AtaqueP2,double vidaP2);
int main(){
   int n,personaje1, personaje2;
   //double PD,ED, VA, PDEF;
   double PDEF;
   double AtaqueP1, AtaqueP2,DefP1,DefP2;
   double vidaP1,vidaP2;
   srand(time(NULL));
   setvbuf(stdout,NULL,_IONBF,0);
   puts("\nIngrese la cant de personajes que desea crear.\n");
   scanf("%d",&n);

   struct TPersonaje *pj = (struct TPersonaje*)malloc(sizeof(struct TPersonaje)*n); //reservo memoria para mis personajes
   //carga los personajes
   puts("\n                PERSONAJES QUE SE PUEDE ELEGIR                    \n");
   for(int i=0;i<n;i++){ // lo hice para 5 personajes
      printf("\nPersonaje %d\n",i+1);
      pj[i].DatosPersonales=(TDatos *)malloc(sizeof(TDatos));
      CargarDatos(pj[i].DatosPersonales);
      MostrarDatos(pj[i].DatosPersonales);

      pj[i].Caracteristicas = (TCaracteristicas*)malloc(sizeof(TCaracteristicas));
      cargar_stats(pj[i].Caracteristicas);
      mostrar_stats(pj[i].Caracteristicas);
   }
   puts("\n    -     -       -     -       -      -      -  \n");
   puts("¿Que dos personajes desea elegir? (del 1 a 5)");
   scanf("%d",&personaje1);
   puts("-------------Personaje 1-------------");
   personaje1=(int)personaje1-1;
   MostrarDatos(pj[personaje1].DatosPersonales);
   mostrar_stats(pj[personaje1].Caracteristicas);
   //Cargo ataque y defensa del personaje 1
   AtaqueP1=cargarAtaque(pj,personaje1);
   PDEF=(double)pj[personaje1].Caracteristicas->Armadura*pj[personaje1].Caracteristicas->velocidad;
   DefP1=PDEF;
   vidaP1=(double)pj[personaje1].DatosPersonales->Salud * DefP1*90;//calculo la vida: salud*defensa*90
   printf("\nAtaque del personaje 1: %.3f",AtaqueP1);
   printf("\nDefensa del peronaje 1: %.3f ",DefP1);
   printf("\nVida del peronaje 1: %.3f ",vidaP1);

   scanf("%d",&personaje2);
   puts("\n-------------Personaje 2-------------");
   personaje2=(int)personaje2-1;
   MostrarDatos(pj[personaje2].DatosPersonales);
   mostrar_stats(pj[personaje2].Caracteristicas);
   //Cargo ataque y defensa del personaje 2
   AtaqueP2=cargarAtaque(pj,personaje2);
   PDEF=(double)pj[personaje2].Caracteristicas->Armadura*pj[personaje2].Caracteristicas->velocidad;
   DefP2=PDEF;
   vidaP2=(double)pj[personaje2].DatosPersonales->Salud * DefP2*90;
   printf("\nAtaque del personaje 2: %.3f",AtaqueP2);
   printf("\nDefensa del peronaje 2: %.3f",DefP2);
   printf("\nVida del peronaje 2: %.3f ",vidaP2);

   //------Batalla-----

   batalla( AtaqueP1, vidaP1 , AtaqueP2, vidaP2);
   return 0;
}

void CargarDatos(struct TDatos *p_datos){
   int var;
   var=1+rand()% 5;
   p_datos->Raza=(TRaza)var;

   p_datos->ApellidoNombre=(char *)malloc(sizeof(char)*30);
   var=rand()% 5;
   strcpy(p_datos->ApellidoNombre,Nombres[var]);
   var=rand()% 5;
   strcat(p_datos->ApellidoNombre,Apellidos[var]);

   p_datos->edad=rand() % 301;
   p_datos->Salud=100;
}
void MostrarDatos(struct TDatos *p_datos){
   puts("    Datos del Personaje \n ");
   printf("Raza: ");
   switch(p_datos->Raza){
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
   puts(p_datos->ApellidoNombre);

   printf("Edad: %d",p_datos->edad);

   printf("\nSalud: %.3f",p_datos->Salud);
}
void cargar_stats(struct TCaracteristicas *Caracteristicas){
   Caracteristicas->velocidad=(rand()%(10-1+1))+1;
   Caracteristicas->destreza=(rand()%(5-1+1))+1;
   Caracteristicas->fuerza=(rand()%(10-1+1))+1;
   Caracteristicas->Nivel=(rand()%(10-1+1))+1;
   Caracteristicas->Armadura=(rand()%(10-1+1))+1;
}
void mostrar_stats(struct TCaracteristicas *Caracteristicas){
   printf("\n\n   ||Caracteristicas del personaje||\n\n");
   printf("Nivel: %d\n",Caracteristicas->Nivel);
   printf("Fuerza: %d\n",Caracteristicas->fuerza);
   printf("Destreza: %d\n",Caracteristicas->destreza);
   printf("Velocidad: %d\n",Caracteristicas->velocidad);
   printf("Armadura: %d\n",Caracteristicas->Armadura);
}
double cargarAtaque(struct TPersonaje *pj ,int indice ){
   double PD,ED, VA;
   //double MDP =50000; //daño maximo
   //ataque
   PD=(double)pj[indice].Caracteristicas->fuerza*pj[indice].Caracteristicas->Nivel*pj[indice].Caracteristicas->destreza;
   ED= rand()% 101;
   VA= ED*PD;
   return(VA);
}
void batalla(double AtaqueP1,double vidaP1 ,double AtaqueP2,double vidaP2){
   int x=1;
   puts("\n-------------------------------BATALLA---------------------------------\n");
   puts("\n3 Ataques de cada uno. Solo si no muere uno antes.\n");
   while(vidaP1>0 && vidaP2>0 && x<4){
      vidaP1=vidaP1-AtaqueP2;
      vidaP2=vidaP2-AtaqueP1;
      x=x+1;
   }
   if(vidaP1>vidaP2){
      printf("\nGano el Personaje 1 tiene : %.3f de vida.",vidaP1);
      printf("\nEl personaje 2 tiene : %.3f de vida.",vidaP2);
   }else{
      if(vidaP1<vidaP2){
         printf("\nGano el Personaje 2 tiene : %.3f de vida.",vidaP2);
         printf("\nEl personaje 1 tiene : %.3f de vida.",vidaP1);
      }else{
         printf("\nEs un empate : P1=%.3f y P2=%.3f.",vidaP1,vidaP2);
      }
   }
}
