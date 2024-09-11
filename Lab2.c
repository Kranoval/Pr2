#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define X 300
#define Y 300

int main()
{
    double start = 0, stop = 0;
    int i = 0, j = 0, r = 0;
    int** a = (int**)calloc(X * Y, sizeof(int*));
    int** b = (int**)calloc(X * Y, sizeof(int*));
    int** c = (int**)calloc(X * Y, sizeof(int*));
    int elem_c = 0;
    srand(time(NULL));
    for (i = 0; i < Y; i++)
    {
        a[i] = (int*)calloc(Y, sizeof(int));
        b[i] = (int*)calloc(Y, sizeof(int));
        c[i] = (int*)calloc(Y, sizeof(int));
    }
    i = 0, j = 0;
    puts("HEllo????");
    start = clock();
    for (i = 0; i < X; i++)
    {
        for (j = 0; j < Y; j++)
        {
            a[i][j] = rand() % 100 + 1;
            b[i][j] = rand() % 100 + 1;
            for (r = 0; r < Y; r++)
            {
                elem_c += a[i][r] * b[i][r];
                c[i][j] = elem_c;
            }
        }
    }
    stop = clock();
    printf("%dx%d = %lf sec.", X, Y, (stop - start)/CLOCKS_PER_SEC);
    free(a);
    free(b);
    free(c);
    return 0;
}
