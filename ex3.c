#include <stdio.h>
#include <stdlib.h> //чтобы пользоваться функцией rand
#include <malloc.h>

// Выбрала 2 вариант реализации (динамический массив)

 int print (int *array, int size) {
    printf ("Ваш массив:\n");
    for (int i = 0; i < size; i++) {
        printf ("%d\n", *(array+i));
    }
    printf ("\n");
    return 0;
}


int append (int *array, int size) {
    int new;
    array = realloc (array, sizeof(int) * (size+1));
    printf ("Введите, какое число вы хотите добавить в конец массива: ");
    scanf ("%d", &new);
    *(array + size) = new;
    printf ("Ваш массив:\n");
    for (int i = 0; i < (size+1); i++) {
        printf ("%d\n", array[i]);
    }
    printf ("\n");
    return 0;

}

int insert (int *array, int size) {
    int new;
    array = realloc (array, sizeof(int) * (size+1));
    printf ("Введите, какое число вы хотите добавить в середину массива: ");
    scanf ("%d", &new);

}

int main () {
    int size, searching;
    int *array = NULL;
    printf ("Введите размер массива: ");
    scanf ("%d", &size);
    array = malloc(sizeof(int) * size); //выделение памяти
    printf ("Ваш массив: \n");
    for (int i = 0; i < size; i++) {
        *(array+i) = rand()%100;
        printf("%d\n", array[i]);

    }
    do {
        printf ("Выберите, что вы хотите сделать с массивом:\n");
        printf("1. Отобразить массив на экране\n");
        printf("2. Вставить элемент в конец массива\n");
        printf("3. Вставить элемент в середину массива\n");
        printf("Если ничего не хотите, введите 0\n");
        scanf("%d", &searching);
        if (searching == 1) {
            print(array, size);
        }       
       if (searching == 2) {
            append(array, size);
            size++;
        }
/*        if (searching == 3) {
            insert();
        }*/
    } while (searching != 0); 

    return 0;
}