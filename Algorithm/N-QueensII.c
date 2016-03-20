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
 * Follow up for N-Queens problem.
 *
 * Now, instead outputting board configurations, return the total
 * number of distinct solutions.
 */

int sum,upperlim;
void test(long row, long ld, long rd) {
    if (row == upperlim)
        ++sum;
    else{
        int pos = upperlim & ~(row | ld | rd);
        while (pos) {
            int p = pos & -pos;
            pos -= p;
            test(row + p, (ld + p) << 1, (rd + p) >> 1);
        }
    }
}

int totalNQueens(int n) {
    sum=0;
    upperlim=(1<<n)-1;
    test(0,0,0);
    return sum;
}
