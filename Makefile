# Commands
RM=\rm
CC=g++
MKDIR=\mkdir

# Program files
OUTPUT_DIR=out
SRC_DIR=src
PROGRAM=${OUTPUT_DIR}/fib_heap
SRCS=${SRC_DIR}/fib_heap.cpp
OBJS_TMP=$(notdir $(SRCS:.cpp=.o))
OBJS=$(addprefix ${OUTPUT_DIR}/,$(OBJS_TMP))


all: ${OUTPUT_DIR} ${PROGRAM} functional-test

clean:
	if [ -d out ]; then ${RM} -rf ${OUTPUT_DIR}; fi

${OUTPUT_DIR}:
	${MKDIR} -p out

unit-test:
	echo "Haven't decided how to unit test, yet!"

functional-test:
	test/functional/run.sh

$(OBJS): $(SRCS)
	${CC} -Wall -c $< -o $@

${PROGRAM}: $(OBJS)
	echo $^
	${CC} -Wall $^ -o $@
