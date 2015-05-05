#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

typedef struct ponto{
	int CoordenadaX;
	int CoordenadaY;
	int tanques;
}TipoPonto;

void Decodifica(FILE *texto);
void OrdenaPontos(FILE *textoA, FILE *saida, int Xbase, int Ybase, int *alternar);

#endif
