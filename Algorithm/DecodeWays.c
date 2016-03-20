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
 * A message containing letters from A-Z is being encoded to numbers
 * using the following mapping:
 *
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * Given an encoded message containing digits, determine the total
 * number of ways to decode it.
 *
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 *
 * The number of ways decoding "12" is 2.
 */

int numDecodings(char* s) {
    if(!*s||!(*s>'0'&&*s<='9'))
        return 0;
    else {
        int a=1,b=1,c,t;
        while(s[1]>='0'&&s[1]<='9') {
            t=(s[0]-'0')*10+s[1]-'0';
            c=t>=10&&t<=26?a:0;
            c+=*++s=='0'?0:b;
            a=b;
            b=c;
        }
        return s[1]?0:b;
    }
}
