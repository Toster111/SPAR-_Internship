# Базовая компиляция

CC = gcc
CFLAGS = -Wall -Wextra -g

# Цель
all: task9

# Сборка
task9: task9.c
	$(CC) $(CFLAGS) -o task9 task9.c

# Очистка
clean:
	rm -f task9


