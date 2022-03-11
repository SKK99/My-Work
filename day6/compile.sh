gcc -Wall -c hello.c
gcc -Wall -c call.c
gcc -Wall hello.o call.o main.c -o main.out
./main.out
