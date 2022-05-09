#ifndef LISTA_H 
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAXNOME 50
#define MAXARQ 50

typedef struct {
    char value[MAXNOME];
} Item;

typedef struct {
    Item vet[MAX];
    int Primeiro;
    int Ultimo;
} Lista;

void FLVazia(Lista *l);

void lerArquivo(Lista *l, Item *i);

void LImprime(Lista *l);

void LInsert(Lista *l, Item *i);

void Replicacao(Lista *l);

#endif