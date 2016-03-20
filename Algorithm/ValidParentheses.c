/*
 * Copyright (C) 2016  Mewiteor <mewiteor@hotmail.com>
 * 
 * This program is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

void f(char **s,bool *b) {
	char cur=0;
	if(!**s||!*b)return;
	else cur=**s;
	switch(cur) {
		case ')':
		case ']':
		case '}':
			*b=false;
			return;
	}
	while(*b&&*++*s) {
		if(')'==**s||']'==**s||'}'==**s) {
			if(**s-cur>2||**s-cur<0) *b=false;
			else cur=0;
			break;
		} else f(s,b);
	}
	if(cur)*b=false;
}

bool isValid(char* s) {
	bool b=true;
	do {
		f(&s,&b);
	}while(b&&*s++);
	return b;
}

