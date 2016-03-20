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
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the
 * bitwise AND of all numbers in this range, inclusive.
 *
 * For example, given the range [5, 7], you should return 4.
 */

int rangeBitwiseAnd(int m, int n) {
    if(m==n)
        return m;
    else {
        double fMN=m^n;
        // fast log2(n)
    	int lg2_mn = ( *( (unsigned long long*)&fMN ) >> 52 ) - 1023;
    	
        return ~((1<<(lg2_mn+1))-1)&m;
    }
}
