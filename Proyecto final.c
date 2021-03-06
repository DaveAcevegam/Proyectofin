#include <stdio.h>
#include <string.h>


void iniciarTablero();
void mostrarTablero(int band); 
void leerCoordenadas(FILE *f);
void archivo(char nombre[6], int edad, int ganada, int barcos);

int tablero[10][10];

int main() 
{
	FILE *f;
	
	iniciarTablero();
	mostrarTablero(0);
	leerCoordenadas(f);
	printf("\n");
	mostrarTablero(1);
		
	printf("\n");		
	system("pause");
	return 1;
}
void iniciarTablero()
{
	int i,j;
	
	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 10; j++)
		{
			tablero[i][j] = 0;	
		}
	}
}
void mostrarTablero(int band	)
{
	int i,j;
	
	printf("   ");										
	for(i = 0; i < 10; i++)
	printf("%d   ",i);
	printf("\n");

	for(i = 0; i < 10; i++)
	{
		printf("%d  ", i);
		for(j = 0; j < 10; j++)
		{
			
			if(band)
			{
				if(tablero[i][j] == 1)
				
				printf("%c   ", 254);
				else
				printf("%c   ", 120);
			}
				else printf("%c   ",120);	
		}
		
	printf("\n");
	}
}   

void leerCoordenadas(FILE *f)
{
	int num, i, line,col,j;
	char car;
	
	srand(time(NULL));
	num = 1 + rand()%(3-1);
	
	if(num == 1)
		f = fopen("coordenadas1.txt","r");
	if(num == 2)
		f = fopen("coordenadas2.txt","r");
	if(num == 3)
		f = fopen("coordenadas3.txt","r"); 
	
	if(f != NULL);
	
	{
		for(i = 0; i < 10; i++)
		{
			fscanf(f,"%d%c%d", &line, &car, &col);
		
				for(j = 0; j < 3; j++)
				{
					tablero[line ][col+j] = 1;
				}
		}		
	}
} 

void archivo(char nombre[6], int edad, int ganada, int barcos){
   /*la funcion recibe 4 parametros
   char nombre[10]: es la cadena del nombre
   int edad: la edad
   int ganada: recibe un 1 o un 0, si el jugador gana guardara 1
               y si pierde guardara un 0
   int barcos: recibe el numero de barcos que logo hundir el perdedor*/

   FILE * flujo;
   flujo = fopen("informacion.txt", "a");
   if(flujo == NULL){
      perror("Error al crear el archivo\n");
   } else {
      if(ganada==1){
        fprintf(flujo, "%s     %d     ganador",nombre, edad);
        fputc('\n', flujo);
      } else{
        fprintf(flujo, "%s     %d     perdedor  %d    barcos hundidos",nombre, edad, barcos);
        fputc('\n', flujo);
      }
      fflush(flujo);
      fclose(flujo);
      printf("DATOS GUARDADOS EXITOSAMENTE!!!!!\n\n");
   }
   
}	
