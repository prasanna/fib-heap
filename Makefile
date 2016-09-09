# Program specific variables
OUTPUT_DIR=out
SRC_DIR=src
PROGRAM=${OUTPUT_DIR}/fib_heap
SRC_FILES=fib_heap.cpp

# Commands
RM=\rm
CXX=g++
MKDIR=\mkdir

# Generic variables
SRCS=$(addprefix ${SRC_DIR}/,${SRC_FILES})
OBJS=$(addprefix ${OUTPUT_DIR}/,$(SRC_FILES:.cpp=.o))


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
	echo $^
	${CXX} -Wall -c $< -o $@

${PROGRAM}: $(OBJS)
	echo $^
	${CXX} -Wall $^ -o $@
