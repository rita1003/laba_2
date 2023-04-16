#include <stdio.h> 

int main() {
    char sym;
    char array[5] = {'H', 'e', 'l', 'l', 'o'};
    int len = sizeof(array)/sizeof(array[0]); //длина массива 
    printf ("Enter your symbol: \n");
    scanf ("%d", &sym); 
    printf ("%d", max_count (sym, array, len));

    return 0;
}

int max_count(char sym, char array, int len) {
    //как работает функция: 
    //имеется 2 переменные count_1 и count_2, равные 0. суть программы - вывод максимальной
    //последовательности. количество элементов последовательности записывается в count_1.
    //как только последовательность заданного элемента прекращается, значение из count_1
    //перебрасывается в count_2, а count_1 обнуляется. как только начинается новая
    //последовательность, количество элементов опять записывается в count_1. и потом, когда
    //последовательность вновь заканчивается, уже сравнивается количество элементов в 
    //count_1 и count_2. если в count_2 количество элементов больше, то count_1 обнуляется
    //и count_2 не меняется. если в count_2 количество элементов меньше, то значение из 
    //count_1 записывается в count_2, а count_1 обнуляется. 

    int count_1 = 0;
    int count_2 = 0; 

    for (int i = 0; i<len; i++) {
        if (array[i] == sym) {
            count_1++;
        }
        if (array[i] != sym) {
            if (count_1 != 0) {
                if (count_1 > count_2) {
                    count_2 = count_1;
                    count_1 = 0;
                }
                if (count_1 < count_2) {
                    count_1 = 0;
                }
            }
        }

    }
    return count_2; 
}