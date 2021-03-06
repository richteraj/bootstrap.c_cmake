bootstrap.c_cmake
========================================================================

[![Travis CI build status][travis_img]][travis_link]

[travis_img]: https://travis-ci.org/richteraj/bootstrap.c_cmake.svg?branch=master
[travis_link]: https://travis-ci.org/richteraj/bootstrap.c_cmake

This is a template for projects in C with the build process managed by
CMake.

Usage
------------------------------------------------------------------------

The project template instantiating is done by [cookiecutter][], a Python
program which creates projects from templates.  After installing this (e.g.
with `pip install cookiecutter`), You can create a new project with:

    cookiecutter https://github.com/richteraj/bootstrap.c_cmake.git

Then set up a Git repository:

    cd the-project
    git init
    git add .
    git commit -m "Initial commit"

You can use the following command to list all things to be done:

    git grep -n "TODO:[0-9]\+"

### Build

To configure (defaults to debug build type) and build the project use:

    mkdir build-dir
    cd buil-dir
    cmake ..
    cmake --build . --target

You can adjust the configuration by editing the `CMakeCache.txt` file inside
the build directory.  Alternatively You can use a program like `ccmake` or
`cmake-gui` to edit this file.

There is a `configure` script which will generate a Makefile so the standard
procedure is possible:

    ./configure
    make
    sudo make install

This Makefile simply forwards common targets to the build directory (provided
CMake uses UNIX Makefiles).  The name of the build directory can be changed
with the `BUILD_DIR` environment variable.
The default build type (`CMAKE_BUILD_TYPE` variable) via `configure` is
release.

### Documentation

You can generate automatic documentation with [Doxygen][] by manually invoking
the `doc` target:

    cmake --build build-dir --target doc

or

    make doc

### Testing

All C and shell source files inside the `tests` directory are automatically
added as a test and bundled into the `test` target.  You can run the tests
with

    cmake --build build-dir --target test

or with `make test` or with `ctest` directly.  The `test` target only executes
the tests, the building has to be done separately.

To facilitate testing with [Travis CI][travis] there is a `.travis.yml` file
provided.

### Release

You can create a source tarball with:

    make dist

This uses the CPack module.  Make sure your working directory is clean or
unwanted files may be included in the tarball.


[cookiecutter]: https://github.com/audreyr/cookiecutter
[Doxygen]: https://www.stack.nl/~dimitri/doxygen/index.html
[travis]: https://travis-ci.org/

________________________________________________________________________

Copyright 2017 A. Johannes RICHTER

Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.3
or any later version published by the Free Software Foundation;
with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
Texts.  A copy of the license is included in the section entitled "GNU
Free Documentation License".
