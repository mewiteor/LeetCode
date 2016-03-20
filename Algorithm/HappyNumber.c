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
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process:
 * Starting with any positive integer, replace the number by the
 * sum of the squares of its digits, and repeat the process until
 * the number equals 1 (where it will stay), or it loops endlessly
 * in a cycle which does not include 1. Those numbers for which
 * this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */

bool isHappy(int n) {
    while(n>4){
        int r=0;
        while(n) {
            r+=(n%10)*(n%10);
            n/=10;
        }
        n=r;
    }
    return n==1;
}
