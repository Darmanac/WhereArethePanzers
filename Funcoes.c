#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Funcoes.h"

void Decodifica(FILE *texto){
	int sequencia, Ntanques;
	char mensagem;
	char coordA[5], coordB[5];
	int i, j, terminarFase, primeiracoord;
	int cont;
	j = 0;
	i = 0;
	cont = 0;
	
	while(scanf("%c", &mensagem) != EOF){

	 	// Primeira fase
		terminarFase = 0;
		
		if(feof(stdin)){
		        terminarFase = 1;
		        fclose(texto);
			return;
           		}

		sequencia = 0;
		Ntanques = 0;
		
		while(sequencia <= 3 && !feof(stdin)){
			
			switch(sequencia){
				case 0:
					if(mensagem == 'p'){
						sequencia++;
					}
					
					else
						break;
					
					break;
				
				case 1:
					if(mensagem == 'o'){
						Ntanques++;
					}
					
					else if(mensagem == 'i' && Ntanques > 0){
						sequencia++;
					}
					
					else
						break;
						
					break;
					
				case 2: 
					if(mensagem == 'n'){
						sequencia++;
					}
					
					else 
						break;
						
					break;
					
				case 3:
					if(mensagem == 't'){
						sequencia++;
					}
					
					else 
						break;
						
					break;
					
			}
			
			if(feof(stdin)){ 
		                terminarFase = 1;
		                fclose(texto);
		                return;
		        }
		       
			
			if(!feof(stdin)){
			        scanf("%c", &mensagem);
			}
			
			
			if(feof(stdin)){ 
		                terminarFase = 1;
		                fclose(texto);
		                return;
		        }
		}
		
		
		
	// Pre segunda fase
		
		if(mensagem != '(' && scanf("%c", &mensagem) != EOF){
			while(mensagem != '(' && !feof(stdin)){
				scanf("%c", &mensagem);
				
				if(feof(stdin)){
			                terminarFase = 1;
           		                return;
           		        }
			}
		}
		
		
		for(i = 0; i < 5;i++){
			coordA[i] = '\0';
			coordB[i] = '\0';
		}
		
		i = 0;
		j = 0;
		primeiracoord = 1;
		
	// achando a 1a coordenada	
		
		while(mensagem != ',' && terminarFase == 0 && scanf("%c", &mensagem) != EOF){
			
			if(feof(stdin)){
			        terminarFase = 1;
           		        return;
           		}
			
			if(mensagem == '(' || mensagem == ')'){
				terminarFase = 1;
			}
			
			else if(mensagem == ',' && coordA[0] == '\0'){
				terminarFase = 1;
			}
			
			else if(mensagem >= '0' && mensagem <= '9'){
				if(mensagem == '0' && primeiracoord == 1){
					// Ignora esse zero pois sera um zero aa esquerda.
					coordA[0] = '0'; // Caso esse seja o unico numero encontrado na coordenada A, ele nao sera tratado como um 0 aa esquerda
				}
				else{
					i++;
					if(i > 5){
						terminarFase = 1;
					}
					
					else{
						coordA[i-1] = mensagem;
						primeiracoord = 0;
					}
				}
			}
				
		}
		
	// achando a 2 coordenada	
		
		primeiracoord = 1;
		
		if(terminarFase == 0){
			while(mensagem != ')' && terminarFase == 0 && scanf("%c", &mensagem) != EOF){
				
				if(feof(stdin)){
					terminarFase = 1;
           			        return;					
				}
					
				if(mensagem == ',' || mensagem == '('){
					terminarFase = 1;
				}
				
				if(mensagem == ')' && coordB[0] == '\0'){
					terminarFase = 1;
				}
				
				else if(mensagem >= '0' && mensagem <= '9'){
					if(mensagem == '0' && primeiracoord == 1){
					// Ignora esse zero pois sera um zero aa esquerda.
					coordB[0] = '0'; // caso esse seja o unico numero encontrado nessa coordenada, ele nao sera tratado como um 0 aa esquerda
					}
					
					else{
						j++;
						if(j > 5){
							terminarFase = 1;
						}
						
						
						else{
							coordB[j-1] = mensagem;
							primeiracoord = 0;
						}
					}
				} 		
			}
		}
		
		// Fim da segunda fase
		
		if(terminarFase == 0){
				fprintf(texto, "%d ", Ntanques);
				fprintf(texto, "%ld ", strtoul(coordA, NULL, 10));
				fprintf(texto, "%ld\n", strtoul(coordB, NULL, 10));
		cont++;
		}
	
		// Impressao no arquivo inicial.
	}
	
	fclose(texto);
	return;
}


