default:
	clang mem.c -O0 -o mem
	./mem

fmt:
	clang-format --verbose --sort-includes -i mem.c
