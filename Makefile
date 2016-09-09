RM=\rm
CC=g++
MKDIR=\mkdir

all: clean compile unit-test link functional-test

clean: .clean-out-dir

.clean-out-dir:
	if [ -d out ]; then ${RM} -rf out; fi

compile: .make-out-dir
	${CC} -c -o out/fib_heap.o fib_heap.cpp

.make-out-dir:
	${MKDIR} -p out

unit-test:
	echo "Haven't decided how to unit test, yet!"

link:
	${CC} -o out/fib_heap out/fib_heap.o

functional-test:
	test/functional/run.sh
