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
 * Description:
 *
 * Count the number of prime numbers less than a non-negative number, n.
 */

unsigned short sq(unsigned int n){
	unsigned short root=0,i;
	unsigned int rem=0,divisor=0;
	for(i=0;i<16;++i) {
		root<<=1;
		rem=((rem<<2)|n>>30);
		n<<=2;
		divisor=root<<1|1;
		if(divisor<=rem) {
			rem-=divisor;
			++root;
		}
	}
	return root;
}

int countPrimes(int n) {
	if(n<3)
        return 0;
	else if(3==n)
        return 1;
	else if(n<6)
        return 2;
	else if(n<8)
        return 3;
	else {
		unsigned char* dt[2];
		int i,j,k,r;
		const int n_6=n/6-1,n_8=(n-8)/6,
			  n_6_8=(n_6>>3)+1,
			  i_max=((int)sq(n_8*6+7)-5)/6;
		for(i=0;i<2;++i)
            dt[i]=(unsigned char*)calloc(n_6_8,sizeof(unsigned char));
		if(n>25) {
			for(i=0,k=5,r=7;i<=i_max;++i,k+=6,r+=6) {
				for(j=(6*i+12)*i+5;j<=n_6;j+=k)
					dt[0][j>>3]|=1<<(j&7);
				for(j=(6*i+10)*i+3;j<=n_8;j+=k)
					dt[1][j>>3]|=1<<(j&7);
				for(j=(6*i+12)*i+5;j<=n_6;j+=r)
					dt[0][j>>3]|=1<<(j&7);
				for(j=(6*i+14)*i+7;j<=n_8;j+=r)
					dt[1][j>>3]|=1<<(j&7);
			}
		}
		r=2;
		for(i=n_6_8-2;i>=0;--i) {
			k=8;
			j=dt[0][i];
			while(j) {
				j=j&(j-1);
				--k;
			}
			r+=k;
			k=8;
			j=dt[1][i];
			while(j) {
				j=j&(j-1);
				--k;
			}
			r+=k;
		}
		k=(n_6&7)+1;
		j=dt[0][n_6_8-1];
		while(j) {
			j=j&(j-1);
			--k;
		}
		r+=k;
		k=(n_6&7)+(n_6==n_8?1:0);
		j=dt[1][n_6_8-1];
		while(j) {
			j=j&(j-1);
			--k;
		}
		r+=k;
		for(i=0;i<2;++i)
            free(dt[i]);
		return r;
	}
}
