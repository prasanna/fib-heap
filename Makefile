# Program specific variables
OUTPUT_DIR=out
SRC_DIR=src
INCLUDE_DIR=include
UNITTEST_SRC_DIR=test/unit
UNITTEST_OBJ_DIR=${OUTPUT_DIR}/unittests
PROGRAM=${OUTPUT_DIR}/fib_heap
SRC_FILES=main.cpp fib_heap.cpp

# Google Test location
GTEST_DIR=../googletest/googletest

# Commands
RM=\rm
CXX=g++
MKDIR=\mkdir
AR=\ar

# Generic variables
SRCS=$(addprefix ${SRC_DIR}/,${SRC_FILES})
OBJS=$(addprefix ${OUTPUT_DIR}/,$(SRC_FILES:.cpp=.o))
SRC_FILES_WITHOUT_MAIN=$(subst main.cpp,,${SRC_FILES})
OBJS_WITHOUT_MAIN=$(addprefix ${OUTPUT_DIR}/,$(SRC_FILES_WITHOUT_MAIN:.cpp=.o))
UNITTEST_SRCS=$(addprefix ${UNITTEST_SRC_DIR}/,$(SRC_FILES_WITHOUT_MAIN:.cpp=_unittest.cpp))
UNITTEST_OBJS=$(addprefix ${UNITTEST_OBJ_DIR}/,$(SRC_FILES_WITHOUT_MAIN:.cpp=_unittest.o))

# GTEST variables that probably don't need to be changed
GTEST_CPPFLAGS=${CPPFLAGS} -isystem ${GTEST_DIR}/include
GTEST_CXXFLAGS=${CXXFLAGS} -g -Wall -Wextra -pthread
GTEST_ARFLAGS=${ARFLAGS}
GTEST_HEADERS= ${GTEST_DIR}/include/gtest/*.h \
               ${GTEST_DIR}/include/gtest/internal/*.h
GTEST_SRCS_=${GTEST_DIR}/src/*.cc ${GTEST_DIR}/src/*.h ${GTEST_HEADERS}


all: ${OUTPUT_DIR} ${PROGRAM} test

clean:
	if [ -d out ]; then ${RM} -rf ${OUTPUT_DIR}; fi

${OUTPUT_DIR}:
	${MKDIR} -p out

${OUTPUT_DIR}/main.o: ${SRC_DIR}/main.cpp
	${CXX} -I${INCLUDE_DIR} -Wall -c $< -o $@

${OUTPUT_DIR}/%.o : ${SRC_DIR}/%.cpp
	${CXX} -I${INCLUDE_DIR} -Wall -c $< -o $@

${PROGRAM}: $(OBJS)
	${CXX} -Wall $^ -o $@

${UNITTEST_OBJ_DIR}/gtest-all.o: ${GTEST_SRCS_}
	${CXX} ${GTEST_CPPFLAGS} -I${INCLUDE_DIR} -I${GTEST_DIR} ${GTEST_CXXFLAGS} -c ${GTEST_DIR}/src/gtest-all.cc -o $@

${UNITTEST_OBJ_DIR}/gtest_main.o: ${GTEST_SRCS_}
	${CXX} ${GTEST_CPPFLAGS} -I${INCLUDE_DIR} -I${GTEST_DIR} ${GTEST_CXXFLAGS} -c ${GTEST_DIR}/src/gtest_main.cc -o $@

${UNITTEST_OBJ_DIR}/gtest_main.a: ${UNITTEST_OBJ_DIR}/gtest-all.o ${UNITTEST_OBJ_DIR}/gtest_main.o
	${AR} ${ARFLAGS} $@ $^

${UNITTEST_OBJ_DIR}:
	mkdir -p ${UNITTEST_OBJ_DIR}


${UNITTEST_OBJ_DIR}/fib_heap_unittest.o: ${UNITTEST_SRC_DIR}/fib_heap_unittest.cpp
	${CXX} ${GTEST_CPPFLAGS} ${GTEST_CXXFLAGS} -c $^ -o $@

${UNITTEST_OBJ_DIR}/%_unittest.o: ${UNITTEST_SRC_DIR}/%_unittest.cpp
	${CXX} ${GTEST_CPPFLAGS} ${GTEST_CXXFLAGS} -c $^ -o $@

${OUTPUT_DIR}/run_unittests: $(OBJS_WITHOUT_MAIN) $(UNITTEST_OBJS) ${UNITTEST_OBJ_DIR}/gtest_main.a
	${CXX} ${GTEST_CPPFLAGS} ${GTEST_CXXFLAGS} -lpthread $^ -o $@

unit-test: ${UNITTEST_OBJ_DIR} ${GTEST_HEADERS} ${OUTPUT_DIR}/run_unittests
	out/run_unittests

functional-test:
	test/functional/run.sh

test: unit-test functional-test
