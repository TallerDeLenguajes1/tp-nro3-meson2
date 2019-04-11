#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define N 5

//enum TRaza{Orco=1, Humano=2, Mago=3, Enano=4, Elfo=5};
char Nombres[6][10]={"Lala", "Lele", "Lili", "Lolo", "Lulu"};
char Apellidos[6][10]={" Fa", " Fe", " Fi", " Fo", " Fu"};

struct TDatos {
char  *Raza; //nota 1
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

void CargarDatos(struct TDatos *dat1);
void MostrarDatos(struct TDatos *dat2);
void cargar_stats(struct TCaracteristicas *car1);
void mostrar_stats(struct TCaracteristicas *car2);


int main(){
   
   srand(time(NULL));  

   struct TPersonaje *pj = (struct TPersonaje*)malloc(sizeof(struct TPersonaje)*N);
   
   for(int i=0; i<N;i++){

   pj[i].Caracteristicas = (struct TCaracteristicas*)malloc(sizeof(struct TCaracteristicas));
   cargar_stats(pj[i].Caracteristicas);

   pj[i].DatosPersonales = (struct TDatos*)malloc(sizeof(struct TDatos));
   CargarDatos(pj[i].DatosPersonales);

   }

   for(int i=0; i<N;i++){

   CargarDatos(pj[i].DatosPersonales);   
   MostrarDatos(pj[i].DatosPersonales);
   cargar_stats(pj[i].Caracteristicas);
   mostrar_stats(pj[i].Caracteristicas);

   }



   return 0;
}

void CargarDatos(struct TDatos *dat1){
   int var1, var2,var3;
   var1=1+rand()% 5;
   //p_datos->Raza=(TRaza)var;

   dat1->ApellidoNombre=(char *)malloc(sizeof(char)*50);
   var2=rand()% 5;
   strcpy(dat1->ApellidoNombre,Nombres[var2]);
   var3=rand()% 5;
   strcat(dat1->ApellidoNombre,Apellidos[var3]);

   dat1->edad=rand() % 310;
   dat1->Salud=100;
   //(printf("%d\n",var1);
   switch(var1){
      case 1:
         dat1->Raza = (char *) malloc(4*sizeof(char));
         dat1->Raza = "Orco";
         break;
      case 2:
         dat1->Raza = (char *) malloc(6*sizeof(char));
         dat1->Raza = "Humano";
         break;
      case 3:
         dat1->Raza = (char *) malloc(4*sizeof(char));
         dat1->Raza = "Mago";
         break;
      case 4:
         dat1->Raza = (char *) malloc(5*sizeof(char));
         dat1->Raza = "Enano";
         break;
      case 5:
         dat1->Raza = (char *) malloc(4*sizeof(char));
         dat1->Raza = "Elfo";
         break;
   }
}
void MostrarDatos(struct TDatos *dat2){
   puts(" \n\n Datos del Personaje \n\n ");
   printf("Raza: %s", dat2->Raza);
   

   printf("\nNombre y Apellido : ");
   puts(dat2->ApellidoNombre);

   printf("Edad: %d",dat2->edad);

   printf("\nSalud: %.3f",dat2->Salud);
}
void cargar_stats(struct TCaracteristicas *car1){ 
   car1->velocidad=(rand()%(10-1+1))+1;
   car1->destreza=(rand()%(5-1+1))+1;
   car1->fuerza=(rand()%(10-1+1))+1;
   car1->Nivel=(rand()%(10-1+1))+1;
   car1->Armadura=(rand()%(10-1+1))+1;
}
void mostrar_stats(struct TCaracteristicas *car2){
	printf("\n\n   ||Caracteristicas del personaje||\n\n");
	printf("Nivel: %d\n",car2->Nivel);
	printf("Fuerza: %d\n",car2->fuerza);
	printf("Destreza: %d\n",car2->destreza);
	printf("Velocidad: %d\n",car2->velocidad);
	printf("Armadura: %d\n",car2->Armadura);
}
/*PD = car1->destreza * car1->fuerza * car1->Nivel;
ED = rand()% 100;
VA = PD * ED;
PDEF = car1->Armadura * car1->Velocidad*/
