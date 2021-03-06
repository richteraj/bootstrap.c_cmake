# Compiled tests
file (GLOB srcs test_*.c)
foreach (test_source IN LISTS srcs)
    get_filename_component (test_target ${test_source} NAME_WE)
    add_executable (${test_target} ${test_source})
    target_link_libraries (${test_target} {{ cookiecutter.pkg_name }}_testlib)
    target_include_directories (${test_target} PRIVATE ${src_DIR})

    add_test (NAME ${test_target} COMMAND ${test_target})
endforeach (test_source)

# Tests with shell scripts
find_program (sh_PROG sh)
if (NOT sh_PROG STREQUAL "sh_PROG-NOTFOUND")
    set (shminitests_sh "${CMAKE_CURRENT_SOURCE_DIR}/shminitests.sh")
    file (GLOB srcs test_*.sh)
    foreach (test_sh_script IN LISTS srcs)
        get_filename_component (test_target ${test_sh_script} NAME_WE)
        add_test (NAME "${test_target}_sh"
            COMMAND ${sh_PROG} ${test_sh_script} ${shminitests_sh})
    endforeach (test_sh_script)
else ()
    message (WARNING "Can't test shell scripts: program 'sh' not found")
endif ()

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

