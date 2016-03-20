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
 * Given two binary strings, return their sum (also a binary string).
 *
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */

char* addBinary(char* a, char* b) {
    int la=strlen(a),lb=strlen(b);
    int lr=(la>lb?la:lb)+1;
    char *rstr=(char*)malloc((lr+1)*sizeof(char));
    int cur=0;
    char *tmp=rstr,*tmp2=rstr,t,c=0;
    while(la&&lb) {
        *tmp=a[--la]-'0'+b[--lb]+c;
        if(*tmp>'1'){*tmp-=2;c=1;}
        else c=0;
        ++tmp;
    }
    while(la) {
        *tmp=a[--la]+c;
        if(*tmp>'1'){*tmp-=2;c=1;}
        else c=0;
        ++tmp;
    }
    while(lb) {
        *tmp=b[--lb]+c;
        if(*tmp>'1'){*tmp-=2;c=1;}
        else c=0;
        ++tmp;
    }
    if(c)*tmp++='1';
    *tmp=0;
    while(tmp2<--tmp) {
        t=*tmp2;
        *tmp2++=*tmp;
        *tmp=t;
    }
    return rstr;
}
