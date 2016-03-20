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
 * Given a string S, find the longest palindromic substring in S.
 * You may assume that the maximum length of S is 1000,
 * and there exists one unique longest palindromic substring.
 */

char* longestPalindrome(char* s) {
    if(!s||!*s||!s[1])
        return s;
    else {
        size_t len=strlen(s),dlen=(len<<1)-1,i,maxi=0,maxl=1;
        char *r;
        for (i=1;i<dlen-maxl;++i) {
            size_t jlen=i<len?i+1:dlen-i,j=2-(i&1);
            while (j<jlen&&s[i-j>>1]==s[i+j>>1])
                j+=2;
            if(maxl<j-1) {
                maxl=j-1;
                maxi=i;
            }
        }
        r=(char*)malloc(sizeof(char)*(maxl+1));
        strncpy(r,s+(maxi+1-maxl>>1),maxl);
        r[maxl]=0;
        return r;
    }
}
