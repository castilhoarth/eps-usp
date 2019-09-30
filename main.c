#include <stdio.h>

/* Definicao de constantes */

#define MAX 15
#define FALSE 0
#define TRUE 1

/* Programa 1a */
extern int remover1(int, int, int *);

/* Programa 1b */
extern int inserir1(int, int, int, int *);

/* Programa 2 */
extern int remover2(int, int, int, int, int *);

/* Programa 3 */
extern void inserir3 (int, int,  int, int *);

/* Programa 4 */
extern int tamanhoSegmentoHorizontal  (int, int *);

/* Programa 5 */
extern int ehSubsequencia  (int, int *, int, int *);

/* Programa 6 */
extern void remover6 (int, int, int, int, int *);

/* Programa 7 */
extern int onde(int, int, int *);

/* Programa 8 */
extern int localiza(int, int, int, int, int *);

/* Programa 9 */
extern int * subSequenciaMaxima(int, int *, int *);

int remover1(int k, int n, int *v)
{
	if(n==0) return FALSE;
	if (k < 0 || k >= n) return FALSE;
	int i;
	for(i = k; i < (n-1); i++){
		v[i] = v[i+1];
	}
	n = n-1;
	return n;
}

int inserir1(int x, int k, int n, int *v) {
	if(n == MAX) return FALSE;
	if (k < 0 || k >= n) return FALSE;
	int i;
	for (i = n; i > k; i--) {
		v[i] = v[i-1];
	}
	v[k] = x;
	n = n+1;
	return n;
}

int remover2(int k, int n,int ini,int fim, int *v) {
    int i;
    if(k >= fim || k < ini) return FALSE;
	if((fim - k) > (k - ini)) {
		for(i = k; i > ini; i--){
			v[i] = v[i-1];

        }
	} else {
		for(i = k; i < n - 1; i++){
			v[i] = v[i+1];
		}
     }
     n = (fim - ini) - 1;
    return n;
}
void inserir3(int x, int k, int n, int *v) {
    int i;
	if(n == MAX) return ;
	if (k < 0 || k >= n) return ;
	for (i = n; i > k; i--) {
		v[i] = v[i-1];
	}
	for (i = i; i < k; i++) {
		v[i] = v[i+1];
	}
	v[k+1] = x;
	n = n+1;
}
//4
int tamanhoSegmentoHorizontal(int n, int *v) {
    int i;
    int cont = 1;
    int def = 0;
    for(i = 0; i < n - 1; i++) {
        if(v[i] == v[i+1]) cont++;
        else{
            if(cont > def){
                def = cont;
                cont = 1;
            } else {
                cont = 1;
            }
        }
    }
    if(def == 1) return -1;
    return def;
}
//5
int ehSubsequencia  (int n1, int *v1, int n2, int *v2) {
    int i,j = 0;
    int indice =-1;
    int anterior = -1;
    int check = 0;

    for(i = 0; i < n1; i++) {
        for(j; j < n2; j++) {
            if (v1[i] == v2[j]){
                    indice = j;
                    if (indice <= anterior) return -1;
                    anterior = j;
                    check = 1;
                    break;
            } else check = 0;
        }
        if(check == 1) j+=1;
        else return FALSE;

    }
    return TRUE;
}
//6
void remover6(int y, int n, int ini, int fim, int* v) {
    int i;
    if(fim == ini) return ;
    if(v[fim-1] == y){
        for(i = fim-1; i < n-1; i++) {
            v[i] = v[i+1];
        }
        remover6(y,n,ini,fim-1,v);
    }
    else {
        remover6(y,n,ini,fim-1,v);
    }
}
//7
int onde(int x, int n, int *v) {
	if(n == 0) return -1;
	if(v[n-1] == x) {
		int i;
		int j;
		for(i = n-1; i >= 0; i--) {
			if(v[i] == x)  j = i;
		}
		return j+1;
	}
	else
		return onde(x,n-1,v);
}
//8
int localiza(int x,int n, int ini, int fim, int *v) {
	if(fim == ini) return -1;
	if(v[fim-1] == x) {
		int i;
		int j;
		for (i = fim-1; i >= ini; i--) {
			if(v[i] == x) j = i;
		}
		return j;
	} else {
		return localiza(x,n,ini,fim-1,v);
	}
}
//9
int* subSequenciaMaxima(int n, int* v, int* tamret) {

    int sizee = 0;
    *tamret = 0;
    int * resp = (int *)malloc(MAX * sizeof(int));
    if(n == 0 || n > MAX || n < 0) return resp;
	int GlobalMax = 0;
	int SufixMax = 0;
	int i;
	int j = 0;
	for(i = 0; i < n; i++) {
		if((v[i]+SufixMax) > GlobalMax) {
			SufixMax = SufixMax + v[i];
			GlobalMax = SufixMax;
			resp [sizee] = v[i];
			++sizee;
             *tamret = sizee;
		} else {
			if(v[i] + SufixMax > 0) {
                    SufixMax = SufixMax + v[i];
					resp[sizee] = v[i];
                    ++sizee;
                    *tamret = sizee;
			} else {
				SufixMax = 0;
				sizee = 0;
			}
		}
	}
	for(i = 0; i < n; i++) printf(" %d ",resp[i]);
    return resp;
}


