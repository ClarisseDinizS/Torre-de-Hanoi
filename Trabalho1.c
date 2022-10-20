#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define TAM 10

#include "Trabalho1.h"

// TRABALHO TORRE DE HANOI - CLARISSE DINIZ SILVA 

int movi = 0; // Variável Global para contar a quantidade de movimentos feitos.
int elemento = 1; // Variável Global para auxiliar na reorganização dos movimentos.

// Structs da Pilha 
struct Pilha {
	int* item;
	int topo;
	char indice;
};

// Structs da Fila
typedef struct elem {
	int info;
	char name;
	struct elem *prox;
}tipo_elem;

typedef struct fila {
	struct elem *inicio;
	struct elem *fim;
	int tam;
}tipo_fila;


// Criação da Pilha e Fila(Funções)

// Inicializa a fila
void criarFila(tipo_fila *f){
	f->inicio = NULL;
	f->fim = NULL;
}

// Insere elementos na fila
void inserir(char x, tipo_fila *valor){
	
	tipo_elem *novo = (tipo_elem *)malloc(sizeof(tipo_elem));
	
	if (novo == NULL){
		printf("\nErro na Alocação");
	}
	else{
		novo->name = x;
		novo->prox = NULL;
		
		if (valor->inicio == NULL){
			valor->inicio = novo;
		}
		else{
			valor->fim->prox = novo;
		}
		valor->fim = novo;
		valor->tam++;	
	}
}

// Imprime a Fila (Nesse caso, vai imprimir os movimentos)
void mostrar(tipo_fila *f){
	
	tipo_elem *atual = f->inicio;
	int cont = 0;
	int x;
	
	if(atual != NULL){
		for(x = 0; x < movi; x++){
		
			printf("\n %c", atual->name);
			atual = atual->prox;
			printf(" %c", atual->name);
			atual = atual->prox;	
		}
	}
}

// Inicializa a Pilha com alocação e tals.
struct Pilha* InicioPilha(int tam,char nome)
{
    struct Pilha* pilha = (struct Pilha*)malloc(sizeof(struct Pilha));
    pilha->item = (int*)malloc(tam * sizeof(int));
    
	pilha->topo = -1;
    pilha->indice = nome;
    return pilha;
}

// Verifica se a pilha está vazia
int PilhaVazia(struct Pilha* valor){
	if (valor->topo == -1){
		return 1;
	}
	else{
		return 0;
	}
}
// Verifica se a pilha está cheia
int PilhaCheia (struct Pilha* valor){
	if (valor->topo == TAM-1){
		return -1;
	}
	else {
		return 0;
	}
}

// Empilhando os valores da pilha
void empilhar(struct Pilha* valor, int x){
	if (PilhaCheia(valor) == -1){
		printf ("Erro: Pilha está cheia");
	}
	else {
		valor->topo++;
		valor->item[valor->topo] = x;	
	}
}

// Desempilhando os valores da pilha
int desempilhar(struct Pilha* valor){
	int aux;
	aux = valor->item[valor->topo];
	valor->topo--;
	return aux;
	
}

// Imprimindo os valores da pilha 
int imprimir(struct Pilha* valor, int indice){
	
	if(indice > valor->topo){ 
		return 0;
	}
	return valor->item[indice];
}

// Função da Torre de Hanoi. Organizar e jogar os discos já organizados do pino inicial para o final/destino. ^._.^
void TorreHanoi(struct Pilha* inicio,struct Pilha* auxiliar, struct Pilha* final,int qtde,tipo_fila *Fil){
	
	if (qtde >= 1){
		TorreHanoi(inicio,final,auxiliar,qtde-1,Fil);
		
		// Inserindo os nomes das PiLhas e guardando na lista.
		inserir(inicio->indice,Fil); 
		inserir(final->indice,Fil);
		
		empilhar(final,desempilhar(inicio));
		
		movi++; // Conta cada um dos movimentos.
		
		TorreHanoi(auxiliar,inicio,final,qtde-1,Fil);
	}
}

/// Tentando Reorganizar os pinos na pilha A para depois fazer o Hanoi de A para C. (•_•) 
void Organizar(struct Pilha* pA, struct Pilha* pB, struct Pilha* pC, int discos,tipo_fila *Fil){
	
	int tamPil = 1;
	
	while(tamPil < discos){
		tamPil++;
		if(pA->item[pA->topo] == 1){ // Buscando no Pino A/ORIGINAL
			elemento++;
			if(pB->item[pB->topo] == elemento){
				TorreHanoi(pA,pC,pB,tamPil-1,Fil);
			}
			else if(pC->item[pC->topo] == elemento){
				TorreHanoi(pA,pB,pC,tamPil-1,Fil);
			}
			
		}
			
		else if(pB->item[pB->topo] == 1){ // Buscando no Pino B/AUXILIAR
			elemento++;
			if(pA->item[pA->topo] == elemento){
				TorreHanoi(pB,pC,pA,tamPil-1,Fil);
			}
			else if(pC->item[pC->topo] == elemento){
				TorreHanoi(pB,pA,pC,tamPil-1,Fil);	
			}
			
		}
		else { // Buscando no Pino C/DESTINO
			elemento++;
			if(pA->item[pA->topo] == elemento){
				TorreHanoi(pC,pB,pA,tamPil-1,Fil);
			}
			if(pB->item[pB->topo] == elemento){
				TorreHanoi(pC,pA,pB,tamPil-1,Fil);	
			}
			
		}
	}
} 

