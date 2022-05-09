#include "lista.h"

void FLVazia(Lista *l) {
    l->Primeiro = 0;
    l->Ultimo = 0;
}

void lerArquivo(Lista *l, Item *i) {

    FILE *arq;

    int aux = 0;

    char nome[MAXNOME];
    char nomeArquivo[MAXARQ];

    printf("Informe o nome do arquivo (com a extensão): ");
    fgets(nomeArquivo, MAXARQ, stdin);
    aux = strlen(nomeArquivo)-1;
    nomeArquivo[aux] = '\0';

    arq = fopen(nomeArquivo, "r+");

    if (arq != NULL) {
            while (fgets(nome, MAXNOME, arq) != NULL) {
                strcpy(i->value, nome);
                LInsert(l, i);
            }
            LImprime(l);
            Replicacao(l);
            fclose(arq);
        } else {
            printf("\nOcorreu um erro. Verifique se o nome do arquivo está correto.\n");
        }
}

void LInsert(Lista *l, Item *i) {
    if (l->Ultimo >= MAX) {
        printf("Lista cheia!\n");
    }
    else {
        strcpy(l->vet[l->Ultimo].value, i->value);
        l->Ultimo++;
    }
}

void LImprime(Lista *l) {
    if(l->Primeiro == l->Ultimo) {
        printf("Lista vazia!\n");
        return;
    }
    for (int i=0; i<l->Ultimo; i++) {
        printf("Nome %d: %s", i+1, l->vet[i].value);
    }
}

void Replicacao(Lista *l) {

    if (l->Primeiro == l->Ultimo) {
        printf("Lista vazia!\n");
        return;
    }

    for (int j = 0; j < l->Ultimo; j++) {

        for (int k = j + 1; k < l->Ultimo; k++) {
            if (strcmp(l->vet[j].value, l->vet[k].value) == 0) {
                strcpy(l->vet[j].value, "\n");
            }
        }

    }

    printf("\n\nReplicações excluídas\n");
    printf("\n\nNova lista: \n");
    LImprime(l);
    
}