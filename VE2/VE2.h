#ifndef __TADP_H
#define __TADP_H

typedef struct ve2 VE2;

VE2 *criaVE2(int);

void liberaVE2(VE2 *vetor);

void adicionaVE2(VE2 *vetor, int v);

void removeVE2(VE2 *vetor);

int obtemElementoVE2(VE2 *vetor);

int vazioVE2(VE2 *vetor);

int cheioVE2(VE2 *vetor);

int tamanhoVE2(VE2 *vetor);

#endif
