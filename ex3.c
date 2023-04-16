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
    int new_arr[size]; //массив для копирования старого массива
    for (int j = 0; j < size; j++) {
        new_arr[j] = *(array+j);
    }
    array = realloc (array, sizeof(int) * (size+1));
    printf ("Введите, какое число вы хотите добавить в середину массива: ");
    scanf ("%d", &new);
    printf ("Ваш массив: \n");
    for (int i = size/2; i < (size+1); i++) {
        if (i == size/2) {
            *(array+i) = new;
        }
        else {
            *(array+i) = new_arr[i-1];
        }
    }
    for (int k = 0; k < (size+1); k++) {
        printf("%d\n", array[k]);
    }
    return 0;
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
        if (searching == 3) {
            insert(array, size);
            size++;
        }
    } while (searching != 0); 

    return 0;

    /* Числа для тестовых проверок:
    1. Для функции append (size = любой):
    1.1. Число -10 - для проверки работы с отрицательным числом
    1.2. Число 2423423 - для проверки работы с очень большим положительным числом
    1.3. Число, уже существующее в массиве (напр. 41) - как реагирует на уже существующее число?
    1.4. Число 10 - для проверки работы с положительным числом 
    1.5. Число -2423423 - для проверки работы с очень большим отрицательным числом 
    
    2. Для функции insert (size кроме 2.4 и 2.5 пункта любой):
    2.1. Число -10 - для проверки работы с отрицательным числом
    2.2. Число 2423423 - для проверки работы с очень большим числом
    2.3. Число, уже существующее в массиве (напр. 41) - как реагирует на уже существующее число?
    2.4. Любое число (напр. 3) и size четное (напр. 6) - посмотреть, куда будет помещено число
    2.5. Любое число (напр. 3) и size нечетное (напр. 5) - посмотреть, куда будет помещено число
    */
}
