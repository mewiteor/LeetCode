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
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

void int2str(char **s,size_t d) {
	char *t=*s,*e;
	while(d) {
		*t++=d%10+'0';
		d/=10;
	}
	e=t;
	while(*s<--t) {char a=**s;*(*s)++=*t;*t=a;}
	*s=e;
}
char* countAndSay(int n) {
	if(n==1)return "1";
	else{
		char *oldstr=countAndSay(n-1),*oldtmp=oldstr;
		const size_t oldstr_len=strlen(oldstr);
		char *str=(char*)malloc(((oldstr_len+1)<<1)*sizeof(char)),*tmp=str;
		size_t j;
		while(*oldtmp) {
			j=1;
			while(*oldtmp==oldtmp[1]){++oldtmp;++j;}
			int2str(&tmp,j);
			*tmp++=*oldtmp++;
		}
		*tmp=0;
		if(n>2)free(oldstr);
		return str;
	}
}
