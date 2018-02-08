CC=c89

main: clean main.o
	$(CC) main.o -lc -o main

clean:
	-@rm -f main
	-@rm -f main.o 
