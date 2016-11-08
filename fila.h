//Função básicas para manipulação de fila
#include <stdio.h>
#include <stdlib.h>
struct no
{
	int dado;															//valor do nó
	struct no *prox;													//endereço do nó anterior
};

typedef struct
{
	struct no *inicio;													//indicação do começo da fila
	struct no *fim;														//indicação do fim da fila
}fila;

void create (fila *q);
int isEmpty (fila q);
int insert (fila *q, int d);
int remove (fila *q, int *d);

void create (fila *q)													//Cria uma fila
{
	q->inicio=NULL;						
	q->fim=NULL;
}																		//inicio e fim não aponta para nada

int insert (fila *q, int d)												//insere um valor na fila
{
	struct no *aux;
	aux = (struct no *) malloc (sizeof(struct no));						//aloca dinamicamente um nó a ser inserido na pilha
	if (aux==NULL)
		retur FALSE;													//analisa se foi criado um nó
	aux->dado=d;														//insere o valor dado no nó
	aux->prox=NULL;														//limpa o endereço indicado no nó
	if (q->inicio==NULL)
		q->inicio=aux;													//se não houver nó inicial, o novo nó será o inicio
	if (q->fim!=NULL)
		q->fim->prox=aux;												//se o fim não for nulo, o fim recebe o endereço do auxiliar
	q->fim=aux;															//fim recebe o endereço do auxiliar 
	return TRUE;
}

int insert (fila *q, int d)												//Inserção de um valor na fila
{
	struc no *aux;
	aux = (struct no *)malloc(sizeof(struct no));						//alocaçãodinamica do nó
	if (aux==NULL)
		return FALSE;													//verifica a alocação do nó
	aux->dado=d;														//atribui valor ao nó
	aux->prox=NULL;														//aribui nulo ao próximo do nó
	if (q->inicio==NULL)
		q->inicio=aux;													//se inicio for nulo, inicio recebe auxiliar
	if (q->fim!=NULL)
		q->fim->prox=aux;												//se fim não for nulo, recebe auxiliar
	q->fim=aux;															//fimr ecebe auxiliar
	return TRUE;
}

int remove (fila *q, int *d)											//Remove um valor da fila
{
	struct no *aux;
	if (q->inicio==NULL)
		return FALSE;													//Se o inicio da fila for nulo retorna falso
	aux=q->inicio;														//o nó recebe o inicio da fila
	q->inicio=aux->prox;												//o inicio agora é o próximo da fila
	*d=aux->dado;														//retorna o dado apagado
	free(aux);															//livera o espaço do nó
	return TRUE;														//retorna verdadeiro
}
