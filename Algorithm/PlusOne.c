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
 * Given a non-negative number represented as an array of digits, plus one to the number.
 *
 * The digits are stored such that the most significant digit is at the head of the list.
 */

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int i,*r=NULL;
    for(i=digitsSize-1;i>=0&&digits[i]==9;--i);
    if(i>=0) {
        r=(int*)calloc(*returnSize=digitsSize,sizeof(int));
        if(r) {
            memcpy(r,digits,i*sizeof(int));
            r[i]=digits[i]+1;
        }
    }else {
        r=(int*)calloc(*returnSize=digitsSize+1,sizeof(int));
        if(r)r[0]=1;
    }
    return r;
}
