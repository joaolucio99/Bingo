all:
	@gcc lib/*.h src/*.c main.c -o main 

run:	
	@./main
	
clean:
	@rm -rf lib/*.gch main
