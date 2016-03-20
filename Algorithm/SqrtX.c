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
 * Implement int sqrt(int x).
 *
 * Compute and return the square root of x.
 */

int mySqrt(int x) {
    unsigned short root=0,i=0;
    unsigned int rem=0,divisor=0,uX=x;
    
    // fast log2(n)
    double fX=uX;
	int lg2_n = ( *( (unsigned long long*)&fX ) >> 52 ) - 1023;
	
	uX<<=(15-(lg2_n>>1))<<1;
	i=(lg2_n>>1)+2;
    while(--i) {
        root<<=1;
        rem=((rem<<2)|uX>>30);
        uX<<=2;
        divisor=root<<1|1;
        if(divisor<=rem) {
            rem-=divisor;
            ++root;
        }
    }
    return (int)root;
}
