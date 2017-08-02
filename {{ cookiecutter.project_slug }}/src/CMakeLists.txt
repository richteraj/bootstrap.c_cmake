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

configure_file (
    ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/config.h
    ESCAPE_QUOTES @ONLY)

add_custom_target (config_h
    COMMENT "Updating config.h"
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/config.h.in)

include_directories (${CMAKE_CURRENT_BINARY_DIR})
add_definitions (-DHAVE_CONFIG_H=1)

add_executable ({{ cookiecutter.pkg_name }} {{ cookiecutter.pkg_name }}.c)
add_dependencies ({{ cookiecutter.pkg_name }} config_h)

# Gather other sources into a lib
# TODO Change to fit the project
file (GLOB srcs *.c)
list (REMOVE_ITEM srcs {{ cookiecutter.pkg_name }}.c)
add_library ({{ cookiecutter.pkg_name }}lib SHARED ${srcs})
target_link_libraries ({{ cookiecutter.pkg_name }} {{ cookiecutter.pkg_name }}lib)
add_dependencies ({{ cookiecutter.pkg_name }}lib config_h)

install(
    TARGETS {{ cookiecutter.pkg_name }} {{ cookiecutter.pkg_name }}lib
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib/static)
