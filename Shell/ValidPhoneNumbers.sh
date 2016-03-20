#! /bin/bash

# Copyright (C) 2016  Mewiteor <mewiteor@hotmail.com>
# 
# This program is free software: you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation, either
# version 3 of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this program.  If not, see
# <http://www.gnu.org/licenses/>.

# Given a text file file.txt that contains list of phone numbers (one per line), write a one liner bash script to print all valid phone numbers.
# 
# You may assume that a valid phone number must appear in one of the following two formats: (xxx) xxx-xxxx or xxx-xxx-xxxx. (x means a digit)
# 
# You may also assume each line in the text file must not contain leading or trailing white spaces.
# 
# For example, assume that file.txt has the following content:
# 
# 987-123-4567
# 123 456 7890
# (123) 456-7890
# Your script should output the following valid phone numbers:
# 987-123-4567
# (123) 456-7890

# Read from the file file.txt and output all valid phone numbers to stdout.
egrep "^(?[[:digit:]]{3}-|\([[:digit:]]{3}\) )[[:digit:]]{3}-[[:digit:]]{4}$" file.txt
