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
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

char* longestCommonPrefix(char** strs, int strsSize) {
	int i,j,max=0;
	unsigned char b=1;
	char *r;
	if(!strsSize)return "";
	else if(1==strsSize)return strs[0];
	while(1)
	{
		if(!strs[0][max])break;
		for(i=1;i<strsSize&&strs[i][max]&&strs[i][max]==strs[0][max];++i);
		if(i<strsSize)break;
		++max;
	}
	r=(char*)malloc((max+1)*sizeof(char));
	strncpy(r,strs[0],max);
	r[max]=0;
	return r;
}
