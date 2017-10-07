#!/bin/sh

sh_mini_tests="$1"
. "$sh_mini_tests"

tests_start

# TODO:320 Add test cases between tests_start and tests_end.

# TODO:321 Tests using evaluate_test and explicitly setting test_case.
test_case="This test will fail"
false
evaluate_test "TODO Fill in the tests for {{ cookiecutter.pkg_name  }}.sh"

# TODO:322 Tests using execute_test_case with test case functions.
This_test_will_also_fail ()
{
    return 42
}

execute_test_case This_test_will_also_fail "" "TODO Make the tests green..."

tests_end

