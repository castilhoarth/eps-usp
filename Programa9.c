#include <stdio.h>

/* Definicao de constantes */

#define MAX 15
#define FALSE 0
#define TRUE 1

/* Programa 9 */
extern int * subSequenciaMaxima(int, int *, int *);

int* subSequenciaMaxima*(int n, int* v, int* tamret) {
	int GlobalMax = 0;
	int SufixMax = 0;
	int i;
	for(i = 0; i < n; i++) {
		if((v[i]+SufixMax) > GlobalMax) {
			SufixMax = SufixMax + v[i];
			GlobalMax = SufixMax;
		} else
		{
			if(v[i]+SufixMax > 0) {
				SufixMax = SufixMax + v[i];
			} else {
				SufixMax = 0;
			}
		}
	}
    return 0;
}
int main(void)
{

int i, n,  res, acertos = 0;

/* Vetores programa 9 */

int v9 [] = {11,12,10,11,13,9,7,3,3,-1,-1,-1,-1,-1,-1};
int b9 [] = {11,12,10,11,13,9,7,3,3};
int *pb9;
int tamb9;

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
}
