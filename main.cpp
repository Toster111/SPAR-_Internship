#include <iostream>


// AND OR NOT

#include <iostream>

int main() {
    std::istream& in = std::cin;

    const int BUFFER_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char symbol{};

    // Читаем первый символ
    in.get(symbol);

    // Пока не встретили перевод строки и поток не закончился
    while (symbol != '\n' && !in.eof()) {
		in.unget();
        // Читаем строку до следующего перевода строки
        in.getline(buffer, BUFFER_SIZE);
        std::cout << buffer;

        // Читаем следующий символ для проверки
        in.get(symbol);
    }

    return 0;
}
