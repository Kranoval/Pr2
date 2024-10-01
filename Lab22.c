#include <stdio.h>
#include <stdlib.h>
#include <time.h>

double shell(int *items, int count) {
    int gap;

    time_t start = clock();

    for (gap = count / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < count; ++i) {
            int temp = items[i];
            int j = i - gap;

            while ((j >= 0) && (items[j] > temp)) {
                items[j + gap] = items[j];
                j -= gap;
            }

            items[j + gap] = temp;
        }
    }

    time_t end = clock();

    double time = difftime(end, start) / CLOCKS_PER_SEC;

    return time;
}

double qs(int *items, int left, int right) {
    int i, j;
    int x, y;

    i = left; j = right;

    time_t start = clock();

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j);
    if (j < right) qs(items, i, right);

    time_t end = clock();

    double time = difftime(end, start) / CLOCKS_PER_SEC;

    return time;
}

int main()
{
    int x, y, z;
    printf("Enter the sizes of the 3 arrays:\n 1 - ");
    scanf("%d", &x);
    printf("\n 2 - ");
    scanf("%d", &y);
    printf("\n 3 - ");
    scanf("%d", &z);
    double time_qx, time_qy, time_qz, time_sx, time_sy, time_sz;
    int h;
    int i = 0;
    int* a = (int*)calloc(x, sizeof(int));
    int* b = (int*)calloc(y, sizeof(int));
    int* c = (int*)calloc(z, sizeof(int));
    int elem_c = 0;
    srand(time(NULL));
    while (1) {
        printf("Select the algoritm operation mod:\n 1 - Random filling of the array.\n 2 - Filling the array in ascending order.\n 3 - Filling the array in descending order.\n 4 - Filling the array first in ascending order, then in descending order.\n");
        scanf(" %d", &h);
        switch (h) {
            case 1: {
                for(i = 0; i < x; i++) {
                    a[i] = rand() % 10000;
                }
                for(i = 0; i < y; i++) {
                    b[i] = rand() % 10000;
                }
                for(i = 0; i < z; i++) {
                    c[i] = rand() % 10000;
                }
                printf(" Array filling completed.\n");
                break;
            }
            case 2: {
                for (i = 0; i < x; i++) {
                    a[i] = i;
                }
                for (i = 0; i < y; i++) {
                    b[i] = i;
                }
                for (i = 0; i < z; i++) {
                    c[i] = i;
                }
                printf(" Array filling completed.\n");
                break;
            }
            case 3: {
                for (i = 0; i < x; i++) {
                    a[i] = x - i;
                }
                for (i = 0; i < y; i++) {
                    b[i] = y - i;
                }
                for (i = 0; i < z; i++) {
                    c[i] = z - i;
                }
                printf(" Array filling completed.\n");
                break;
            }
            case 4: {
                for (i = 0; i < (x / 2); i++) {
                    a[i] = i;
                }
                for (i = (x / 2); i < x; i++) {
                    a[i] = x - i;
                }
                for (i = 0; i < (y / 2); i++) {
                    b[i] = i;
                }
                for (i = (y / 2); i < y; i++) {
                    b[i] = x - i;
                }
                for (i = 0; i < (z / 2); i++) {
                    c[i] = i;
                }
                for (i = (z / 2); i < z; i++) {
                    c[i] = x - i;
                }
                printf(" Array filling completed.\n");
                break;
            }
            default: {
                printf("ERROR - You must select from the provided list.\n");
                break;
            }
        }

        if ((h > 0) && (h < 5)) {
            time_sx = shell(a, x);
            time_sy = shell(b, y);
            time_sz = shell(c, z);
            printf("\n Time to sort the arrays:\n 1 - %f", time_sx);
            printf("\n 2 - %f", time_sy);
            printf("\n 3 - %f", time_sz);
            time_qx = qs(a, 0, x - 1);
            time_qy = qs(b, 0, y - 1);
            time_qz = qs(c, 0, z - 1);
            printf("\n Quicksort time for arrays:\n 1 -  %f", time_qx);
            printf("\n 2 -  %f", time_qy);
            printf("\n 3 -  %f", time_qz);
            break;
        }
    }
    
    free(a);
    free(b);
    free(c);

    return 0;
}


/*Вывод: Мы научились проводить оченку времени выполнения программ и их отдельных частей.*/