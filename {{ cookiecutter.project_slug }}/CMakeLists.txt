cmake_minimum_required (VERSION 3.0)

set (CMAKE_BUILD_TYPE Debug CACHE STRING
    "Debug, Release, RelWithDebInfo or MinSizeRel")

project ({{ cookiecutter.project_slug }} VERSION 0.1.0 LANGUAGES C)
set (PROJECT_AUTHORS "{{ cookiecutter.full_name }}")
set (PROJECT_COPY_YEARS "{{ cookiecutter.year }}")

set (src_DIR ${PROJECT_SOURCE_DIR}/src)
set (tests_DIR ${PROJECT_SOURCE_DIR}/tests)
set (doc_DIR ${PROJECT_SOURCE_DIR}/doc)
set (bin_DIR ${PROJECT_SOURCE_DIR}/bin)
set (lib_DIR ${PROJECT_SOURCE_DIR}/lib)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${bin_DIR})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${lib_DIR})

include (CTest)

set (CMAKE_C_STANDARD 99)
set (CMAKE_C_STANDARD_REQUIRED ON)

add_compile_options (-Wall -Wextra -Wpedantic -O3)
if (CMAKE_C_COMPILER_ID STREQUAL Clang)
    add_compile_options (-Wno-missing-prototypes
        $<$<CONFIG:Debug>:-O2>
        $<$<CONFIG:Debug>:-Weverything>
        $<$<CONFIG:Debug>:-Wno-padded>
        $<$<CONFIG:Debug>:-Wno-disabled-macro-expansion>)
elseif (CMAKE_C_COMPILER_ID STREQUAL GNU)
    add_compile_options (
        $<$<CONFIG:Debug>:-Og> $<$<CONFIG:Debug>:-Wformat=2>)
endif ()
add_definitions (-D_GNU_SOURCE)
set (CMAKE_EXPORT_COMPILE_COMMANDS 1)


add_subdirectory (${src_DIR})
add_subdirectory (${tests_DIR})
add_subdirectory (${doc_DIR})


set (CPACK_PACKAGE_CONTACT ${PROJECT_AUTHORS})
set (CPACK_PACKAGE_DIRECTORY "${PROJECT_SOURCE_DIR}/dist")
set (CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
set (CPACK_SOURCE_GENERATOR "TBZ2")
# TODO:550 Add files which should not be included in the source tar ball.
set (CPACK_SOURCE_IGNORE_FILES
    "${CMAKE_CURRENT_BINARY_DIR}/" "${CPACK_PACKAGE_DIRECTORY}/"
    "\\\\.swp$" "~$"
    "${CPACK_SOURCE_IGNORE_FILES}")
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
set (CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
include (CPack)

# TODO Remark: CPack does not fully quote (only white space) the paths for the
# package_source target.  Therefore paths with special shell characters like '('
# and ')' will make the build fail.
add_custom_target (dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source)


# Summary
message ("\n-- Summary:")
message ("Project ${PROJECT_NAME} (${PROJECT_VERSION}):")
message ("  src:           ${PROJECT_SOURCE_DIR}")
message ("  build:         ${PROJECT_BINARY_DIR}")
message ("  build type:    ${CMAKE_BUILD_TYPE}")
message ("C compiler:      ${CMAKE_C_COMPILER_ID} (${CMAKE_C_COMPILER})")
get_property (compile_flags DIRECTORY PROPERTY COMPILE_OPTIONS)
message ("  Flags:         ${compile_flags}")
get_property (compile_defs DIRECTORY PROPERTY COMPILE_DEFINITIONS)
message ("  -D:            ${compile_defs}")

# CMakeLists.txt -- global project configuration
# Copyright 2017 A. Johannes RICHTER <albrechtjohannes.richter@gmail.com>
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

