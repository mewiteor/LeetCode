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
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a
 * given number of rows like this: (you may want to display this
 * pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 *
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion
 * given a number of rows:
 *
 * string convert(string text, int nRows);
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

char* convert(char* s, int numRows) {
    if(numRows<2)return s;
	else {
		const int slen=strlen(s);
		char *ret=(char*)malloc((slen+1)*sizeof(char));
		int i,j,k=numRows-1<<1,cur=0;
		for(i=0;i<slen;i+=k)
			ret[cur++]=s[i];
		for(i=1;i<numRows-1;++i) {
			ret[cur++]=s[i];
			for(j=k;j+i<slen;j+=k) {
				ret[cur++]=s[j-i];
				ret[cur++]=s[j+i];
			}
			if(j-i<slen)
				ret[cur++]=s[j-i];
		}
		for(i=numRows-1;i<slen;i+=k)
			ret[cur++]=s[i];
		ret[cur]=0;
		return ret;
	}
}
