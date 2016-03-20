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
 * Given a string S and a string T, find the minimum window in S
 * which will contain all the characters in T in complexity O(n).
 *
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 *
 * Note:
 * If there is no such window in S that covers all characters in T,
 * return the empty string "".
 *
 * If there are multiple such windows, you are guaranteed that
 * there will always be only one unique minimum window in S.
 */

char* minWindow(char* s, char* t) {
    int map[128]={0};
    int begin=0,end=0,head=0,d=INT_MAX,count=0;
    char *r;
    
    while(*t) {
        ++map[*t++];
        ++count;
    }
    
    while(s[end]) {
        if(map[s[end++]]-->0) --count;
        while(!count) {
            if(end-begin<d)
                d=end-(head=begin);
            if(!map[s[begin++]]++) ++count;
        }
    }
    
    if(d==INT_MAX)
        return "";
    
    r=(char*)malloc((d+1)*sizeof(char));
    memcpy(r,s+head,d);
    r[d]=0;
    return r;
}
