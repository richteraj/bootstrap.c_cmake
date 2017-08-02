# CMakeLists.txt - CMake tests files
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

include_directories (${CMAKE_BINARY_DIR}/src ${CMAKE_SOURCE_DIR}/src)
# TODO Keep if tests library necessary
# add_library (testutils testutils.c)

file (GLOB srcs test_*.c)
foreach (test_source IN LISTS srcs)
    get_filename_component (test_target ${test_source} NAME_WE)
    add_executable (${test_target} ${test_source})
    # TODO Add testutils lib if present
    target_link_libraries (${test_target} {{ cookiecutter.pkg_name }}lib)
    add_test (${test_target} ${test_target})
endforeach (test_source)
