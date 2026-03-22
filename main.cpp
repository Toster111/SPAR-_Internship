#include <iostream>


// AND OR NOT

#include <cstring>

int main() {
    std::istream& in = std::cin; // Чтобы было удобнее работать с потоком

    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE]; // Буфер для чтения потока
    char symbol{};
    unsigned int len_array{0};

    unsigned int staples_l = 0;
    unsigned int staples_r = 0;

    // Читаем первый символ
    in.get(symbol);

    // Пока не встретили перевод строки и поток не закончился
    while (symbol != '\n' && !in.eof()) {
        ++len_array;
        buffer[len_array] = symbol;
        if (symbol == '(') {
            ++staples_l;
        }

        if (symbol == ')') {
            ++staples_r;
        }

        in.get(symbol);
    }

	unsigned int counter = 0;

	const int NEW_BUFFER_SIZE = 1024;
    char new_buffer[NEW_BUFFER_SIZE];

	char * token = strtok(buffer, ")");

	//while (token != nullptr)





    return 0;
}