void OrdenaPontos(FILE *textoA, FILE *saida, int Xbase, int Ybase, int *alternar){
	TipoPonto Atual, Max;
	double distanciaAtual, distanciaMax;
	int vazio, vazio2, fim;
	FILE *textoB;
	
	fim = 0;
	
	Max.tanques = -1;
	
	textoA = fopen("A.txt", "r");
	textoB = fopen("B.txt", "r");
	
	if(fscanf(textoA, "%d", &vazio) == EOF && fscanf(textoB, "%d", &vazio2) == EOF){
		fim = 1;
	}
	
	
	fclose(textoA);
	fclose(textoB);
	
	if(*alternar == 0 && fim == 0){
		textoA = fopen("A.txt", "r");
		textoB = fopen("B.txt", "w");
		
		while(fscanf(textoA, "%d %d %d\n", &Atual.tanques, &Atual.CoordenadaX, &Atual.CoordenadaY) != EOF){
			
			if(Atual.tanques > Max.tanques){
				if(Max.tanques != -1){
					fprintf(textoB, "%d %d %d\n", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
				}
				Max.tanques = Atual.tanques;
				Max.CoordenadaX = Atual.CoordenadaX;
				Max.CoordenadaY = Atual.CoordenadaY;
			}
			
			else if(Atual.tanques < Max.tanques){
				fprintf(textoB, "%d %d %d\n", Atual.tanques, Atual.CoordenadaX, Atual.CoordenadaY);
			}
			
			else if(Atual.tanques == Max.tanques){
				distanciaAtual = sqrt(pow((Atual.CoordenadaX - Xbase), 2) + pow((Atual.CoordenadaY - Ybase), 2));
				distanciaMax = sqrt(pow((Max.CoordenadaX - Xbase), 2) + pow((Max.CoordenadaY - Ybase), 2));
				
				if(distanciaAtual < distanciaMax){
					fprintf(textoB, "%d %d %d\n", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
					Max.tanques = Atual.tanques;
					Max.CoordenadaX = Atual.CoordenadaX;
					Max.CoordenadaY = Atual.CoordenadaY;
				}
				
				else if(distanciaAtual > distanciaMax){
					fprintf(textoB, "%d %d %d\n", Atual.tanques, Atual.CoordenadaX, Atual.CoordenadaY);
				}
				
				else if(distanciaAtual == distanciaMax){
					fprintf(textoB, "%d %d %d\n", Atual.tanques, Atual.CoordenadaX, Atual.CoordenadaY);
				}
			}
			
		}
		
		fclose(textoA);
		fclose(textoB);
		
		if(Max.tanques != -1){
			//fprintf(saida, "%d;(%d,%d)", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
			printf("%d;(%d,%d)\n", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
		}
		
		*alternar = 1;
		OrdenaPontos(textoA, saida, Xbase, Ybase, alternar);
	}
	
	else if(*alternar == 1 && fim == 0){
		textoB = fopen("B.txt", "r");
		textoA = fopen("A.txt", "w");
		
		while(fscanf(textoB, "%d %d %d\n", &Atual.tanques, &Atual.CoordenadaX, &Atual.CoordenadaY) != EOF){
			
			if(Atual.tanques > Max.tanques){
				if(Max.tanques != -1){
					fprintf(textoA, "%d %d %d\n", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
				}
				Max.tanques = Atual.tanques;
				Max.CoordenadaX = Atual.CoordenadaX;
				Max.CoordenadaY = Atual.CoordenadaY;
			}
			
			else if(Atual.tanques < Max.tanques){
				fprintf(textoA, "%d %d %d\n", Atual.tanques, Atual.CoordenadaX, Atual.CoordenadaY);
			}
		
			else if(Atual.tanques == Max.tanques){
				distanciaAtual = sqrt(pow((Atual.CoordenadaX - Xbase), 2) + pow((Atual.CoordenadaY - Ybase), 2));
				distanciaMax = sqrt(pow((Max.CoordenadaX - Xbase), 2) + pow((Max.CoordenadaY - Ybase), 2));
				
				if(distanciaAtual < distanciaMax){
					fprintf(textoA, "%d %d %d\n", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
					Max.tanques = Atual.tanques;
					Max.CoordenadaX = Atual.CoordenadaX;
					Max.CoordenadaY = Atual.CoordenadaY;
				}
				
				else if(distanciaAtual > distanciaMax){
					fprintf(textoA, "%d %d %d\n", Atual.tanques, Atual.CoordenadaX, Atual.CoordenadaY);
				}
				
				else if(distanciaAtual == distanciaMax){
					fprintf(textoA, "%d %d %d\n", Atual.tanques, Atual.CoordenadaX, Atual.CoordenadaY);
				}
			}	
		
		}
		
		fclose(textoA);
		fclose(textoB);
		
		if(Max.tanques != -1){
			fprintf(saida, "%d;(%d,%d)", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
			printf("%d;(%d,%d)\n", Max.tanques, Max.CoordenadaX, Max.CoordenadaY);
		}
		
		*alternar = 0;
		OrdenaPontos(textoA, saida, Xbase, Ybase, alternar);
	}
	
}


