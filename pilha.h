#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

struct no
{
	int dado;			//valor armazenado
	struct no *prox;
};

typedef struct
{
	struct no *topo;
}pilha;

void create(pilha *s)
{
	s->topo=NULL;
}

int push(pilha *s, int d)		//garda na pilha o 'd'
{
	struct no *aux;
	aux=(struct no*)malloc(sizeof(struct no));
	if(aux==NULL) return (FALSE);
	aux->dado = d;				// se o armazenado ñ for numero = não funciona
	aux->prox = s->topo;
	s->topo=aux;
	return(TRUE);
}

int pop(pilha *s, int *d)		// tipo *d
{
	struct no *aux;
	if(s->topo==NULL) return (FALSE);
	aux = s->topo;
	s->topo = (s->topo)->prox;
	*d = aux->dado;
	free(aux);
	return(TRUE);
}

int isEmpty (pilha *s)
{
	if (s->topo == NULL)
		return TRUE;
	return FALSE;
}

//================================Segunda pilha.h=======================
int contaNos(pilha s)
{
   struct no *aux = s.topo;
   int c=0;
   if(aux==NULL) return 0;
   do
   {
   	   c++;
   	   aux = aux->prox;
   }
   while(aux!=NULL);
   return c;
}

int somaNos(pilha s)
{
   struct no *aux = s.topo;
   int soma=0;
   if(aux==NULL) return 0;
   do
   {
       soma = soma + aux->dado;   	   
       aux = aux->prox;
   }while(aux!=NULL);
   return soma;
}

int ultimoValor(pilha s)
{
   struct no *aux = s.topo;
   int c=0;
   if(aux==NULL) return 0;
   do
   {
   	   c++;
   	   aux = aux->prox;
   }
   while(aux->prox!=NULL);
   return aux->dado;
}

int penultimoValor(pilha s)
{
   struct no *aux = s.topo;
   int c=0;
   if(aux==NULL) return 0;
   do
   {
   	   c++;
   	   aux = aux->prox;
   }
   while(aux->prox->prox!=NULL);
   return aux->dado;
}

int primeiroValor(pilha s)
{
   struct no *aux = s.topo;
   if(aux==NULL) return 0;
   else 
   return aux->dado;
}

int segundoValor(pilha s)
{
   struct no *aux = s.topo;
   if(aux->prox==NULL) return 0;
   else 
   return aux->prox->dado;
}
