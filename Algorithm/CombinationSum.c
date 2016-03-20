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
 * Given a set of candidate numbers (C) and a target number (T),
 * find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending
 * order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */

int cmp(const void *a,const void *b) {
    int aa=*(int*)a;
    int bb=*(int*)b;
    return aa>bb?1:aa<bb?-1:0;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int** columnSizes, int* returnSize) {
    int *count=(int*)calloc(candidatesSize,sizeof(int)),remain=target,i,j,k,cur=candidatesSize;
    int **ret=(int**)malloc(0);
    *columnSizes=(int*)malloc(0);
    *returnSize=0;
    qsort(candidates,candidatesSize,sizeof(int),cmp);
    for (;;) {
        if (!remain||!cur) {
            if(!remain) {
                ret=(int**)realloc(ret,++*returnSize*sizeof(int*));
                *columnSizes=(int*)realloc(*columnSizes,*returnSize*sizeof(int));
                (*columnSizes)[*returnSize-1]=0;
                for (i=0;i<candidatesSize;++i)
                    (*columnSizes)[*returnSize-1]+=count[i];
                ret[*returnSize-1]=(int*)malloc((*columnSizes)[*returnSize-1]*sizeof(int));
                for (k=0,i=0;i<candidatesSize;++i)
                    for (j=0;j<count[i];++j,++k)
                        ret[*returnSize-1][k]=candidates[i];
            }
            if(!cur) {
                if(target/candidates[0]==count[0]) break;
                remain+=count[0]*candidates[0];
                count[0]=0;
                while(!count[++cur]);
            }
            remain+=candidates[cur];
            --count[cur];
        } else {
            --cur;
            count[cur]=remain/candidates[cur];
            remain%=candidates[cur];
        }
    }
    return ret;
}

