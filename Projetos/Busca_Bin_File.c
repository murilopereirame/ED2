/*#include <stdlib.h>
#include <stdio.h>

void main() {
	FILE* arq;
	char c;

	int ini = 0;
	int fin = 0;
	arq = fopen("dados.txt", "r");
	if (arq != NULL) {
		fseek(arq, 3, SEEK_END);
		fin = ftell(arq) - 1;
		fin /= 3;

		printf("Digite o caractere a ser buscado: ");
		scanf("%c", &c);

		printf("\n");
		rewind(arq);

		if (pos(arq, ini, fin, c))
			printf("\nPossui o caractere %c.", c);
		else
			printf("\nNão possui o caractere %c.", c);
	}
	else {
		printf("Erro na leitura.");
	}
}

int pos(FILE* arq, int ini, int fim, char key) {
	char b = NULL;
	fseek(arq, ((ini+fim)/2)*3, SEEK_SET);
	fscanf(arq, "%c", &b);
	
	if ((int)b == (int)key)
		return 1;
	if (ini >= fim)
		return 0;
	else {
		if ((int)b > (int)key) {
			pos(arq, ini, ((ini + fim) / 2) - 1, key);
		}
		else {
			pos(arq, ((ini + fim) / 2) + 1, fim, key);
		}
			
	}
}*/