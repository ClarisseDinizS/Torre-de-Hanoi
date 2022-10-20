#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define TAM 10

#include "Trabalho1.h"

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

int main (){
	
	// Declarando variáveis e alocando a fila.
	int qtde;
	qtde = 5;
	tipo_fila *Fil = (tipo_fila *)malloc(sizeof(tipo_fila));
	
	// Criando a fila para armazenar os movimentos.
	criarFila(Fil);
	
	// Criação das pilhas (Pinos).	
	
	struct Pilha* original = InicioPilha(qtde,'A');
	struct Pilha* auxiliar= InicioPilha(qtde,'B');
	struct Pilha* destino = InicioPilha(qtde,'C');
	
	// Empilhando os valores no Pino A.
	empilhar(original,5);
	empilhar(original,3);

	// Empilhando os valores no Pino B.
	empilhar(auxiliar,2);
	
	// Empilhando os valores no Pino C.
	empilhar(destino,4);
	empilhar(destino,1);
	
	//Chamando a função Reorganizar para organizar os discos na pilha A para depois fazer a Torre de Hanoi de A para C.
	Organizar(original,auxiliar,destino,qtde,Fil);

	// Função Torre de Hanoi para jogar os discos já organizados em A para o pino C.
	TorreHanoi(original,auxiliar,destino,qtde,Fil);
	
	printf("%d", movi);
	
	// Mostra os movimentos feitos durante a execução do Hanoi.
	mostrar(Fil);
	
		
}
