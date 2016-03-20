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
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * click to show spoilers.
 *
 * Have you thought about this?
 * Here are some good questions to ask before coding.
 * Bonus points for you if you have already thought through this!
 *
 * If the integer's last digit is 0, what should the output be?
 * ie, cases such as 10, 100.
 *
 * Did you notice that the reversed integer might overflow? Assume
 * the input is a 32-bit integer, then the reverse of 1000000003 overflows.
 * How should you handle such cases?
 *
 * For the purpose of this problem, assume that your function returns 0
 * when the reversed integer overflows.
 *
 * Update (2014-11-10):
 * Test cases had been added to test the overflow behavior.
 */

#ifndef INT_MAX
#define INT_MAX ((int)((unsigned int)-1>>1))
#endif

int reverse(int x) {
    long long r=0;
	while(x) {
		r=r*10+x%10;
		x/=10;
	}
	return r>INT_MAX||r<-INT_MAX-1?0:r;
}
