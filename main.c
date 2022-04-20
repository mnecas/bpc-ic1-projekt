#include <iostream>
#include<stdio.h>
#include <ctype.h>
#include<stdlib.h>

int main()
{
	int m, n, a, m2, n2, k = -2147483648;
	short int z = 0;
	int vys, e, b, c = 0;
	int	 id1, id2, id3, idh = 0;
	int** mat = NULL;
	int** mat2 = NULL;
	int** matv = NULL;
	char x;
	FILE* fptr;
	
	/*printf("Chcete vymazat predchozi historii, ano = 1, ne = 2:	");
	scanf("%d", &idh);
	while ((idh != 1) && (idh != 2))
	{
		printf("Neplatna identifikace, zadejte hodnotu na intervalu 1-2!: ");
		scanf("%d", &idh);
	}
	if (idh == 1)
	{
		fopen(*fptr, "historie.txt", "w+");
		fprintf(fptr, "");
		fclose(fptr);
	}*/
	

	printf("Zvolte operaci s maticemi 1 = soucet, 2 = rozdil, 3 = nasobeni zadanym cislem, 4 = nasobeni matic, 5 = transponovana matice, 6 = determinant matice:   ");
	scanf("%d", &id3);
	while ((id3 != 1) && (id3 != 2) && (id3 != 3) && (id3 != 4) && (id3 != 5) && (id3 != 6))
	{
		printf("Neplatna identifikace, zadejte hodnotu na intervalu 1-6!");
		scanf("%d", &id3);
	}

	printf("-------------MATICE1------------\n");
	printf("Zadejte 1 pro ctvercovou matici a 2 pro obdelnikovou: ");
	scanf(" %c", &x);
	while (getchar() != '\n');
	
	while (isdigit(x) == 0)
	{
		printf("Neplatna identifikace, zadej hodnotu znovu!");
		scanf(" %c", &x);
		while (getchar() != '\n');
	}

	while (isdigit(x)) {
		id1 = (x - '0');
		x = ' ';
	}

	while ((id1 != 1) && (id1 != 2))
	{
		printf("Neplatna identifikace, zadej hodnotu znovu!");
		scanf(" %c", &x);
		while (getchar() != '\n');

		while (isdigit(x) == 0)
		{
			printf("Neplatna identifikace, zadej hodnotu znovu!");
			scanf(" %c", &x);
			while (getchar() != '\n');
		}

		while (isdigit(x)) {
			id1 = (x - '0');
			x = ' ';
		}
	}

	//ZADAVANI ROZMERU MATICE 1
	if (id1 == 1) {
		printf("Zadejte rozmery prvni matice:\n");

		//OSETROVANI ZDA JE NA VSTUPU CISLO
		scanf(" %c", &x);
		while (getchar() != '\n');
		while (isdigit(x) == 0)
		{
			printf("Neplatna identifikace, zadej hodnotu znovu!");
			scanf(" %c", &x);
			while (getchar() != '\n');
		}

		while (isdigit(x)) {
			m = (x - '0');
			x = ' ';
		}
		// 

		while ((m > 5) || (m <= 0))
		{
			printf("Neplatny vstup matice mohou byt maximalne o velikosti 5x5 \n");
			scanf(" %c", &x);
			while (getchar() != '\n');
			while (isdigit(x) == 0)
			{
				printf("Neplatna identifikace, zadej hodnotu znovu!");
				scanf(" %c", &x);
				while (getchar() != '\n');
			}

			while (isdigit(x)) {
				m = (x - '0');
				x = ' ';
			}
		}
		n = m;
		mat = (int**)calloc(n, sizeof(int*));

	}
	
	else if (id1 == 2) {
		printf("Zadejte rozmery prvni matice (radky x sloupce):\n");
		scanf("%d %d", &m, &n);
		
		while ((m <= 0) || (m > 5) || (n <= 0) || (n > 5))
		{
			printf("Neplatny vstup matice mohou byt maximalne o velikosti 5x5 \n");
			scanf("%d %d", &m, &n);
		}
		mat = (int**)calloc(n, sizeof(int*));
	}
	else {
		printf("Neplatna identifikace!");
	}



	if ((id1 == 1) || (id1 == 2))
	{
		printf("Ted budete zadavat prvky matice (za sebou)\n");
		for (int i = 0; i < m; i++)
		{
			*(mat + i) = (int*)calloc(m, sizeof(int));
			for (int j = 0; j < n; j++) {
				scanf("%d", &a);
				*(*(mat + i) + j) = a;
			}
		}
	}

	if ((id3 == 1) || (id3 == 2) || (id3 == 4))
	{
		printf("-------------MATICE2------------\n");
		printf("Zadejte 1 pro ctvercovou matici a 2 pro obdelnikovou: ");
		scanf(" %c", &x);
		while (getchar() != '\n');
		while (isdigit(x) == 0)
		{
			printf("Neplatna identifikace, zadej hodnotu znovu!");
			scanf(" %c", &x);
			while (getchar() != '\n');
		}

		while (isdigit(x)) {
			id2 = (x - '0');
			x = ' ';
		}

		while ((id2 != 1) && (id2 != 2))
		{
			printf("Neplatna identifikace, zadej hodnotu znovu!");
			scanf(" %c", &x);
			while (getchar() != '\n');

			while (isdigit(x) == 0)
			{
				printf("Neplatna identifikace, zadej hodnotu znovu!");
				scanf(" %c", &x);
				while (getchar() != '\n');
			}

			while (isdigit(x)) {
				id2 = (x - '0');
				x = ' ';
			}
		}

		if (id2 == 1) {
			printf("Zadejte rozmery druhe matice:\n");
			scanf("%d", &m2);
			while (getchar() != '\n');

			while ((m2 > 5) || (m2 <= 0))
			{
				printf("Neplatny vstup matice mohou byt maximalne o velikosti 5x5 \n");
				scanf("%d", &m2);
				while (getchar() != '\n');
			}

			n2 = m2;
			mat2 = (int**)calloc(n2, sizeof(int*));

		}

		else if (id2 == 2) {
			printf("Zadejte rozmery druhe matice (radky x slupce):\n");
			scanf("%d %d", &m2, &n2);
			while ((m2 <= 0) || (m2 > 5) || (n2 <= 0) || (n2 > 5))
			{
				printf("Neplatny vstup matice mohou byt maximalne o velikosti 5x5 \n");
				scanf("%d %d", &m2, &n2);
			}
			mat2 = (int**)calloc(n2, sizeof(int*));
		}
		else
			printf("Neplatna identifikace, spuste program znovu!");


		//	printf("%d %d\n", m2, n2);

		if ((id2 == 1) || (id2 == 2))
		{
			printf("Ted budete zadavat prvky matice (za sebou)\n");
			for (int i = 0; i < m2; i++)
			{
				*(mat2 + i) = (int*)calloc(m2, sizeof(int));
				for (int j = 0; j < n2; j++) {
					scanf("%d", &a);
					*(*(mat2 + i) + j) = a;
				}
			}
		}
	}



	switch (id3) {
	case 1:
		if ((m == m2) && (n == n2))				//SOUČET 
		{
			z = 1;
			matv = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < m; i++)
			{
				*(matv + i) = (int*)calloc(m, sizeof(int));
				for (int j = 0; j < n; j++)
				{
					matv[i][j] = (mat[i][j] + mat2[i][j]);
				}
			}
		}
		else
			printf("Tyhle matice nelze scitat");

		break;
	case 2:
		if ((m == m2) && (n == n2))			// ROZDIL 
		{
			z = 1;
			matv = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < m; i++)
			{
				*(matv + i) = (int*)calloc(m, sizeof(int));
				for (int j = 0; j < n; j++)
				{
					matv[i][j] = (mat[i][j] - mat2[i][j]);
				}
			}
		}
		else
			printf("Tyhle matice nelze odecitat");
		break;
	case 3:						//nasobeni k cislem
		z = 1;
		printf("Zadej cislo kterym chces nasobit: ");
		scanf("%d", &k);
		matv = (int**)calloc(n, sizeof(int*));
		for (int i = 0; i < m; i++)
		{	
			*(matv + i) = (int*)calloc(m, sizeof(int));
			for (int j = 0; j < n; j++)
			{
				matv[i][j] = (mat[i][j] * k);
			}
		}
		break;
	case 4:						//nasobeni 2 matic
		
		if (m2 == n)	//Podmínka jestli je mozne matice nasobit 
		{
			z = 3;
			matv = (int**)calloc(n, sizeof(int*));
			for (int i = 0; i < m; i++)
			{
				int sum = 0;
				*(matv + i) = (int*)calloc(m, sizeof(int));
				for (int j = 0; j < n2; j++)
				{
					for (int k = 0; k < m2; k++) {
						sum = (sum + (mat[i][k] * mat2[k][j]));

					}
					matv[i][j] = sum;
					sum = 0;
				}
			}

		}
		break;
	case 5:
		if ((m <= 4) && (n <= 4))
		{
			z = 4;
		}
		else {
			printf("\n");
			printf("Transponovat lze matice do rozmeru 4x4!\n");
			printf("\n");
		}
			
		break;
	case 6:
		if ((m <= 4) && (n <= 4)) {	//DETERMINANT
			vys = 0;
			if ((m == 1) && (n == 1)) {
				z = 5;
				vys = mat[0][0];
			}
				
			else if ((m == 2) && (n == 2)) {
				z = 5;
				vys = ((mat[0][0] * mat[1][1]) - (mat[0][1] * mat[1][0]));
			}
			else if ((m == 3) && (n == 3)) {
				z = 5;
				/*for (int i = 0; i < 3; i++) {
					vys = vys + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] - mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
				}*/
				e = mat[0][0] * ((mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]));
				b = mat[0][1] * ((mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]));
				c = mat[0][2] * ((mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]));
				vys = e - b + c;
			}
			else if ((m == 4) && (n == 4)) {
				z = 5;
				vys = (mat[0][0] * mat[1][1] * mat[2][2] * mat[3][3]) + (mat[0][0] * mat[1][2] * mat[2][3] * mat[3][1])
					+ (mat[0][0] * mat[1][3] * mat[2][1] * mat[3][2]) - (mat[0][0] * mat[1][3] * mat[2][2] * mat[3][1])
					- (mat[0][0] * mat[1][2] * mat[2][1] * mat[3][3]) - (mat[0][0] * mat[1][1] * mat[2][3] * mat[3][2])
					- (mat[0][1] * mat[1][0] * mat[2][2] * mat[3][3]) - (mat[0][2] * mat[1][0] * mat[2][3] * mat[3][1])
					- (mat[0][3] * mat[1][0] * mat[2][1] * mat[3][2]) + (mat[0][3] * mat[1][0] * mat[2][2] * mat[3][1])
					+ (mat[0][2] * mat[1][0] * mat[2][1] * mat[3][3]) + (mat[0][1] * mat[1][0] * mat[2][3] * mat[3][2])
					+ (mat[0][1] * mat[1][2] * mat[2][0] * mat[3][3]) + (mat[0][2] * mat[1][3] * mat[2][0] * mat[3][1])
					+ (mat[0][3] * mat[1][1] * mat[2][0] * mat[3][2]) - (mat[0][3] * mat[1][2] * mat[2][0] * mat[3][1])
					- (mat[0][2] * mat[1][1] * mat[2][0] * mat[3][3]) - (mat[0][1] * mat[1][3] * mat[2][0] * mat[3][2])
					- (mat[0][1] * mat[1][2] * mat[2][3] * mat[3][0]) - (mat[0][2] * mat[1][3] * mat[2][1] * mat[3][0])
					- (mat[0][3] * mat[1][1] * mat[2][2] * mat[3][0]) + (mat[0][3] * mat[1][2] * mat[2][1] * mat[3][0])
					+ (mat[0][2] * mat[1][1] * mat[2][3] * mat[3][0]) + (mat[0][1] * mat[1][3] * mat[2][2] * mat[3][0]);
			}
		}
		else {
			printf("\n");
			printf("Determinant matice lze vypocitat pouze do rozmeru 4x4!\n");
			printf("\n");
		}
		break;
	default: printf("Neplatna operace vol v rozsahu (1-5)");
	}

	printf("Vypis prvni matice: ");
	printf("\n");
	for (int i = 0; i < m; i++)			//VÝPIS MATICE1
	{
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("(%d) ", mat[i][j]);
		}
	}

	printf("\n");
	printf("\n");
	if ((id3 == 1) || (id3 == 2) || (id3 == 4))
	{
	printf("Vypis druhe matice: ");
	printf("\n");
		for (int i = 0; i < m2; i++)			//VÝPIS MATICE2
			{
				printf("\n");
				for (int j = 0; j < n2; j++) {
					printf("(%d) ", mat2[i][j]);
				}
		}
	}
	printf("\n");
	printf("\n");

	if (z == 1) {
		printf("Vysledek je:\n ");
		for (int i = 0; i < m; i++)			//VÝPIS VYSL
		{	
			printf("\n");
			printf("\n");
			for (int j = 0; j < n; j++) {
				printf("(%d) ", matv[i][j]);
			}
		}
	}
	else if (z == 3)
	{	
		printf("Vysledek je:\n ");
		for (int i = 0; i < m; i++)			//VÝPIS MATICE PO NÁSOBENÍ
		{
			printf("\n");
			for (int j = 0; j < n2; j++) {
				printf("(%d) ", matv[i][j]);
			}
		}
	}
	else if (z == 4) {
		printf("Vysledek je:\n ");
		for (int i = 0; i < n; i++)			//VÝPIS MATICE1 TRANSPONOVANÉ 
		{
			printf("\n");
			for (int j = 0; j < m; j++) {
				printf("(%d) ", mat[j][i]);
			}
		}
		printf("\n");
	}
	else if (z == 5)			//VÝPIS DETERMINANTU
	{
		printf("Determinant matice je %d", vys);
	}
	else
		printf("S temito maticemi nelze provadet zvolena operace!\n");

	//------------------------------------------------------------------HISTORIE HISTORIE HISTORIE HISTORIE HISTORIE-----------------------------------------------------------------------------------------
	/*if (z == 1) {							//VÝPIS VÝSLEDNÉ MATICE DO HISTORIE 
		fopen(&fptr, "historie.txt", "a");
		fprintf(fptr, "\nVysledek je:");
		for (int i = 0; i < m; i++)
		{
			fprintf(fptr, "\n");
			for (int j = 0; j < n; j++) {
				fprintf(fptr, "(%d)", matv[i][j]);
			}
		}
		fclose(fptr);
	}
	else if (z == 2)						//VÝPIS MATIC PO NÁSOBENÍ SKALÁREM
	{
		fopen64(&fptr, "historie.txt", "a");
		fopen()
		fopen(&fptr, "historie.txt", "a");
		fprintf(fptr, "\nVysledek prvni matice je:");
		for (int i = 0; i < m; i++)			
		{
			fprintf(fptr, "\n");
			for (int j = 0; j < n; j++) {
				fprintf(fptr, "(%d) ", mat[i][j]);
			}
		}
		fclose(fptr);
	}
	else if (z == 3) {							//VÝPIS VÝSLEDNÉ MATICE DO HISTORIE 
		fopen(&fptr, "historie.txt", "a");
		fprintf(fptr, "\nVysledek je:");
		for (int i = 0; i < m; i++)
		{
			fprintf(fptr, "\n");
			for (int j = 0; j < n2; j++) {
				fprintf(fptr, "(%d)", matv[i][j]);
			}
		}
		fclose(fptr);
	}
	else if (z == 4) {							//VÝPIS TRANSPONOVANÝCH MATIC DO HISTORIE
		fopen(&fptr, "historie.txt", "a");
		fprintf(fptr, "\nVysledek prvni transponované matice je:");
		for (int i = 0; i < n; i++)			//VÝPIS MATICE1 TRANSPONOVANÉ 
		{
			fprintf(fptr, "\n");
			for (int j = 0; j < m; j++) {
				fprintf(fptr, "(%d) ", mat[j][i]);
			}
		}
		fclose(fptr);
	}
	else if (z == 5) {
		fopen(&fptr, "historie.txt", "a");
		fprintf(fptr, "\nDeterminant matice je %d", vys);
		fclose(fptr);
	}

	*/
	return 0;
}
	