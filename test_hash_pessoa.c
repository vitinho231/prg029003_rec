
#include <stdio.h>
#include "hash_pessoa.h"
#include "AnaliseTempo.h"

int main() {
  dicionario_t *dicionario = criar_dicionario(2);
  if (dicionario == NULL) {
    printf("Não foi possível reservar memória\n");
    exit(EXIT_FAILURE);
  }

  int n_samples = 100;
  int n_tests_not_exist = 100;
  unsigned int cpfs[n_samples];
  for (int i = 0; i < n_samples; i++) {
    pessoa_t *p = malloc(sizeof(pessoa_t));
    char random_cpf[12];
    cpfs[i] = rand()%99999999999;
    sprintf(random_cpf, "%d", cpfs[i]);
    *p = (pessoa_t){strdup(random_cpf), strdup(random_cpf), strdup("@example.org") };
    inserir(dicionario, p->cpf, p);
  }

  imprimir_dicionario(dicionario);

  double melhorTCPU = 1;
  double piorTCPU = 0;
  double somaTCPU = 0;
  for (int i = 0; i < n_samples; i++) {
    char cpf[12];
    sprintf(cpf, "%d", cpfs[i]);
    double tReal, tCPU;
    inicializarTempoRealeCPU();
    if (buscar(dicionario, cpf) == NULL) {
      fprintf(stderr, "*** Chave %s não encontrada", cpf);
      exit(EXIT_FAILURE);
    }
    obterTempoRealeCPU(&tReal, &tCPU);
    somaTCPU = somaTCPU + tCPU;
    if (tCPU > piorTCPU) piorTCPU = tCPU;
    if (tCPU < melhorTCPU) melhorTCPU = tCPU;
  }

  for (int i = 0; i < n_tests_not_exist; i++) {
    char cpf[12];
    sprintf(cpf, "%d", rand()%99999999999);
    double tReal, tCPU;
    inicializarTempoRealeCPU();
    if (buscar(dicionario, cpf) != NULL) {
      fprintf(stderr, "*** Chave %s que não deveria foi encontrada", cpf);
      exit(EXIT_FAILURE);
    }
    obterTempoRealeCPU(&tReal, &tCPU);
    somaTCPU = somaTCPU + tCPU;
    if (tCPU > piorTCPU) piorTCPU = tCPU;
    if (tCPU < melhorTCPU) melhorTCPU = tCPU;
  }

  printf("Melhor tCPU = %lf\n",melhorTCPU);
  printf("Pior tCPU = %lf\n",piorTCPU);
  printf("Média tCPU = %lf\n",somaTCPU/(n_samples+n_tests_not_exist));

  destruir_dicionario(dicionario);
  return 0;
}