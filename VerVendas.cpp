#include<stdio.h>
#include<stdlib.h>
#include<math.h>


struct Vendas{
    int Cod, Qtde;
    double PrecUnit;
};

int main(){
	int A, B;
	double C, PrecoFinal = 0, Valor;
	int i;
	int Codigo = 0;
	int TamV;
	Vendas *V = NULL;
	FILE *Arq;
	
	Arq = fopen("vendas.txt", "r");
    TamV = 0;
        while(fscanf(Arq, "%d;%d;%lf\n", &A, &B, &C) != EOF){
            TamV++;
            V = (Vendas *)realloc(V, sizeof(Vendas) * TamV);
            V[TamV - 1].Cod = A;
            V[TamV - 1].Qtde = B;
            V[TamV - 1].PrecUnit = C;
        }
	fclose(Arq);
	
	do{
		printf("Digite o codigo: ");
		scanf("%d", &Codigo);
		
		if(Codigo != 0){
			while(Codigo < 10000 || Codigo > 21000){
			printf("%d Codigo invalido (deve ser entre  10000 e 21000)\n\n", Codigo);
			printf("Digite o codigo: ");
			scanf("%d", &Codigo);
			}
		}
		Valor = 0;
		if(Codigo != 0){
			for(i = 0; i < TamV; i++){
			if(V[i].Cod == Codigo){
				Valor = V[i].PrecUnit;
				PrecoFinal = PrecoFinal + Valor;
			}
		}
		printf("Total vendido do produto %d = R$ %.2lf\n\n", Codigo, PrecoFinal);
		}
		if(Codigo == 0){
			printf("Fim do Programa");
		}
	}while(Codigo != 0);
	
	free(V);
	return 0;	
}
