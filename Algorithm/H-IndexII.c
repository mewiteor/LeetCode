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
 * Follow up for H-Index: What if the citations array is sorted in
 * ascending order? Could you optimize your algorithm?
 *
 * Hint:
 *
 * Expected runtime complexity is in O(log n) and the input is sorted.
 */

int hIndex(int* citations, int citationsSize) {
    int start=0,end=citationsSize;
    int it;
    while(start<end) {
        it=start+(end-start>>1);
        if(citations[it]==citationsSize-it)
            return citationsSize-it;
        else if(citations[it]<citationsSize-it)
            start=it+1;
        else
            end=it;
    }
    return citationsSize-start;
}
