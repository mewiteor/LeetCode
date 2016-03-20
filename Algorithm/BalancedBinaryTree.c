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
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a
 * binary tree in which the depth of the two subtrees of every node
 * never differ by more than 1.
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dep(struct TreeNode* root) {
    int l,r;
    if(!root)
        return 0;
    if(!root->left&&!root->right)
        return 1;
    if(!root->left||!root->right)
        return root->left?1+dep(root->left):1+dep(root->right);
    l=1+dep(root->left);
    r=1+dep(root->right);
    return l<r?r:l;
}

bool isBalanced(struct TreeNode* root) {
    int l,r;
    if(!root)
        return true;
    if(!isBalanced(root->left))
        return false;
    if(!isBalanced(root->right))
        return false;
    l=dep(root->left);
    r=dep(root->right);
    return (l>r?l-r:r-l)<2;
}
