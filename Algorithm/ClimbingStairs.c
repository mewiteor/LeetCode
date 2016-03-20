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
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct
 * ways can you climb to the top?
 */

int climbStairs(int n) {
    // ([1 1,1 0]^n)[0][0]
    int r[2][2]={{1,0},{0,1}},
        x[2][2]={{1,1},{1,0}},
        t[2][2];
    while(n) {
        if(n&1) {
            memcpy(&t,&r,sizeof t);
            // r=t*x
            r[0][0]=t[0][0]*x[0][0]+t[0][1]*x[1][0];
            r[0][1]=t[0][0]*x[0][1]+t[0][1]*x[1][1];
            r[1][0]=t[1][0]*x[0][0]+t[1][1]*x[1][0];
            r[1][1]=t[1][0]*x[0][1]+t[1][1]*x[1][1];
        }
        memcpy(&t,&x,sizeof t);
        // x=t*t
        x[0][0]=t[0][0]*t[0][0]+t[0][1]*t[1][0];
        x[0][1]=t[0][0]*t[0][1]+t[0][1]*t[1][1];
        x[1][0]=t[1][0]*t[0][0]+t[1][1]*t[1][0];
        x[1][1]=t[1][0]*t[0][1]+t[1][1]*t[1][1];
        n>>=1;
    }
    return r[0][0];
}
