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
 * Implement pow(x, n).
 */

double myPow(double x, int n) {
    double r=1;
    if(x==0)return 0;
    else if(x==1)return 1;
    else if(x==-1)return n&1?-1:1;
    if(n<0){n=-n;x=1/x;}
    while(n) {
        if(n&1){r*=x;}
        x*=x;
        n>>=1;
    }
    return r;
}
