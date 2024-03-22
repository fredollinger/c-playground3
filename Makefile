CC=clang

all: stringSort
	echo build all

stringSort:
	${CC} $@.c -o stringSort

clean:
	rm -f stringSort
