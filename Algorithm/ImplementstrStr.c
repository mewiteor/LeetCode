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
 * Implement strStr().
 *
 * Returns the index of the first occurrence of needle in haystack,
 * or -1 if needle is not part of haystack.
 */

int strStr(char* haystack, char* needle) {
	const size_t n=strlen(haystack);
	const size_t m=strlen(needle);
	size_t* next=(size_t*)malloc((m+1)*sizeof(size_t));
	size_t i,j=0;
	if(!*needle)return 0;
	next[0]=next[1]=0;
	for(i=1;i<m;++i) {
		while(j>0&&needle[i]!=needle[j])j=next[j];
		if(needle[i]==needle[j])++j;
		next[i+1]=j;
	}
	j=0;
	for(i=0;i<n;++i) {
		while(j>0&&needle[j]!=haystack[i])j=next[j];
		if(needle[j]==haystack[i])++j;
		if(j==m) {
			free(next);
			return i-j+1;
		}
	}
	free(next);
	return -1;
}
