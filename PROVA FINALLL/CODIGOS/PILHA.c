#include <stdio.h>
#include <stdlib.h>

typedef struct no{

	int valor;
	struct no* prox;
}no;

typedef no pilha;

void empilhar(pilha** p, int numero){

	pilha* novo = (pilha*)malloc(sizeof(pilha));

	if(*p == NULL){
		*p = novo;
		(*p)->valor = numero;
		(*p)->prox = NULL;

	}

	else{

	pilha* percorre;

	percorre = *p;


		while(percorre->prox != NULL ){

			percorre = percorre -> prox;
		}

	percorre -> prox = novo;
	novo -> valor = numero;
	novo -> prox = NULL;


	}


}
void desempilhar(pilha** p){
	pilha* percorre;
	percorre = *p;

	if(*p == NULL) printf("A Pilha está vazia\n");


	else{

		if(percorre->prox == NULL) *p = NULL;
		else{

			while(percorre->prox->prox != NULL){
				percorre = percorre->prox;
			}

			percorre ->prox = NULL;

		}

	}
}

void imprimir(pilha* p){

	pilha* percorre;

	percorre = p;

	if(p == NULL) printf("A Pilha se encontra vazia!\n");
	else{
		while(percorre != NULL){

			printf("Elemento: %d \n", percorre->valor);

			percorre = percorre -> prox;

		}
	}
}

void esvaziarpilha(pilha **p){

	pilha* aux;
	aux = *p;

	while(aux != NULL){
		*p = aux->prox;
		free(aux);
		aux = *p;

	}


}


int main(){


	pilha* p = NULL;

	int elemento, opcao;

	while(opcao != 0){

	system("cls");

		printf("PILHA\n0 - Sair\n");
		printf("1 - Empilhar\n");
		printf("2 - Desempilhar\n");
		printf("3 - Esvaziar\n");
		printf("4 - ver pilha\n");

		scanf("%d", &opcao);


		switch(opcao){

			case 1:

				printf("Qual elemento você deseja empilhar?\n");
					scanf("%d", &elemento);

				empilhar(&p, elemento);

				printf("Vamos imprimir agora após ter empilhado\n");

				imprimir(p);

				getchar();
				getchar();


			break;



			case 2:

				printf("desempilhando...\n");

				desempilhar(&p);

				printf("\n");

				printf("imprimindo...\n");
				imprimir(p);


				getchar();
				getchar();
			break;


			case 3:


				printf("Esvaziando...\n");

				esvaziarpilha(&p);

				printf("Imprimindo...\n");

				imprimir(p);

				getchar();
				getchar();
			break;

			case 4:

				printf("Imprimindo...\n");
				imprimir(p);

				getchar();
				getchar();

			break;


		}







	}

}
