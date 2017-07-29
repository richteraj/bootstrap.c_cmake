#!/usr/bin/env python

# post_gen_project.py -- hooks for cookiecutter
# Copyright 2017 A. Johannes RICHTER <albrechtjohannes.richter@gmail.com>
#
# This file is part of 'bootstrap.c-cmake'.
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


import cookie2cutter.addons.user as user

##
# Vim session and desktop file
#
repo = '{{ cookiecutter.repo_name }}'

try:
    user.create_vim_session(name=repo, path='.', overwrite=False)
except UserWarning:
    print('Session already exists ...skipping!')
    print('Desktop entry may have to be edited')

user.create_desktop(session_name=repo, working_dir='.')

##
# Git set-up.
#
user.git_init_and_commit('.')
