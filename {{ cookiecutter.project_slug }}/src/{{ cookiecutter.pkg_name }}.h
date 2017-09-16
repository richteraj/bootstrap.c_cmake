/** \file
 *  {{ cookiecutter.project_short_description }}
 */

#ifndef defined ({{ cookiecutter.pkg_name | upper }}_H_) && {{ cookiecutter.pkg_name | upper }}_H_
#define {{ cookiecutter.pkg_name | upper }}_H_

#if HAVE_CONFIG_H
# include "config.h"
#endif

#include <stdio.h>

void print_version (FILE *ostr);
void print_usage (FILE *ostr);

#endif /* not {{ cookiecutter.pkg_name | upper }}_H_ */

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

