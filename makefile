convert: convert.c
	gcc -o convert convert.c convert2.c


ctest: convert.c
	gcc -o ctest --coverage convert.c convert2.c
