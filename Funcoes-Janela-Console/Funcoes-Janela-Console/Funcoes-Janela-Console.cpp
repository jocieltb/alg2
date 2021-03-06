// Funcoes-Janela-Console.cpp : Este arquivo contém funções para printar linhas com caracteres especiais
// formando uma janela em ambiente Console.

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include "string.h"

// Manipular posição do Cursor na tela
void gotoxy(int x, int y) {
	COORD c = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

// Centralizar texto na tela (Usar o retorno no parametro X da gotoxy
int centralizar(int t, char* texto)
{
	int ttexto = strlen(texto);
	int centro;

	centro = 2 + (t / 2) - (ttexto / 2);

	return centro;
}

//Inserir linha dupla superior
void LDSup(int t)
{
	int i;
	printf(" ");
	printf("%c", 201);
	for (i = 0; i < t; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 187);
	printf("\n");
}
//Inserir Linha dupla inferior
void LDInf(int t)
{
	int i;
	printf(" ");
	printf("%c", 200);
	for (i = 0; i < t; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 188);
	printf("\n");
}

//Linha dupla central com divisor inferior
void LDCentDI(int t, int d)
{
	int i = 0;
	printf(" ");
	printf("%c", 204);
	for (i = 0; i < d; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 203);
	for (i = 0; i < (t - d - 1); i++)
	{
		printf("%c", 205);
	}
	printf("%c", 185);
	printf("\n");
}
//Linha dupla central com divisor superior
void LDCentDS(int t, int d)
{
	int i = 0;
	printf(" ");
	printf("%c", 204);
	for (i = 0; i < d; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 202);
	for (i = 0; i < (t - d - 1); i++)
	{
		printf("%c", 205);
	}
	printf("%c", 185);
	printf("\n");
}
//Linha dupla inteira com divisor
void LDIntD(int t, int n, int d)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		printf(" ");
		printf("%c", 186);
		for (j = 0; j < d; j++)
		{
			printf(" ");
		}
		printf("%c", 186);
		for (j = 0; j < (t - d - 1); j++)
		{
			printf(" ");
		}
		printf("%c", 186);
		printf("\n");
	}
}

// Linha dupla inferior com divisor
void LDInfD(int t, int d)
{
	int i = 0;
	printf(" ");
	printf("%c", 200);
	for (i = 0; i < d; i++)
	{
		printf("%c", 205);
	}
	printf("%c", 202);
	for (i = 0; i < (t - d - 1); i++)
	{
		printf("%c", 205);
	}
	printf("%c", 188);
	printf("\n");
}



//Inserir Linha inteira 
void LDInt(int t, int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		printf(" ");
		printf("%c", 186);
		for (j = 0; j < t; j++)
		{
			printf(" ");
		}
		printf("%c", 186);
		printf("\n");
	}
}
//Inserir Linha central
void LDCent(int t)
{
	int i;
	printf(" ");
	printf("%c", 204);
	for (i = 0; i < t; i++)
	{
		printf("%c", 205);
	}

	printf("%c", 185);
	printf("\n");
}

void MT1(int th, int tv, int tc)
{

	LDSup(th);			//Linha superior
	LDInt(th, 1);		//linha inteira (1 - quantidade de linhas)
	LDCent(th);			//divisão horizontal (linha dupla)
	LDInt(th, tv - 6);	//linha inteira (th - tamanho horizontal, tv - tamanho vertical (quantidades de linhas)
	LDCent(th);
	LDInt(th, 1);
	LDInf(th);			//linha inferior

}

void MT2(int th, int tv, int tc)
{

	LDSup(th);			//Linha superior
	LDInt(th, 1);		//linha inteira (1 - quantidade de linhas)
	LDCent(th);			//divisão horizontal (linha dupla)
	LDInt(th, tv - 6);	//linha inteira (th - tamanho horizontal, tv - tamanho vertical (quantidades de linhas)
	LDCentDI(th, tc);	//linha dupla central com divisor inferior
	LDIntD(th, 1, tc);	//linha dupla inteira com divisor
	LDInfD(th, tc);		//linha dupla inferior com divisor

}

void MT3(int th, int tv, int tc)
{
	LDSup(th);				//Linha superior
	LDInt(th, 1);			//linha inteira (1 - quantidade de linhas)
	LDCentDI(th, tc);		//linha dupla central com divisor inferior
	LDIntD(th, tv - 6, tc);	//linha dupla inteira com divisor
	LDCentDS(th, tc);		//linha dupla central com divisor inferior
	LDInt(th, 1);			//linha dupla inteira com divisor
	LDInf(th);				//linha dupla inferior com divisor
}

int main()
{
	//Parametros de Configuração ------------------------------------------------	
	int th = 114;		// tamanho da janela na horizontal						
	int tv = 35;		// Tamanho da janela na vertical							
	int tc = 70;		// tamanho da coluna esquerda 							
	MT3(th, tv, tc);    //Modelos de tela (MT1 a MT3)								
	char texto[] = "NOME DA JANELA"; //Nome da janela ou programa
	gotoxy(th - 19, tv - 2); printf("by Jociel T. Barbosa");		
	//---------------------------------------------------------------------------

	//Codigos que não devem ser alterados ---------------------------------------
	int ct = centralizar(th, texto); //Centraliza o nome da janela
	gotoxy(ct, 1); printf("%s", texto);
	//---------------------------------------------------------------------------
	
	// Inicio do codigo da aplicação

	// Codigo exemplo;

	gotoxy(75, 4); printf("Texto Exemplo 1:");
	gotoxy(75, 6); printf("Texto Exemplo 2:");
	gotoxy(75, 8); printf("Texto Exemplo 3:");
	gotoxy(75, 10); printf("Texto Exemplo 4:");

	gotoxy(4, 4); printf("Texto Exemplo 1:");
	gotoxy(4, 6); printf("Texto Exemplo 2:");
	gotoxy(4, 8); printf("Texto Exemplo 3:");
	gotoxy(4, 10); printf("Texto Exemplo 4:");
	gotoxy(4, 10); printf("Texto Exemplo 5:");

	//fim codigo da aplicação
	
	// Codigo que não deve ser alterado -----------------------------------------	
	gotoxy(1, tv + 1);
	printf("\n");
	system("pause");
	return 0;
	//---------------------------------------------------------------------------
}