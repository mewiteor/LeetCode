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
 * Given a string which contains only lowercase letters, remove
 * duplicate letters so that every letter appear once and only once.
 * You must make sure your result is the smallest in lexicographical
 * order among all possible results.
 *
 * Example:
 * Given "bcabc"
 * Return "abc"
 *
 * Given "cbacdcbc"
 * Return "acdb"
 */


#define BIT_TEST(bitlist,index) ((bitlist)>>(index)&1)
#define BIT_SET(bitlist,index) (bitlist|=1<<(index))
#define BIT_CLR(bitlist,index) (bitlist&=~(1<<(index)))
char *removeDuplicateLetters(char* s) {
    static char ret[27];
    char *s_end=s,*ret_top=ret-1;
    unsigned int isVisited=0;
    size_t count[26]={0};
    while(*s_end)
        ++count[*s_end++ - 'a'];
    while(s<s_end) {
        if(BIT_TEST(isVisited,*s-'a')) {
            --count[*s++ -'a'];
            continue;
        }
        while(ret_top>=ret&&*ret_top>*s&&count[*ret_top-'a'])
            BIT_CLR(isVisited,*ret_top-- -'a');
        *++ret_top=*s;
        --count[*s-'a'];
        BIT_SET(isVisited,*s++-'a');
    }
    *++ret_top=0;
    return ret;
}
