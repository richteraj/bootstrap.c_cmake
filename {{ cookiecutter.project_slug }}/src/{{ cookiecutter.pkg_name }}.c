/*
   {{ cookiecutter.pkg_name }}.c -- {{ cookiecutter.project_short_description }}
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

#include "{{ cookiecutter.pkg_name }}.h"

int
main (int argc, char *argv[])
{
  print_version (stdout);
  return 0;
}

void
print_version (FILE *ostr)
{
  fprintf (ostr, "%s (%s)\n", PROJECT_NAME, PROJECT_VERSION);
  fprintf (ostr, "Copyright %s %s\n", PROJECT_COPY_YEARS, PROJECT_AUTHORS);
  fprintf (ostr,
"License GPLv3+: "
    "GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>\n"
"This is free software: you are free to change and redistribute it.\n"
"There is NO WARRANTY, to the extent permitted by law.\n"
          );
}
