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

# Given a text file file.txt, transpose its content.
# 
# You may assume that each row has the same number of columns and each field is separated by the ' ' character.
# 
# For example, if file.txt has the following content:
# 
# name age
# alice 21
# ryan 30
# Output the following:
# 
# name alice ryan
# age 21 30

# Read from the file file.txt and print its transposed content to stdout.
awk '{
	for(i=1;i<=NF;++i) {
		if(NR == 1) {
			s[i]=$i;
		} else {
			s[i]=s[i]" "$i;
		}
	}
}
END {
	for(i=1;s[i]!="";++i) {
		print s[i];
	}
}' file.txt
