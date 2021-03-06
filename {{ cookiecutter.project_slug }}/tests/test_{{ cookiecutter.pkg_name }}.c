/** \file
 * Tests for {{ cookiecutter.pkg_name }}.c.  */

#include "{{ cookiecutter.pkg_name }}.h"
#include "cminitests.h"

#undef cmt_set_up
void
cmt_set_up ()
{
    // TODO:301 Set-up for every test case.
}

#undef cmt_tear_down
void
cmt_tear_down ()
{
    // TODO:302 Tear-down for every test case.
}

// TODO:310 Add test cases.
char *
this_test_will_fail ()
{
    require (0 > 1, "TODO Fill in the tests for {{ cookiecutter.pkg_name  }}.c");
    return NULL;
}

void
all_tests ()
{
    CMT_TEST_CASE (this_test_will_fail,)
}

CMT_RUN_TESTS (all_tests)

/* Copyright {{cookiecutter.year}} {{cookiecutter.full_name}} <{{cookiecutter.email}}>

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


