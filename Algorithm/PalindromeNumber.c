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
 * Determine whether an integer is a palindrome.
 * Do this without extra space.
 *
 * click to show spoilers.
 *
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string,
 * note the restriction of using extra space.
 *
 * You could also try reversing an integer. However,
 * if you have solved the problem "Reverse Integer",
 * you know that the reversed integer might overflow.
 * How would you handle such case?
 *
 * There is a more generic way of solving this problem.
 */

bool isPalindrome(int x) {
    if(x<0)return false;
    else {
        long long a=0,xx=x;
        while(xx) {
            a=a*10+xx%10;
            xx/=10;
        }
        return a==x;
    }
}
