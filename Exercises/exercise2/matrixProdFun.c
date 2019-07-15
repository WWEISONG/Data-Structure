#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define M 3
#define N 4
#define P 4

void matrixProduct(float a[M][N], float b[N][P], float c[M][P]);
void showMatrix(float m[][N], int row, int column);

int main(int argc, char *argv[])
{
	char /**test[1],*/ s[6] = {'h', 'e', 'l', 'l', 'o'}; // becareful about char and string when
/*	test[0] = malloc(sizeof(char) * 10);				 // using array to store
	test[0] = "songwei";*/
	for ( int i = 0; i < 6; i++ )
	{
		if ( s[i] != '\0' ){
			printf("%c ", s[i]);
		}
	}

	printf("\n%p", s);

	putchar('\n');
/*	float a[3][4] = {                  // 3 rows and 4 columns
		{1.1, 2.1, 3.1, 4.1},
		{2.1, 3.1, 4.1, 5.1},
		{3.1, 4.1, 5.1, 6.1}
	};

	float b[4][4] = {
		{1.1, 2.1, 3.1, 4.1},
		{2.1, 3.1, 4.1, 5.1},
		{3.1, 4.1, 5.1, 6.1},
		{4.1, 5.1, 6.1, 7.1}
	};

	float c[3][4] = {0};

	matrixProduct(a, b, c);
	showMatrix(c, M, N);
	showMatrixPointer(c, M, N);*/

	return EXIT_SUCCESS;
}

void matrixProduct(float a[M][N], float b[N][P], float c[M][P])
{
	int m = 0, n = 0, p = 0;
	float temp = 0.0;
	for ( m = 0; m < M; m++ )        // every row of a
	{
		for ( p = 0; p < P; p++ )    // every column of b
		{
			temp = 0.0;
			for ( n = 0; n < N; n++ )  // row multiply column
			{
				temp += a[m][n] * b[n][p];
			}

			c[m][p] = temp;          // assign every element to c
		}
	}

	return;
}

void showMatrix(float m[][N], int row, int column)
{
	int i, j;
	for ( i = 0; i < row; i++ )           // print every row
	{
		for ( j = 0; j < column; j++ )    // print every column
		{
			printf("%.3f ", m[i][j]);
		}

		printf("\n");
	}

	return;
}
