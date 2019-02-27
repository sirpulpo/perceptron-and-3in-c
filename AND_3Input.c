#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
# define Tit 7 // 2^(3) = 8 iteraciones.
# define Tin 2 // 3 entradas.

void f_Vista();
float f_Aprendizaje(float [Tin]);
void f_Ejecucion(float [Tin], float);
void f_again(int *);

int main()
{
	int again=0	;
	float Vw[Tin], thr = 0.0;
	f_Vista();
	do{
		thr = f_Aprendizaje(Vw);
		f_again(&again);
	}while(again == 1);
}

void f_Vista()
{
	system("color f4");
	printf("\n\t\tEntrena un perceptron para simular la");
	printf("\n\t\tfuncion logica AND de 3 entradas.");
	printf("\n\t\t_____________________________________\n\n");
	printf("\t\t\20 Aguirre Gil Victor Daniel\n\n");
	printf("\t\t\20 Estrada Barrientos Alexis Jafet\n\n\n");
	system("pause");
	system("cls");
}

float f_Aprendizaje(float Vw[Tin])
{
	int i = 0, j = 0, aux = 0, y = 0, dcado = 0, bndr = 0, epoch = 0, Vent[Tin];
	float thr = 0.0, a = 0.0, resp = 0.0, error = 0.0;
	printf("Ingrese el valor del umbral que desee: ");
	scanf("%f", &thr);
	printf("Ingrese el valor de la intencidad de aprendizaje que desee: ");
	scanf("%f", &a);
	printf("Carga el vector de pesos.");
	for(i = 0; i <= Tin; i++)
	{
		printf("\nValor del peso w_%i = ",i+1);
		scanf("%f",&Vw[i]);
	}
	system("pause");
	system("cls"); // hasta aquí se carga el umbral, el aprendizaje y el vector de pesos.
	printf("\n thr = %.2f,",thr);
	printf("\ta = %.2f\n |",a);
	for(i = 0; i <= Tin; i++)
	{
		printf(" w_%i = %.2f |", (i+1), Vw[i]);
	} // Imprime los valores con los que trabajará.
	epoch = 1;
	do{
		bndr = 0;
		printf("\n\n\t\t ----- Epoca: %i -----\n", epoch);
		printf("\n| x1, x2, x3 | f(x) |  Salidas   |Error|  w1,   w2,   w3,  |");
		for(i = 0; i <= Tit; i++)
		{
			aux = i;
			// 1° f(x).
			for(j = Tin; j >= 0; j--) // cargar vector de entrenamiento con el numero binario correspondiente.
			{
				Vent[j] = (aux % 2);
				aux = (int)(aux / 2);
			}
			printf("\n|");
			resp = 0;
			for(j = 0; j <= Tin; j++)
			{
				resp = resp + (Vent[j] * Vw[j]); // calcula la f(x) función de entrada.
				printf(" %i", Vent[j]); // imprime el vector de entrada.
				if(j != Tin)
					printf(" ,");
				if(j == Tin)
					printf("  ");
			}
			printf("| %.2f ", resp);
			// 2° función de activación.
			y = 0;
			if(resp > thr)
				y = 1;
			// 3° evaluar si hay error comparando salidas.
			dcado = 0;
			if(i == 7)
				dcado = 1;
			printf("|Esp-%i|Real-%i", dcado, y);
			// 4° si hay error f_Rosenblatt(), si no seguir.
			error = 0.0;
			if(dcado != y)
			{
				bndr = 1;
				if(y < dcado)
					error = 1.0;
				else
					error = -1.0;
				for(j = 0; j <= Tit; j++)
				{
					Vw[j] = Vw[j] + (error * a * Vent[j]);
				}
			}
			if( error < 0)
			{
				printf("|%.1f ", error);
				printf("|");
			}else
			{
				printf("| %.1f ", error);
				printf("|");
			}
			
			for(j = 0; j <= Tin; j++)
			{
				printf(" %.2f", Vw[j]); // imprime el vector de pesos.
				if(j != Tin)
					printf(",");
				if(j == Tin)
					printf("  ");
			}
			printf("|");
		}
		epoch++;
		if(epoch > 7)
			bndr = 0;
	}while(bndr == 1);
	printf("\n\nPodemos ver que el aprendizaje converge ");
	printf("puesto que no presenta error en la ultima iteracion.\n\n");
	system("pause");
	return thr;
}

void f_Ejecucion(float Vw[Tin], float thr)
{
	int Vx[Tin], i = 0, y = 0;
	float resp = 0.0;
	printf("\nIntroduzca los valores de entrada:\n");
	for(i = 0; i <= Tin; i++)
	{
		printf(" x%i = ",i+1);
		scanf("%i",&Vx[i]);
	}
	resp = 0.0;
	for(i = 0; i <= Tin; i++)
	{
		resp = resp + (Vw[i] * Vx [i]);
	}
	printf("  f(x) = %.2f", resp);
	y = 0;
	if(resp > thr)
		y = 1;
	printf("\n La salida es: y = %i", y);
	
}

void f_again(int *again)
{
	do{
		printf("\n\n\nDesea repetir el algoritmo: ");
		printf("\n\n1) Si.");
		printf("\n\n2) No.");
		scanf("%d",again);
	}while(*again < 1 || *again > 2);
}
