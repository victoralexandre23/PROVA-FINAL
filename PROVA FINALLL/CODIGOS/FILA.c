#include<stdio.h>
#include<stdlib.h>
#define max 5
int rear=-1,front=-1;
int queue[max];

void insert();
int delete();
void display();

main()
{
    int w,num;
    while(1)
    {
        printf("FILA");
        printf("\n1. Inserir");
        printf("\n2. Deletar");
        printf("\n3. Mostrar fila");
        printf("\n4. Sair");
        printf("\nEscolha uma opcao para enfilerar :");
        scanf("%d",&w);
        if(w==1)
            insert();
        else if(w==2)
            num=delete();
        else if(w==3)
            display();
        else if(w==4)
            exit(1);
        else printf("\nEscolha invalida!!");

    }

}

void insert()
{
    int num;
    if(rear==max-1){
        printf("\nFila cheia! !\n");
        return;
    }
    printf("\nEscolha um numero a ser inserido: ");
    scanf("%d",&num);
    if(front==-1)
        front=front+1;

    rear=rear+1;
        queue[rear]=num;

}

int delete()
{
    int num;
    if(front==-1 || front==rear+1)
    {
        printf("\nFila vazia!\n");
        return 0;
    }
    num=queue[front];
    printf("\n%d foi deletado.\n",num);
    front=front+1;
}

void display()
{
    int i;
    if(front==-1 || front==rear+1)
    {
        printf("\nFila vazia, nada para mostrar agora.");
        return;
    }
    printf("\n\n");
    for(i=front;i<=rear;i++)
        printf("%d\t",queue[i]);
        printf("\n");
}
