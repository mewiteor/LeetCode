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

# Write a bash script to calculate the frequency of each word in a text file words.txt.
# 
# For simplicity sake, you may assume:
# 
# words.txt contains only lowercase characters and space ' ' characters.
# Each word must consist of lowercase characters only.
# Words are separated by one or more whitespace characters.
# For example, assume that words.txt has the following content:
# 
# the day is sunny the the
# the sunny is is
# Your script should output the following, sorted by descending frequency:
# the 4
# is 3
# sunny 2
# day 1
# Note:
# Don't worry about handling ties, it is guaranteed that each word's frequency count is unique.
# 
# [show hint]
# 
# Hint:
# Could you write it in one-line using Unix pipes?

# Read from the file words.txt and output the word frequency list to stdout.
cat words.txt|tr -s ' ' '\n'|sort|uniq -c|sort -g -r|awk '{printf("%s %s\n",$2,$1)}'
