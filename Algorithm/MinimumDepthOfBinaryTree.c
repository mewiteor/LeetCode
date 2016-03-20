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
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path
 * from the root node down to the nearest leaf node.
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root) {
    int l,r;
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    if(!root->left||!root->right)
        return root->left?1+minDepth(root->left):1+minDepth(root->right);
    l=1+minDepth(root->left),r=1+minDepth(root->right);
    return l<r?l:r;
}
