
#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>
#include <malloc.h>
#include <string.h>
#include <iostream>

using namespace std;

// elementos da matriz esparsa (use tambem se quiser criar listas auxiliares)
typedef struct estr {
        int info;
	    int lin;
	    int col;
        struct estr *proxC;   // ponteiro para a direita
        struct estr *proxL;   // ponteiro para baixo
} NO;

// matriz 10 x 10 (a linha e coluna 0 são desprezadas)
typedef struct {
	NO* LIN[11];
	NO* COL[11];
} LISTASCR;

//inicialização
void inicializarMatriz (LISTASCR* m)
{
    int i;
    for (i = 1; i < 11; i++)
        m->LIN[i] = NULL;

    for (i = 1; i < 11; i++)
        m->COL[i] = NULL;
}

//procurar
NO* busca(LISTASCR* m, int i, int j, NO* *acima, NO* *esq) {
    *acima = NULL;
    NO * p = m->COL[j];
    while (p) {
        if (p->lin >= i) break;
        *acima = p;
        p = p->proxL;
    }
    *esq = NULL;
    p = m->LIN[i];
    while (p) {
        if (p->col >= j) break;
        *esq = p;
        p = p->proxC;
    }
  //  if (esq.proxC.col != j || acima.proxL.lin != i) 
        p = NULL;
    return p;
}

//inserir
void inserir (LISTASCR *m, int i, int j, int ch) {
    NO *esq;
    NO *acima;
    NO *atual = busca(m, i, j, &acima, &esq);

    if (!atual)
    {
        NO* novo = (NO *)malloc(sizeof(NO));
        novo->info = ch;
        novo->col = j;
        novo->lin = i;
        if (esq)
        {
            novo->proxC = esq->proxC;
            esq->proxC = novo;
        }
        else
        {
            novo->proxC = m->LIN[i];
            m->LIN[i] = novo;
        }

        if (acima)
        {
            novo->proxL = acima->proxL;
            acima->proxL = novo; //proxl aponta para um NÓ
        }
        else
        {
            novo->proxL = m->COL[j];
            m->COL[j] = novo;
        }
    }
}

void exibirLista(NO* p) {
    cout << "Exibindo lista"<< endl;
    while (p) {
        printf("%d ",p->info);
        cout << endl;
        p = p->proxL;
     }
}

void substituir (LISTASCR* m, int i, int j) {

    int contador;
	int ok;
	
    if (i > j)
        contador = j;
    else
        contador = i;

    //Percorrer Linha
    NO* p1 = m->LIN[i];
    NO* aux1 = p1;
    
    //Inicio1
	NO* inicio1 = (NO*) malloc(sizeof(NO));
	inicio1->info = p1->info;
	ok = 1;

    while (p1 && p1->col < contador) {
		if (ok > 1)
			{
			    NO* novo1 = (NO*) malloc(sizeof(NO));
                novo1->info = p1->info;
                novo1->proxC = NULL;
		        aux1->proxC = novo1;
			    aux1 = novo1;
            } else aux1 = inicio1;
            p1 = p1->proxC;
            ok++;   
    }

	//Percorrer coluna
	NO* p2 = m->COL[j];		
    NO* aux2 = p2;
    
    //Inicio2
    NO* inicio2 = (NO*) malloc(sizeof(NO));
    inicio2->info = p2->info;
	ok = 1;

	while (p2 && p2->lin < contador) 
    {
		if (ok > 1)
		{
		    NO* novo2 = (NO*) malloc(sizeof(NO));
            novo2->info = p2->info;
            novo2->proxL = NULL;
	        aux2->proxL = novo2;
		    aux2 = novo2;
        } else aux2 = inicio2;
        
    	p2 = p2->proxL;
        ok++;
	}
    
   	NO* q2 = inicio2; //Variável de controle do Percorrer coluna
	exibirLista (q2);
    p1 = m->LIN[i];

    //Pegando Coluna e colando na linha
	while (q2 && p1->col < contador) 
    { 
    	cout << "INFO: "<< q2->info << endl;
	    p1->info = 777;
    	q2 = q2->proxL;
    	p1 = p1->proxC;
    }
    
    NO* q1 = inicio1; //Variável de controle do Percorrer linha
    p2 = m->COL[i];

	while (q1 && p2->lin < contador) 
    { //Linha
		p2->info = 777;//q->info
        cout << "INFO: "<< q->info << endl;
		q = q->proxC;
		p2 = p->proxC;
    } 
}
 

void imprimir(LISTASCR* m) {
    printf("Matriz\n");
    for (int i = 1; i < 11; i++) {
        NO* atual = m->LIN[i];
        for (int j = 1; j < 11; j++) {
            if (atual) {
                if (atual->lin == i && atual->col == j) {
                    printf("%d ", atual->info);
                    atual = atual->proxC;
                } else {
                    printf("0 ");
                }
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int main () {
    LISTASCR m;
    inicializarMatriz (&m);
    inserir (&m, 1, 1, 1);
    inserir (&m, 1, 3, 9);
    inserir (&m, 2, 2, 2);
    inserir (&m, 2, 3, 10);
    inserir (&m, 2, 5, 7);
    inserir (&m, 3, 2, 3);
    inserir (&m, 3, 5, 6);
    inserir (&m, 4, 2, 11);
    inserir (&m, 4, 3, 4);
    inserir (&m, 4, 4, 6);
    inserir (&m, 5, 5, 8);
    
    imprimir (&m);
    substituir (&m, 4, 3);
    imprimir (&m);
    
    return 0;
}
