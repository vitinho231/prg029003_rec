
#ifndef INC_1_HASHTABLE_PESSOA_H
#define INC_1_HASHTABLE_PESSOA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *cpf;
    char *nome;
    char *email;
} pessoa_t;

typedef struct no {
    char *chave;
    pessoa_t *valor;
    struct no *prox;
} no_t;

typedef struct dicionario {
    int tamanho; // tamanho do vetor
    no_t **vetor;
} dicionario_t;

dicionario_t *criar_dicionario(int m);
void destruir_pessoa(pessoa_t *pessoa);
void destruir_no(no_t *no);
void destruir_dicionario(dicionario_t *d);
int hash(const char *chave, int m);
bool inserir(dicionario_t *d, char *chave, pessoa_t *valor);
pessoa_t *buscar(dicionario_t *d, char *chave);
void imprimir_pessoa(dicionario_t *d, char *chave);
void imprimir_dicionario(dicionario_t *d);

#endif //INC_1_HASHTABLE_PESSOA_H
