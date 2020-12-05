//--------------------------------------------------------------
// NOMES DOS RESPONSÁVEIS: Arthur de Castilho Nascimento & Gustavo Macedo Ribeiro
//--------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <ctype.h>
#include <iostream>

using namespace std;

char* nroUSP1() {
    return("11270674");
}

// ######### ESCREVA O NROUSP DO SEGUNDO INTEGRANTE AQUI (OU DEIXE COM ZERO)
char* nroUSP2() {
    return("");
}


typedef struct estr
{
	int pk;
	char info;
	struct estr *prox;
} NO;

typedef struct lista
{
	NO* inicio;
} LISTA;

//Inicializar

void inicializar(LISTA *l)
{
	l->inicio = NULL;
}

// Último elemento

NO* ultimoElemento(LISTA* l)
{
	NO* p = l->inicio;
	if(p)
	{
		while(p->prox)
		{
			p = p->prox;
		}
	}
	return (p);
}

//Exibir
void exibir(NO* p)
{
	while(p)
	{
		cout << p->info;
		p = p->prox;
	}

}


void anexar(int ch, LISTA* l, char charr)
{
	NO* novo;
	NO* ant;
	ant = ultimoElemento(l);
	novo = (NO*) malloc(sizeof(NO));
	novo->pk = ch;
	novo->info = charr;
	novo->prox = NULL;
	if(!ant) l->inicio = novo;
	else ant->prox = novo;
}



//------------------------------------------
// O EP consiste em implementar esta funcao
// e outras funcoes auxiliares que esta
// necessitar
//------------------------------------------

NO* decodificar(char* entrada)
{
	LISTA l;
	inicializar(&l);

	int n = strlen(entrada);
	if(n <= 0) return NULL;
	NO* resp;
	resp = l.inicio;
	int indice = 0;

	// seu codigo AQUI
	for (int i = 0; i < n; i++)
	{
		if (entrada[i] >= 48 && entrada[i] <= 57)
		{

			int x = (int)entrada[i] - 48;//Valor do número
			for (int j = 0; j < x; j++)
			{
				anexar(indice, &l, entrada[i + 1]);
			}
			i++;
		}
		else
		{
			anexar(indice, &l, entrada[i]);
			indice += 1;
		}
	}
	resp = l.inicio;
	return resp;
}

int main()
{
	NO* p;
	char entrada[] = "3a";
	NO* teste = decodificar(entrada);
	exibir(teste);
}
