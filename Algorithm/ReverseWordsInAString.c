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
 * Given an input string, reverse the string word by word.
 *
 * For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 *
 * Clarification:
 * What constitutes a word?
 * A sequence of non-space characters constitutes a word.
 * Could the input string contain leading or trailing spaces?
 * Yes. However, your reversed string should not contain leading or trailing spaces.
 * How about multiple spaces between two words?
 * Reduce them to a single space in the reversed string.
 */

void reverse(char* s,size_t len){
    size_t i;
    char t;
    for(i=len>>1;i>0;--i) {
        t=s[i-1];
        s[i-1]=s[len-i];
        s[len-i]=t;
    }
}
void reverseWords(char *s) {
    char *t=s,*r=s;
    while(' '==*t)
        ++t;
    while(*t) {
        while(*t&&*t!=' ')
            *r++=*t++;
		if (!*t)
            *r++ = 0;
        else {
			*r++ = *t++;
			while (' ' == *t)
                ++t;
		}
    }
    if(r==s) {
        *s=0;
        return;
    }
    else
        r[-1]=0;
    reverse(s,r-1-s);
    t=s;
    while(*t) {
        do {
            ++t;
        } while(*t&&' '!=*t);
        reverse(s,t-s);
        if(*t)
            s=++t;
    }
}
