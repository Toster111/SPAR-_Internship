#include <iostream>
#include <cstring>

int main() {
    std::istream& in = std::cin; // Чтобы было удобнее работать с потоком

    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE] = {0}; // Буфер для чтения потока (обнуляем)
    char symbol{};
    unsigned int len_array = 0; // инициализируем нулём

    unsigned int staples_l = 0;
    unsigned int staples_r = 0;

    // Читаем первый символ
    in.get(symbol);

    // Пока не встретили перевод строки и поток не закончился
    while (symbol != '\n' && !in.eof()) {
        buffer[len_array] = symbol; // сохраняем символ в буфер (было len_array++ после присвоения)
        ++len_array;

        if (symbol == '(') {
            ++staples_l;
        }

        if (symbol == ')') {
            ++staples_r;
        }

        in.get(symbol);
    }

    buffer[len_array] = '\0'; // добавляем null-terminator для strtok

    unsigned int counter = 0; // счётчик переменных

    const int NEW_BUFFER_SIZE = 1024;
    char new_buffer[NEW_BUFFER_SIZE];

    // Копируем buffer в new_buffer, так как strtok модифицирует строку
    strncpy(new_buffer, buffer, len_array);

    char* token = strtok(new_buffer, " )("); // разделители: пробел, скобки

    while (token != nullptr) {
        // Проверяем, является ли токен переменной (одна буква от A до Z)
        if (strlen(token) == 1 && token[0] >= 'A' && token[0] <= 'Z') {
            counter++;
        }
        // Проверяем, не является ли токен оператором
        else if (strcmp(token, "AND") != 0 &&
                 strcmp(token, "OR") != 0 &&
                 strcmp(token, "NOT") != 0) {
        }

        // Проверка токенизации
        std::cout << token << std::endl;

        token = strtok(nullptr, " )(");
    }

    // Проверка
    std::cout << "Скобок открывающих: " << staples_l << std::endl;
    std::cout << "Скобок закрывающих: " << staples_r << std::endl;
    std::cout << "Количество переменных: " << counter << std::endl;

    // Выводим исходное выражение для проверки
    std::cout << "Выражение: " << buffer << std::endl;

    return 0;
}
