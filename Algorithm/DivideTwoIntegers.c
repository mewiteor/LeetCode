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
 * Divide two integers without using multiplication,
 * division and mod operator.
 *
 * If it is overflow, return MAX_INT.
 */

#define MAX_INT ((int)((unsigned int)-1>>1))
int divide(int dividend, int divisor) {
	if(!divisor||(dividend==-MAX_INT-1&&divisor==-1))return MAX_INT;
	{
		bool neg=dividend>0^divisor>0;
		unsigned long long da=dividend<0?-(long long)dividend:dividend,db=divisor<0?-(long long)divisor:divisor;
		if(da<db)return 0;
		{
			// fast log2(n)
			double fda=da,fdb=db;
			unsigned int lg2_da = ( ( *(unsigned long long*)&fda )>> 52 ) - 1023;
			unsigned int lg2_db =  ( ( *(unsigned long long*)&fdb )>> 52 ) - 1023;
			int lr_shift=lg2_da-lg2_db,i;
			int ret=0;
			if(!(db&db-1))
			{
				ret=da>>lg2_db;
				return neg?-ret:ret;
			}
			db<<=lr_shift;
			for(i=lr_shift;i>=0;--i) {
				if(da>=db) {
					ret|=1<<i;
					da-=db;
				}
				db>>=1;
			}
			return neg?-ret:ret;
		}
	}
}
