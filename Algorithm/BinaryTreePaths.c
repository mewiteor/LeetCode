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
 * Given a binary tree, return all root-to-leaf paths.
 * 
 * For example, given the following binary tree:
 * 
 *    1
 *  /   \
 * 2     3
 *  \
 *   5
 * All root-to-leaf paths are:
 * 
 * ["1->2->5", "1->3"]
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    //assert(returnSize!=NULL);
    if(NULL==root) {
        *returnSize=0;
        return (char**)calloc(0,sizeof(char*));
    } else {
        char *cur,**left,**right,**ret;
        int cur_len,left_size,right_size;
        cur_len=snprintf(NULL,0,"%d",root->val)+1;
        cur=(char*)malloc(cur_len*sizeof(char));
        snprintf(cur,cur_len,"%d",root->val);
        left=binaryTreePaths(root->left,&left_size);
        right=binaryTreePaths(root->right,&right_size);
        if(!left_size&&!right_size) {
            *returnSize=1;
            free(left);
            free(right);
            ret=(char**)malloc(sizeof(char*));
            *ret=cur;
        } else {
            size_t i,k=0;
            *returnSize=left_size+right_size;
            ret=(char**)malloc(*returnSize*sizeof(char*));
            for(i=0;i<left_size;++i,++k) {
                char *t=(char*)malloc((strlen(cur)+2+strlen(left[i])+1)*sizeof(char));
                strcpy(t,cur);
                strcat(t,"->");
                strcat(t,left[i]);
                free(left[i]);
                ret[k]=t;
            }
            for(i=0;i<right_size;++i,++k) {
                char *t=(char*)malloc((strlen(cur)+2+strlen(right[i])+1)*sizeof(char));
                strcpy(t,cur);
                strcat(t,"->");
                strcat(t,right[i]);
                free(right[i]);
                ret[k]=t;
            }
            free(cur);
        }
        return ret;
    }
}
