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


#include <getopt.h>
#include <stdbool.h>
#include <stdlib.h>

#include "{{ cookiecutter.pkg_name }}.h"

int
main (int argc, char *argv[])
{
  int choice;
  while (true)
    {
      int option_index = 0;

      static struct option long_options[] =
      {
        /* Argument styles:
           no_argument, required_argument, optional_argument */
        {"version", no_argument, 0, 'V'},
        {"help",    no_argument, 0, 'h'},
        /* TODO add options here */
        {0, 0, 0, 0}
      };

      /* Argument parameters for an option "o":
        no_argument: "o"
        required_argument: "o:"
        optional_argument: "o::" */
      choice = getopt_long (
        argc, argv, "Vh", long_options, &option_index);

      /* Finished parsing options */
      if (choice == -1)
        break;

      switch (choice)
        {
        case 'V':
          print_version (stdout);
          exit (EXIT_SUCCESS);
          break;

        case 'h':
          print_usage (stdout);
          exit (EXIT_SUCCESS);
          break;

        case '?':
          /* getopt_long will have already printed an error */
          print_usage (stderr);
          exit (EXIT_FAILURE);
          break;

        default:
          fprintf (stderr,
            "?? getopt returned character code 0%o ??\n", choice);
        }
    }

  /* Non-option arguments */
  if (optind < argc)
  {
    while (optind < argc)
      {
        /* TODO deal with arguments */
        ++optind;
      }
  }

  return 0;
}

/* Print version information to `ostr`.  */
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

/* Print usage to `ostr`.  */
void
print_usage (FILE *ostr)
{
  fprintf (ostr, "Usage: %s %s\n", PROJECT_NAME, "[OPTION]... [FILE]...");
  fprintf (ostr, "Short description may be here\n\n");
  fprintf (ostr,
"  -h, --help          display this help and exit\n"
"  -V, --version       output version information and exit\n"
  );
}
