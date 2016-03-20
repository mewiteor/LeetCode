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
 * Given an integer n, count the total number of digit 1 appearing
 * in all non-negative integers less than or equal to n.
 *
 * For example:
 * Given n = 13,
 * Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.
 *
 * Hint:
 *
 * Beware of overflow.
 */

int countDigitOne(int n) {
    unsigned long long sum=0;
    if(n>0) {
        unsigned long long ten=1,a,b,c,nn=n;
        while(nn>=ten) {
            a=nn%ten;
            b=nn/ten;
            c=b%10;
            b/=10;
            sum+=!c?b*ten:1==c?b*ten+a+1:(b+1)*ten;
            ten*=10;
        }
    }
    return sum;
}
