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
 * Given an array of strings, group anagrams together.
 *
 * For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
 * Return:
 *
 * [
 *   ["ate", "eat","tea"],
 *   ["nat","tan"],
 *   ["bat"]
 * ]
 * Note:
 *   For the return value, each inner list's elements must follow
 *   the lexicographic order.
 *   All inputs will be in lower-case.
 */

typedef struct{
    int n;
    int dat[26];
}DAT;
int comp(const void* a,const void* b){return memcmp(((DAT*)a)->dat,((DAT*)b)->dat,sizeof(int)*26);}
char** anagrams(char** strs, int strsSize, int* returnSize) {
    DAT *d;
    int i,j,k;
    char **ret=NULL;
    *returnSize=0;
    if(strsSize<2)return ret;
    d=(DAT*)calloc(strsSize,sizeof(DAT));
    for(i=0;i<strsSize;++i) {
        d[i].n=i;
        for(j=strlen(strs[i])-1;j>=0;--j)
            ++d[i].dat[strs[i][j]-'a'];
    }
    qsort(d,strsSize,sizeof(DAT),comp);
    for(i=1,j=0;i<strsSize;++i)
        if(comp(d+i,d+i-1))
            j=0;
        else {
            if(j)
                ret=(char**)realloc(ret,++*returnSize*sizeof(char*));
            else {
                ret=(char**)realloc(ret,(*returnSize+=2)*sizeof(char*));
                j=1;
                ret[*returnSize-2]=strs[d[i-1].n];
            }
            ret[*returnSize-1]=strs[d[i].n];
        }
    free(d);
    return ret;
}
