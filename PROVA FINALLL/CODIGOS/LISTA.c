#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int num;
	struct node *prox;
} node;
int tam;
node *alocar(){
	node *novo = (node *) malloc(sizeof(node));
	if (!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}
	return novo;
}
void inicia(node *LISTA){
	LISTA->prox = NULL;
	tam = 0;
}
void AdicionarInicio(node *LISTA){
	node *novo = alocar();

	novo->prox = LISTA->prox;
	LISTA->prox = novo;
	printf("Novo elemento: ");
	scanf("%d", &novo->num);

	tam++;
}
void AdicionarFim(node *LISTA){
	node *novo = alocar();

	novo->prox = NULL;
	if(LISTA->prox == NULL)
		LISTA->prox = novo;
	else{
		node *tmp = LISTA->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	printf("Novo elemento: ");
	scanf("%d", &novo->num);

	tam++;
}
void AdicionarN(node *LISTA){
	int pos, count;

	printf("Qual posicao desejas inserir? Escolha de [1 ate %d]: ", tam);
	scanf("%d", &pos);

	if(pos > 0 && pos <= tam){
		if(pos == 1){
			AdicionarInicio(LISTA);
		}
		else{
			node *atual = LISTA->prox, *anterior = LISTA;
			node *novo = alocar();
			for(count=1; count < pos; count++){
				anterior = atual; atual = atual->prox;
			}
			anterior->prox = novo;
			novo->prox = atual;
			printf("Novo elemento: ");
			scanf("%d", &novo->num);
			tam++;
		}
	}
	else{
		printf("Elemento invalido!\n");
	}
}
void ExibirLista(node *LISTA){
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		node *tmp;
		for (tmp = LISTA->prox; tmp != NULL; tmp = tmp->prox)
		printf("%d\n", tmp->num);
	}
	printf("Tamanho da lista: %d\n", tam);
	printf("\n\n");
	system("PAUSE");
}
void ExibirElementoN(node *LISTA){
	int pos, count;

	printf("Qual elemento desejas consultar? Escolha de [1 ate %d]: ", tam);
	printf("\n\n");
	scanf("%d",&pos);

	if(pos>0 && pos <= tam){
		node *atual = LISTA->prox, *anterior = LISTA;

		for(count=1; count < pos; count++){
			anterior = atual;
			atual = atual->prox;
		}
		system("CLS");
		printf("\n\n");
		printf("Valor do elemento %d e: %d\n",pos, atual->num);
		printf("\n\n");
		system("PAUSE");
	}
}
void RemoverInicio(node *LISTA){
	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		node *tmp = LISTA->prox;
		LISTA->prox = tmp->prox;
		printf("NO %d removido com sucesso!",tmp->num);
		free(tmp);
		tam--;
	}
	printf("\n\n");
	system("PAUSE");
}
void RemoverFim(node *LISTA){
	node *aux;

	if (LISTA->prox == NULL)
		printf("Lista vazia!");
	else{
		node *ultimo = LISTA->prox, *penultimo = LISTA;
		while(ultimo->prox != NULL){
			penultimo = ultimo;
			ultimo = ultimo->prox;
			tam--;
		}
		penultimo->prox = NULL;
		printf("NO %d removido com sucesso!",ultimo->num);
	}
	printf("\n\n");
	system("PAUSE");
}
void RetirarN(node *LISTA){
	int pos, count;

	printf("Qual posição desejas retirar? Escolha de [1 ate %d]: ", tam);
	scanf("%d",&pos);

	if(pos>0 && pos <= tam){
		if(pos==1){
			return RemoverInicio(LISTA);
		}
		else{
			node *atual = LISTA->prox, *anterior = LISTA;

			for(count=1; count < pos; count++){
				anterior = atual;
				atual = atual->prox;
			}

			anterior->prox=atual->prox;
			tam--;
			printf("Elemento %d removido com sucesso!",atual->num);
			system("PAUSE");
		}
	}
}
void Liberar(node *LISTA){
	node *atual = LISTA->prox, *proximo;
	while(atual != NULL){
		proximo = atual->prox;
		free(atual);
		atual = proximo;
	}

	inicia(LISTA);
}
int main(void){

	node *LISTA = alocar();
	inicia(LISTA);
	int opt;

	do{
		system("CLS");
		printf(" LISTA\n");

		printf(" \n1-adicionar no inicio\n");

		printf("\n 2-adicionar no fim\n");

		printf("\n 3-adicionar em um ponto especifico\n");

		printf("\n 4-Remover do inicio\n");

		printf("\n 5-Remover do final\n");

		printf("\n 6-Remover de um ponto especifico\n");

		printf("\n 7-mostrar elementos da lista\n");

		printf("\n 8-Consultar elemento \n");

		printf("\n 9-Liberar os elementos da lista \n");

		printf("\n 0-Sair \n");

		printf("Escolha a opcao: ");
		scanf("%d", &opt);
		system("CLS");

		switch(opt)
		{
			case 1:
				AdicionarInicio(LISTA);
				break;
			case 2:
				AdicionarFim(LISTA);
				break;
			case 3:
				AdicionarN(LISTA);
				break;
			case 4:
				RemoverInicio(LISTA);
				break;
			case 5:
				RemoverFim(LISTA);
				break;
			case 6:
				RetirarN(LISTA);
				break;
			case 7:
				ExibirLista(LISTA);
				break;
			case 8:
				ExibirElementoN(LISTA);
				break;
			case 9:
				Liberar(LISTA);
				ExibirLista(LISTA);
				break;
			case 0:
				Liberar(LISTA);
				break;
			default:
				printf("Comando invalido\n\n");
		}
	}while(opt <= 9 && opt != 0);
	Liberar(LISTA);
	return 0;
}
