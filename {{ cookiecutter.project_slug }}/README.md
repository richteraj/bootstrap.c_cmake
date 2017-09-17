{{ cookiecutter.project_name }}
========================================================================

{{cookiecutter.project_short_description}}

**TODO**

Prerequisites
------------------------------------------------------------------------

- a GNU compatible C standard library (i.e. the feature test macro
  `_GNU_SOURCE` is required)
- CMake (version 3.0 or newer)

Installation
------------------------------------------------------------------------

Execute the following commands:

    $ ./configure
    $ make
    $ sudo make install

The project build is directed by CMake.  So the `configure` script simply
creates an empty `build` (or the name in the `BUILD_DIR` environment variable)
directory and calls `cmake ..` with `CMAKE_BUILD_TYPE=Release`.  It also
generates a Makefile which forwards the targets into the build dir.

To build directly with CMake use:

    $ mkdir build-dir
    $ cd build-dir
    $ cmake .. -DCMAKE_BUILD_TYPE=Release
    $ cmake --build .
    $ sudo cmake --build . --target install

Generate Doxygen documentation with `make doc` and run tests with `make test`.


**TODO**


Usage
------------------------------------------------------------------------

**TODO** Describe the main usage of the program.

To get further information call `{{ cookiecutter.pkg_name }} --help`.


________________________________________________________________________

Copyright {{cookiecutter.year}} {{cookiecutter.full_name}}

Permission is granted to copy, distribute and/or modify this document
under the terms of the GNU Free Documentation License, Version 1.3
or any later version published by the Free Software Foundation;
with no Invariant Sections, no Front-Cover Texts, and no Back-Cover
Texts.  A copy of the license is included in the section entitled "GNU
Free Documentation License".
