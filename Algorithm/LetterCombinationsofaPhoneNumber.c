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
 * Given a digit string, return all possible letter combinations
 * that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *
 * 1 @-@    2 abc   3 def
 * 4 ghi    5 jkl   6 mno
 * 7 pqrs   8 tuv   9 wxyz
 * * +      0 _     # ^
 *
 * Input:Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * Note:
 * Although the above answer is in lexicographical order, your answer
 * could be in any order you want.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {
    const char *strs[]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    const size_t strsSize[]={3,3,3,3,3,4,3,4};
    char **ret=NULL;
    char *t;
    int i,digLen=0,j,k,z;
    
    if(!*digits) {
        *returnSize=0;
        return (char**)malloc(0);
    }
    *returnSize=1;
    for(t=digits;*t;++t)
        *returnSize*=strsSize[*t-'2'];
    digLen=t-digits;
    ret=(char**)malloc(*returnSize*sizeof(char*));
    for(i=0;i<*returnSize;++i) {
        ret[i]=(char*)malloc((digLen+1)*sizeof(char));
        for(j=0,k=i;j<digLen;++j) {
            z=digits[j]-'2';
            ret[i][j]=strs[z][k%strsSize[z]];
            k/=strsSize[z];
        }
        ret[i][j]=0;
    }
    return ret;
}
