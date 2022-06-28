build:
	gcc -std=c11 \
	src/main.c \
	src/vector.c \
	tests/vectorTest.c \
	-o main.exe