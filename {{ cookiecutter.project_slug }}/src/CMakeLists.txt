configure_file (
    "config.h.in"
    "${CMAKE_CURRENT_BINARY_DIR}/config.h"
    ESCAPE_QUOTES @ONLY)

# TODO:501 Add targets and set dependencies.
add_executable ({{ cookiecutter.pkg_name }}
    {{ cookiecutter.pkg_name }}.c
    "${CMAKE_CURRENT_BINARY_DIR}/config.h")
target_include_directories ({{ cookiecutter.pkg_name }}
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_compile_definitions ({{ cookiecutter.pkg_name }}
    PRIVATE "-DHAVE_CONFIG_H=1")

# Gather sources into a lib for testing purposes
# TODO:510 This is quick and dirty with globbing
file (GLOB srcs *.c)
add_library ({{ cookiecutter.pkg_name }}_testlib STATIC ${srcs})
target_include_directories ({{ cookiecutter.pkg_name }}_testlib
    PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
target_compile_definitions ({{ cookiecutter.pkg_name }}_testlib
    PRIVATE "-DHAVE_CONFIG_H=1")
# TODO:511 Add libraries.

# TODO:520 Add install targets.
install(
    TARGETS {{ cookiecutter.pkg_name }}
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib)

# CMakeLists.txt - CMake source files
# Copyright {{cookiecutter.year}} {{cookiecutter.full_name}} <{{cookiecutter.email}}>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

