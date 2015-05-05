#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"
/*#include <sys/time.h>
#include <sys/resource.h>
#include <stdint.h>

void SetMemoryLimit(const int64_t limit_mb){
	struct rlimit limits;
	limits.rlim_cur = limit_mb * 1024ull * 1024ull;
	limits.rlim_max = limit_mb * 1024ull * 1024ull;
	int error_code = setrlimit(RLIMIT_AS, &limits);
}
*/

int main(){
	FILE *textoA, *Resultado;
	int Xbase, Ybase;
	int AlternarArquivo;
	int megabytes;
	
	fscanf(stdin, "%d", &megabytes);
	fscanf(stdin, "%d %d", &Xbase, &Ybase);
	
	textoA = fopen("A.txt", "w");
	
	if(textoA == NULL){
		printf("Falha em abrir o arquivo!");
		exit(1);
	}
	
	Decodifica(textoA);
	
	Resultado = fopen("Saida.txt", "w");
	
	if(Resultado == NULL){
		printf("Falha em abrir o arquivo!");
		exit(1);
	}
	
	AlternarArquivo = 0;
	
	OrdenaPontos(textoA, Resultado, Xbase, Ybase, &AlternarArquivo);
		
	fclose(Resultado);
	
	
	return 0;
}
