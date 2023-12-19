
#include <sys/time.h>
#include <time.h>
#include "AnaliseTempo.h"

static struct timeval iReal;
static clock_t iCPU;

void inicializarTempoRealeCPU() {
  gettimeofday(&iReal, 0);
  iCPU = clock();
}

void obterTempoRealeCPU(double *tReal, double *tCPU) {
  struct timeval fReal;
  gettimeofday(&fReal, 0);
  clock_t fCPU = clock();

  *tReal = (fReal.tv_sec - iReal.tv_sec) + (fReal.tv_usec - iReal.tv_usec) * 1e-6;
  *tCPU = ((double) (fCPU - iCPU)) / CLOCKS_PER_SEC;
}
