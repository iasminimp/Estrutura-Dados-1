#ifndef __TADP_H
#define __TADP_H

typedef struct ve1 VE1;

VE1 *criaVE1(int);

void liberaVE1(VE1 *vetor);

void adicionaVE1(VE1 *vetor, int v);

void removeVE1(VE1 *vetor);

int obtemElementoVE1(VE1 *vetor);

int vazioVE1(VE1 *vetor);

int cheioVE1(VE1 *vetor);

int tamanhoVE1(VE1 *vetor);

#endif
