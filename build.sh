gcc -c example.c -o example.o &&
gcc -c List.c -o List.o &&

gcc example.o List.o -o myapp &&
rm example.o
rm List.o
./myapp
rm myapp