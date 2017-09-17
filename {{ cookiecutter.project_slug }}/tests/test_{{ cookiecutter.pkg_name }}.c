#include <assert.h>

#include "{{ cookiecutter.pkg_name }}.h"
#include "cminitests.h"

#undef cmt_set_up
void
cmt_set_up (void)
{
    /* TODO Set-up for every test case. */
}
#undef cmt_tear_down
void
cmt_tear_down (void)
{
    /* TODO Tear-down for every test case. */
}

/* TODO Add test cases */
char *
this_test_will_fail (void)
{
    require (0 > 1, "TODO Fill in the tests for {{ cookiecutter.pkg_name  }}.");
    return NULL;
}

void
all_tests (void)
{
    CMT_TEST_CASE (this_test_will_fail,)
}

CMT_RUN_TESTS (all_tests)

/* test_{{ cookiecutter.pkg_name }}.c -- tests for {{ cookiecutter.pkg_name }}.c
   Copyright {{cookiecutter.year}} {{cookiecutter.full_name}} <{{cookiecutter.email}}>

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


