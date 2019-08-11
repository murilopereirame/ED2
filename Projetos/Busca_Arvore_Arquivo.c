#include <stdlib.h>
#include <stdio.h>

typedef struct {
	int chave;
	int ind_esq;
	int ind_dir;
	int ind_pai;
} NO;

void main(){
	FILE* fp;
	int i, ind, sizeNO;

	fp = fopen("structArqBin.dat", "wb+");
	if (fp != NULL) {
		NO* aux = malloc(sizeof(NO));
		aux->chave = 4;
		aux->ind_esq = 1;
		aux->ind_dir = 4;
		aux->ind_pai = -1;
		fwrite(aux, sizeof(NO), 1, fp);

		aux->chave = 2;
		aux->ind_esq = 2;
		aux->ind_dir = 3;
		aux->ind_pai = 1;
		fwrite(aux, sizeof(NO), 1, fp);

		aux->chave = 1;
		aux->ind_esq = -1;
		aux->ind_dir = -1;
		aux->ind_pai = 2;
		fwrite(aux, sizeof(NO), 1, fp);

		aux->chave = 3;
		aux->ind_esq = -1;
		aux->ind_dir = -1;
		aux->ind_pai = 2;
		fwrite(aux, sizeof(NO), 1, fp);

		aux->chave = 6;
		aux->ind_esq = 5;
		aux->ind_dir = 6;
		aux->ind_pai = 1;
		fwrite(aux, sizeof(NO), 1, fp);

		aux->chave = 5;
		aux->ind_esq = -1;
		aux->ind_dir = -1;
		aux->ind_pai = 5;
		fwrite(aux, sizeof(NO), 1, fp);

		aux->chave = 7;
		aux->ind_esq = -1;
		aux->ind_dir = -1;
		aux->ind_pai = 5;
		fwrite(aux, sizeof(NO), 1, fp);
		
		free(aux);

		printf("%d", BuscaBin(0, 4, fp, sizeof(NO)));

		fclose(fp);
	}
}

int BuscaBin(int pos, int chave, FILE* arq, int sizeNO) {
	NO* aux = malloc(sizeof(NO));
	fseek(arq, pos * sizeof(NO), SEEK_SET);
	//fread(aux, sizeNO, 1, arq);
	fread(aux, sizeof(NO), 1, arq);


	if (aux->chave == chave)
		return 1;
	if (pos == -1)
		return 0;
	else {
		if (aux->chave > chave) {
			BuscaBin(aux->ind_esq, chave, arq, sizeNO);
		}
		else {
			BuscaBin(aux->ind_dir, chave, arq, sizeNO);
		}
	}
}