#include <stdio.h>
#include <stdlib.h> //чтобы пользоваться функцией rand

int searching (int sym, int len_stb, int array[][len_stb], int len_str) {

    for (int i = 0; i < len_str; i++) {
        for (int j = 0; j < len_stb; j++) {
            if (sym == array[i][j]) {
                printf ("Stroka is %d\n" , i+1);
                printf ("Stolbik is %d", j+1); 

            }
        }
    }    

    return 0;
} 

int main () {
    int array[3][2] = {{0, 0}, {0, 0}, {0, 0}};
    int len_str = sizeof(array)/sizeof(array[0]);
    int len_stb = sizeof(array[0])/sizeof(array[0][0]);
    int sym; 
    printf ("Array is: \n");
    for (int i = 0; i < len_str; i++) {
        for (int j = 0; j < len_stb; j++) {
            array[i][j] = rand()%100; //числа меньше 100 
            printf ("%d  ", array[i][j]);
        }
        printf ("\n");
    }
    printf ("Select the search item: ");
    scanf ("%d", &sym);
    searching (sym, len_stb, array, len_str);
    return 0;
}