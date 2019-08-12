#include <stdio.h>
#include <stdlib.h>

struct tipono {
	short int tipoinfo; // numero=0 operacao=1
	union {
		char operacao;
		float numero;
	} info;
	int esq;
	int dir;
};

float calculo(char op, float n1, float n2) {
	float res;
	switch (op) {
	case '-': res = n1 - n2;
		break;
	case '+': res = n1 + n2;
		break;
	case '*': res = n1 * n2;
		break;
	case '/': res = n1 / n2;
		break;

	}
	return res;
}

float avalia(int pos, FILE *fp) {
	struct tipono* aux = malloc(sizeof(struct tipono));
	fseek(fp, pos*sizeof(struct tipono), SEEK_SET);
	fread(aux, sizeof(struct tipono), 1, fp);

	float num1, num2, res;
	char operacao;
	if (aux->tipoinfo == 0) {
		res = aux->info.numero;
		printf("retornando %f\n", res);
	}
	else {
		operacao = aux->info.operacao;
		printf("retornando %c\n", operacao);
		num1 = avalia(aux->esq, fp);
		num2 = avalia(aux->dir, fp);
		res = calculo(operacao, num1, num2);
		printf("calculo: %c\n", res);
	}
	return res;
}

void inserirNo( int ind, int tipo, char op, float num, int indesq, int inddir, FILE* fp) {
	struct tipono* aux = malloc(sizeof(struct tipono));
	aux->tipoinfo = tipo;
	if (fp != NULL) {
		if (tipo == 00) {
			aux->info.numero = num;
			aux->esq = -1;
			aux->dir = -1;
			fwrite(aux, sizeof(struct tipono), 1, fp);
		}
		else {
			aux->info.operacao = op;
			aux->esq = indesq;
			aux->dir = inddir;
			fwrite(aux, sizeof(struct tipono), 1, fp);
		}
	}
}

int main()
{
	FILE* fp = fopen("arq.dat", "wb+");
	inserirNo(0, 1, '+', 0, 1, 2, fp);
	inserirNo(1, 1, '+', 0, 3, 4, fp);
	inserirNo(2, 0, ' ', 3, -1, -1, fp);
	inserirNo(3, 0, ' ', 3, -1, -1, fp);
	inserirNo(4, 1, '/', 0, 5, 6, fp);
	inserirNo(5, 1, '*', 0, 7, 8, fp);
	inserirNo(6, 0, ' ', 5, -1, -1, fp);
	inserirNo(7, 0, ' ', 4, -1, -1, fp);
	inserirNo(8, 1, '-', 0, 9, 10,fp);
	inserirNo(9, 0, ' ', 6, -1, -1, fp);
	inserirNo(10, 0, ' ', 7, -1, -1,fp);

	/*inserirNo( 10, 0, ' ', 7, -1, -1,fp);
	inserirNo( 9, 0, ' ', 6, -1, -1,fp);
	inserirNo( 8, 1, '-', 0, 9, 10,fp);
	inserirNo( 7, 0, ' ', 4, -1, -1,fp);
	inserirNo( 6, 0, ' ', 5, -1, -1,fp);
	inserirNo( 5, 1, '*', 0, 7, 8,fp);
	inserirNo( 4, 1, '/', 0, 5, 6,fp);
	inserirNo( 3, 0, ' ', 3, -1, -1,fp);
	inserirNo( 2, 0, ' ', 3, -1, -1,fp);
	inserirNo( 1, 1, '+', 0, 3, 4,fp);
	inserirNo( 0, 1, '+', 0, 1, 2,fp);*/
	fclose(fp);

	fp = fopen("arq.dat", "rb+");
	printf("%f", avalia(0, fp));
	fclose(fp);

	getchar();
	return 0;
}
