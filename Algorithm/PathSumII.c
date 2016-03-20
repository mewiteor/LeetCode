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
 * Given a binary tree and a sum, find all root-to-leaf paths where
 * each path's sum equals the given sum.
 * 
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void f(struct TreeNode* node, int sum,int allsum,int*** pret,int **colSizes,int *retSize,int **nums,size_t len) {
    /*printf("%p,%d,%d;",node,sum,allsum);
    for(int i=0;i<len;++i)
        printf(!i+",%d",(*nums)[i]);
    putchar('\n');*/
    if(!node) {
        if(sum==allsum) {
            *pret=(int**)realloc(*pret,++*retSize*sizeof(int*));
            *colSizes=(int*)realloc(*colSizes,*retSize*sizeof(int));
            (*pret)[*retSize-1]=(int*)malloc(((*colSizes)[*retSize-1]=len)*sizeof(int));
            memcpy((*pret)[*retSize-1],*nums,len*sizeof(int));
        }
    } else {
        *nums=(int*)realloc(*nums,++len*sizeof(int));
        sum+=(*nums)[len-1]=node->val;
        if(node->left==node->right)
            f(NULL,sum,allsum,pret,colSizes,retSize,nums,len);
        else {
            if(node->left)
                f(node->left,sum,allsum,pret,colSizes,retSize,nums,len);
            if(node->right)
                f(node->right,sum,allsum,pret,colSizes,retSize,nums,len);
        }
        *nums=(int*)realloc(*nums,--len*sizeof(int));
    }
}
 
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** pathSum(struct TreeNode* root, int sum, int** columnSizes, int* returnSize) {
    int **ret=(int**)malloc(0),*ns=(int*)malloc(0);
    *returnSize=0;
    *columnSizes=(int*)malloc(0);
    if(!root)
        return ret;
    f(root,0,sum,&ret,columnSizes,returnSize,&ns,0);
    free(ns);
    return ret;
}
