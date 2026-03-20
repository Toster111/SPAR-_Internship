#include <stdio.h>

int main(int argc, char * argv[]) {

	// Искомая последовательность - возрастающая последовательность 
	// с максимальной суммой её элементов и максимальной длиной.

    int sum = 0; // Текущая сумма последовательности
    int max_count = 0; // Длина искомой последовательности
    int max_sum = 0; // Сумма искомой последовательности
    int start_counter = 1; // Начало текущей последовательности
    int stop_counter = 0; // Конец текущей последовательности
    int current_length = 0; // Промежуточная длина текущей последовательности
    int final_start = 1; // Начало искомой последовательности
    int final_stop = 0; // Конец искомой последовательности

    printf("Введите массив: \n");

    sum = argv[1][0] - '0'; // Первый элемент последовательности не учитывается в цикле
    
    for (int i = 2; i < argc; i++) { // Проход по последовательности
    
        if (argv[i - 1][0] > argv[i][0]) { // Проверка условия
            stop_counter = i - 1;
            current_length = stop_counter - start_counter;
            
            int temp_start = start_counter;
            int temp_stop = stop_counter;
            
            if (sum > max_sum || (sum == max_sum && max_count < current_length)) { // Сравнение с текущими макс. элем. 
                max_sum = sum;
                max_count = current_length;
                final_start = temp_start;
                final_stop = temp_stop;
            }
            
            sum = argv[i][0] - '0';
            start_counter = i; // Началась новая последовательность   
        } else {
            sum += argv[i][0] - '0';
        }
    }

    stop_counter = argc - 1;
    current_length = stop_counter - start_counter;

    // Тестовый вывод
    
    if (sum > max_sum || (sum == max_sum && max_count < current_length)) {
        printf("%d \n", sum);
        printf("%s \n", argv[start_counter]);
        printf("%s \n", argv[stop_counter]);
        printf("%d \n", current_length);
    } else {
        printf("%d \n", max_sum);
        printf("%s \n", argv[final_start]);
        printf("%s \n", argv[final_stop]);
        printf("%d \n", max_count);
    }
    
    return 0;
}
