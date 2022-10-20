#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define TAM 10

#ifndef TRABALHO1_H
#define TRABALHO1_H

extern int movi; // Variável Global para contar a quantidade de movimentos feitos.
extern int elemento; // Variável Global para auxiliar na reorganização dos movimentos.

// Structs da Pilha 
typedef struct Pilha Pilha;

// Structs da Fila
typedef struct elem tipo_elem;

typedef struct fila tipo_fila;

// Inicializa a fila
void criarFila(tipo_fila *f);

// Insere elementos na fila
void inserir(char x, tipo_fila *valor);

// Imprime a Fila (Nesse caso, vai imprimir os movimentos)
void mostrar(tipo_fila *f);

// Inicializa a Pilha com alocação e tals.
struct Pilha* InicioPilha(int tam,char nome);

// Verifica se a pilha está vazia.
int PilhaVazia(struct Pilha* valor);

// Verifica se a pilha está cheia.
int PilhaCheia (struct Pilha* valor);

// Empilhando os valores da pilha.
void empilhar(struct Pilha* valor, int x);

// Desempilhando os valores da pilha.
int desempilhar(struct Pilha* valor);

// Imprimindo os valores da pilha.
int imprimir(struct Pilha* valor, int indice);

// Função da Torre de Hanoi. Organizar e jogar os discos já organizados do pino inicial para o final/destino. ^._.^
void TorreHanoi(struct Pilha* inicio,struct Pilha* auxiliar, struct Pilha* final,int qtde,tipo_fila *Fil);

// Tentando Reorganizar os pinos na pilha A para depois fazer o Hanoi de A para C. (•_•)
void Organizar(struct Pilha* pA, struct Pilha* pB, struct Pilha* pC, int discos,tipo_fila *Fil);

#endif

