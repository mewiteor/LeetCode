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
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given
 * input specs). You are responsible to gather all the input requirements up front.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload button
 * to reset your code definition.
 *
 * spoilers alert... click to show requirements for atoi.
 *
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the
 * first non-whitespace character is found. Then, starting from this character,
 * takes an optional initial plus or minus sign followed by as many numerical
 * digits as possible, and interprets them as a numerical value.
 *
 * The string can contain additional characters after those that form the integral number,
 * which are ignored and have no effect on the behavior of this function.
 *
 * If the first sequence of non-whitespace characters in str is not a valid integral number,
 * or if no such sequence exists because either str is empty or
 * it contains only whitespace characters, no conversion is performed.
 *
 *
 * If no valid conversion could be performed, a zero value is returned.
 * If the correct value is out of the range of representable values,
 * INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 */

#ifndef INT_MAX
#define INT_MAX ((long long)((unsigned int)-1>>1))
#endif

int myAtoi(char* str) {
    long long r=0;
	int neg=1;
	while(' '==*str)++str;
	if('-'==*str){neg=-1;++str;}
	else if('+'==*str)++str;
	while(*str>='0'&&*str<='9'&&(1==neg&&r<=(long long)INT_MAX||-1==neg&&r<=(long long)INT_MAX+1))
		r=r*10+*str++-'0';
	if(1==neg&&r>(long long)INT_MAX)r=(long long)INT_MAX;
	else if(-1==neg&&r>(long long)INT_MAX+1)r=(long long)INT_MAX+1;
	return r*neg;
}
