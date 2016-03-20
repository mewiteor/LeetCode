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
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

int romanToInt(char* s) {
    int r=0;
	while('M'==*s){r+=1000;++s;}
	if('C'==s[0]&&'M'==s[1]){r+=900;s+=2;}
	else if('C'==s[0]&&'D'==s[1]){r+=400;s+=2;}
	else if('D'==*s){r+=500;++s;}
	while('C'==*s){r+=100;++s;}
	if('X'==s[0]&&'C'==s[1]){r+=90;s+=2;}
	else if('X'==s[0]&&'L'==s[1]){r+=40;s+=2;}
	else if('L'==*s){r+=50;++s;}
	while('X'==*s){r+=10;++s;}
	if('I'==s[0]&&'X'==s[1]){r+=9;s+=2;}
	else if('I'==s[0]&&'V'==s[1]){r+=4;s+=2;}
	else if('V'==*s){r+=5;++s;}
	while('I'==*s){r+=1;++s;}
	return r;
}
