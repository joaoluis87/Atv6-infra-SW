bin: main.c
	gcc main.c -o main -lpthread

run: 
	./main

clean: 
	rm main