#include <stdio.h>
#include <stdlib.h> //чтобы пользоваться функцией rand

int main () {
    int array[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int sym; 
    printf ("Array is: ");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            array[i][j] = rand()%100; //числа меньше 100 
            printf ("%d  ", array[i][j]);
        }
        printf ("\n");
    }
    printf ("Select the search item: ");
    scanf ("%d", &sym);
    return 0;
}