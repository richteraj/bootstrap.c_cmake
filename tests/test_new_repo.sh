#!/bin/sh

set -o errexit
set -o verbose

# Go to test directory
test_dir="`dirname \"$0\"`"
cd "$test_dir"

test_project="my_new_project"
test_config="./cookiecutterrc"

[ -d "$test_project" ] && rm -fr "$test_project"
cookiecutter --config-file "$test_config" --no-input ..
[ -d "$test_project" ]

cd "$test_project"
./configure
make -s
make -s doc
make -s clean
! make -s test
cmake --build build --target package
make -s clean
make -s dist

exit 0
