shared:
	gcc -shared *.c -o libnetutils.so

static:
	gcc -c *.c 
	ar rcs libnetutils.a *.o
	rm *.o
