all:
	gcc randFile.c -o randFile

clean: all
	rm randFile
	rm *.txt
	rm *~

run: all
	./randFile
