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
 * Given a list of non negative integers, arrange them such that
 * they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number
 * is 9534330.
 *
 * Note: The result may be very large, so you need to return a string
 * instead of an integer.
 */

long long tens[]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000,10000000000};
int comp(const void* a,const void* b) {
	int aa=*(int*)a,bb=*(int*)b;
	if(!aa&&!bb)return 0;
	if(!aa)return 1;
	if(!bb)return -1;
	{
		long long r=(bb*tens[(long long)log10((double)aa)+1]+aa)-(aa*tens[(long long)log10((double)bb)+1]+bb);
		return r>0?1:r?-1:0;
	}
}
char* largestNumber(int* nums, int numsSize) {
	qsort(nums,numsSize,sizeof(int),comp);
	if(!nums[0])
        return "0";
	else {
		int i,j,len=numsSize+1,k;
		char *r,*t;
		for(i=0;i<numsSize;++i)
            if(nums[i]>9)
                len+=log10(nums[i]);
		t=r=(char*)malloc(len*sizeof(char));
		for(i=0;i<numsSize;++i) {
			if(nums[i]<10)
				*t++=nums[i]+'0';
			else {
				for(k=j=log10(nums[i]);j>=0;--j) {
					t[j]=nums[i]%10+'0';
					nums[i]/=10;
				}
				t+=k+1;
			}
		}
		*t=0;
		return r;
	}
}