int main(void)
{

int i, n,  res, acertos = 0;

/* Preparacao dos vetores para testes */
/* vetor de entrada: v???[] */
/* vetor de saida: b???[] */

/* Vetores programa 1a */
int v1a [] = {1,2,3,4,5,6,7,8,9,10,-1,-1,-1,-1,-1};
int b1a [] = {1,2,3,5,6,7,8,9,10};

/* Vetores programa 1b */
int v1b [] = {1,2,3,5,6,7,8,9,10,-1,-1,-1,-1,-1,-1};
int b1b [] = {1,2,3,5,6,3,7,8,9,10};

/* Vetores programa 2 */
int v2 [] = {1,2,3,5,6,3,7,8,9,10,-1,-1,-1,-1,-1};
int b2 [] = {1,2,2,3,6,3,7,8,9,10};

/* Vetores programa 3 */
int v3 [] = {1,2,3,6,3,7,8,9,10,-1,-1,-1,-1,-1,-1};
int b3 [] = {1,2,3,6,3,3,7,8,9,10};

/* Vetor programa 4 */

int v4 [] = {1,1,1,2,3,6,6,7,8,9,10,-1,-1,-1,-1};

/* Vetores programa 5 */

int v5a [] = {11,12,13,11,10,9,7,3,3,-1,-1,-1,-1,-1,-1};

int v5b [] = {12,13,10,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int v5c [] = {11,12,10,11,13,9,7,3,3,-1,-1,-1,-1,-1,-1};

/* Vetores programa 6 */

int v6 [] = {1,1,1,2,3,6,6,7,8,9,10,-1,-1,-1,-1};
int b6 [] = {1,2,3,6,6,7,8,9,10};

/* Vetor programa 7 */

 int v7 [] = {1,1,1,2,3,6,6,7,8,9,10,-1,-1,-1,-1};

/* Vetor programa 8 */

 int v8 [] = {1,1,1,2,3,6,6,7,7,9,10,-1,-1,-1,-1};

/* Vetores programa 9 */

int v9 [] = {11,12,10,11,13,9,7,3,3,-1,-1,-1,-1,-1,-1};
int b9 [] = {11,12,10,11,13,9,7,3,3};
int *pb9;
int tamb9;


/* Teste programa 1a */

n = 10;
res=FALSE;

n=remover1(3,n,v1a);
if(n == 9)
	{
	res = TRUE;
	for(i=0; i < n;++i)
		{
		if(v1a[i] != b1a[i])
			{
			res=FALSE;
			break;
			}
		}
	if(res)
		++acertos;
        printf("\n");
	}
if(res) printf("\nTeste 1a");
/* Teste programa 1b */


res=FALSE;

n = 9;
n = inserir1(3,5,n,v1b);
if(n == 10)
	{
	res = TRUE;
	for(i=0; i < n;++i)
		{
		if(v1b[i] != b1b[i])
			{
			res=FALSE;
			break;
			}
		}
	if(res)
		++acertos;
	}
if(res) printf("\nTeste 1b");
/* Teste programa 2 */

res=FALSE;
n = 10;
n=remover2(3,n,1,9,v2);
if(n == 7)
	{
	res = TRUE;
	for(i=0; i < 9;++i)
		{
		if(v2[i] != b2[i])
			{
			res=FALSE;
			break;
			}
		}
	if(res)
		++acertos;
	}

if(res) printf("\nTeste 2");

/* Teste programa 3 */

inserir3(3,4,9,v3);

if(v3[5] == 3) acertos++;
if(v3[5] == 3) printf("\nTeste 3");

/* Teste programa 4 */

if(tamanhoSegmentoHorizontal(11, v4) == 3) acertos++;
if(tamanhoSegmentoHorizontal(11, v4) == 3) printf("\nTeste 4");

/* teste programa 5 */

if(ehSubsequencia(4, v5b, 9,  v5a))
	acertos++;
if(ehSubsequencia(4, v5b, 9,  v5a)) printf("\nTeste 5");
printf("\n Numero de acertos at 5a %d",acertos);

if(!ehSubsequencia(4, v5b, 9,  v5c))
	acertos++;
if(ehSubsequencia(4, v5b, 9,  v5c)) printf("\nTeste 5b");
printf("\n Numero de acertos at 5b %d",acertos);
/* teste programa 6 */

remover6(1,11,1,6,v6);

if(v6[0]==b6[0] && v6[1] != 1 && v6[2] != 1)
	acertos++;
if(v6[0]==b6[0] && v6[1] != 1 && v6[2] != 1)printf("\nTeste 6");
printf("\n Numero de acertos at 6 %d",acertos);
/* Teste programa 7 */

if(onde(6,11,v7) == 6) acertos++;
if(onde(6,11,v7) == 6) printf("\nTeste 7");
printf("\n Numero de acertos at 7 %d",acertos);
/* Teste programa 8 */

if(localiza(6,11,7,11,v8) == -1) acertos++;
if(localiza(6,11,7,11,v8) == -1) printf("\nTeste 8");
printf("\n Numero de acertos at 8 %d",acertos);
/* Teste programa 9 */

pb9 = (int *) subSequenciaMaxima(9,v9,&tamb9);

res=FALSE;
if(tamb9 == 9)
	{
	res=TRUE;
	for(i=0; i < tamb9 ; ++i)
		if(pb9[i] != b9[i]){
			res=FALSE;
			break;
		}
}
if(res) acertos++;


printf("Acertos: %d\n",acertos);
}
