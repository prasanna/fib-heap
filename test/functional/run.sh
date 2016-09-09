#!/usr/bin/env bash

COMMAND_NAME="fib_heap"

FUNCTIONAL_TEST_BASE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
FUNCTIONAL_TEST_DIRS=`find ${FUNCTIONAL_TEST_BASE_DIR} -type d -d 1 -name "*functional_test_*"`

COMMAND_TO_TEST="${FUNCTIONAL_TEST_BASE_DIR}/../../out/${COMMAND_NAME}"

EXIT_CODE=0

for FUNCTIONAL_TEST_DIR in "${FUNCTIONAL_TEST_DIRS}"
do
    rm -f ${FUNCTIONAL_TEST_DIR}/actual_output.txt
    ${COMMAND_TO_TEST} < ${FUNCTIONAL_TEST_DIR}/input.txt > ${FUNCTIONAL_TEST_DIR}/actual_output.txt

    diff ${FUNCTIONAL_TEST_DIR}/actual_output.txt ${FUNCTIONAL_TEST_DIR}/expected_output.txt
    DIFF_EXIT_CODE=$?

    if [[ 0 != ${DIFF_EXIT_CODE} ]]; then
	echo "< ACTUAL"
	echo "> EXPECTED"
    
	echo "*** TEST ${FUNCTIONAL_TEST_DIR} FAILED ***"
	EXIT_CODE=1
    fi
done

if [[ 0 = ${EXIT_CODE} ]]; then
    echo "Functional Tests PASS"
fi

exit ${EXIT_CODE}
