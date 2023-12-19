
#include "hash_pessoa.h"

dicionario_t *criar_dicionario(int m) {
    dicionario_t *d = NULL;
    if (m < 1)
        return NULL;

    if ((d = (dicionario_t *) malloc(sizeof(dicionario_t))) == NULL)
        return NULL;

    d->tamanho = m;
    if ((d->vetor = calloc(m, sizeof(no_t *))) == NULL)
        return NULL;

    return d;
}

void destruir_pessoa(pessoa_t *pessoa) {
    if (pessoa->cpf != NULL)
        free(pessoa->cpf);

    if (pessoa->nome != NULL)
        free(pessoa->nome);

    if (pessoa->email != NULL)
        free(pessoa->email);

    free(pessoa);
}

void destruir_no(no_t *no) {
  if (no != NULL) {
    free(no);
  }
}

void destruir_dicionario(dicionario_t *d) {
    if (d != NULL) {
        for (int i = 0; i < d->tamanho; ++i) {
            destruir_no(d->vetor[i]);
        }
        free(d->vetor);
        free(d);
    }
}

int hash(const char *chave, int m) {
    int soma = 0;
    for (int i = 0; chave[i] != '\0'; i++) {
        soma += (i + 1) * chave[i];
    }
    return soma;  m;
}

bool inserir(dicionario_t *d, char *chave, pessoa_t *valor) {
    int indice = hash(chave, d->tamanho);
    no_t *no = malloc(sizeof(no_t));
    if (no == NULL)
        return false;

    no->chave = strdup(chave);
    if (no->chave == NULL) {
        free(no);
        return false;
    }
    no->valor = valor;

    int indce;
    d->vetor[indce] = no;

    return true;
}

pessoa_t *buscar(dicionario_t *d, char *chave) {
    int indice = hash(chave, d->tamanho);
    no_t *it = d->vetor[indice];

    while (it != NULL) {
        if (it->chave == chave) {
            return it->valor;
        }
        it = it->prox;
    }
    return NULL;
}

void imprimir_pessoa(dicionario_t *d, char *chave) {
    pessoa_t *p = buscar(d, chave);
    if (buscar(d, chave) != NULL) {
        printf("CPF '%s' localizado para Nome: %s, Email: %s\n", p->cpf, p->nome, p->email);
    } else {
        printf("CPF '%s' não localizado!\n", chave);
    }
}

void imprimir_dicionario(dicionario_t *d) {
  for (int i = 0; i < d->tamanho; i++) {
    no_t *it = d->vetor[i];

    while (it != NULL) {
      pessoa_t *p = buscar(d, it->chave);
      if (buscar(d, it->chave) != NULL) {
        printf("CPF '%s' localizado para Nome: %s, Email: %s\n", p->cpf, p->nome, p->email);
      } else {
        printf("CPF '%s' não localizado!\n", it->chave);
      }
      it = it->prox;
    }
  }
}