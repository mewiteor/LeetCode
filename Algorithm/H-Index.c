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
 * Given an array of citations (each citation is a non-negative integer)
 * of a researcher, write a function to compute the researcher's h-index.
 *
 * According to the definition of h-index on Wikipedia: "A scientist
 * has index h if h of his/her N papers have at least h citations each,
 * and the other N − h papers have no more than h citations each."
 *
 * For example, given citations = [3, 0, 6, 1, 5], which means the
 * researcher has 5 papers in total and each of them had received
 * 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3
 * papers with at least 3 citations each and the remaining two with
 * no more than 3 citations each, his h-index is 3.
 *
 * Note: If there are several possible values for h, the maximum one
 * is taken as the h-index.
 *
 * Hint:
 *
 * An easy approach is to sort the array first.
 * What are the possible values of h-index?
 * A faster approach is to use extra space.
 */

int hIndex(int* citations, int citationsSize) {
    int *counts=(int*)calloc(citationsSize+1,sizeof(int));
    int i,sum;
    
    for(i=0;i<citationsSize;++i)
        ++counts[citations[i]>citationsSize?citationsSize:citations[i]];
    for(i=citationsSize,sum=0;(sum+=counts[i])<i;--i);
    free(counts);
    return i;
}
