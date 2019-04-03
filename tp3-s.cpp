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
int main(){
   struct TDatos datos;
   struct TDatos *p_datos=&datos;
   srand(time(NULL));
   CargarDatos(p_datos);
   MostrarDatos(p_datos);
   return 0;
}

void CargarDatos(struct TDatos *p_datos){
   int var;
   var=1+rand()% 5;
   p_datos->Raza=(TRaza)var;

   p_datos->ApellidoNombre=(char *)malloc(sizeof(50));
   var=rand()% 5;
   strcpy(p_datos->ApellidoNombre,Nombres[var]);
   var=rand()% 5;
   strcat(p_datos->ApellidoNombre,Apellidos[var]);

   p_datos->edad=rand() % 310;
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
