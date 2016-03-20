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
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 * 
 * For example:
 * 
 *     1 -> A
 *     2 -> B
 *     3 -> C
 *     ...
 *     26 -> Z
 *     27 -> AA
 *     28 -> AB 
 */

// (n>26?convertToTitle((n-1)/26):"")+(char)((n-1)%26+'A')
char* convertToTitle(int n) {
    char *ret,*ptr;
    int nn=n,len=0;
    while(nn) {
        ++len;
        nn=(nn-1)/26;
    }
    ret=(char*)malloc((len+1)*sizeof(char));
    ptr=ret+len;
    *ptr=0;
    while(n) {
        *--ptr=--n%26+'A';
        n/=26;
    }
    return ret;
}
