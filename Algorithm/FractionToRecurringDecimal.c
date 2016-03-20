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
 * Given two integers representing the numerator and denominator of
 * a fraction, return the fraction in string format.
 *
 * If the fractional part is repeating, enclose the repeating part
 * in parentheses.
 *
 * For example,
 *
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * Hint:
 *
 * No scary math, just apply elementary math knowledge. Still remember
 * how to perform a long division?
 * Try a long division on 4/9, the repeating part is obvious. Now try
 * 4/333. Do you see a pattern?
 * Be wary of edge cases! List out as many test cases as you can
 * think of and test your code thoroughly.
 */

char* fractionToDecimal(int numerator, int denominator) {
    long long num,den,p,q,t,a,b,c,i,retsz,cursz;
    bool neg;
    char *ret=NULL;
    if(!numerator)
        return "0";
    num=numerator;
    den=denominator;
    neg=num>0^den>0;
    if(num<0)
        num=-num;
    if(den<0)
        den=-den;
	p=num;
	q=den;
    while(p) {
        t=q;
        q=p;
        p=t%p;
    }
    num/=q;
    den/=q;
    t=num/den;
    num%=den;
    retsz=40;
    ret=(char*)malloc((retsz+1)*sizeof(char));
    cursz=sprintf(ret,"%s%lld",neg?"-":"",t);
    if(num) {
        strcat(ret,".");
        ++cursz;
        p=den;
        a=0;b=0;
        while(!(p&1)) {
            ++a;
            p>>=1;
        }
        while(!(p%5)) {
            ++b;
            p/=5;
        }
        c=a>b?a:b;
		while(c--) {
			num*=10;
			ret[cursz++]=num/den+'0';
			num%=den;
			ret[cursz]=0;
		}
		while(a--)
            num>>=1;
		while(b--)
            num/=5;
        // num / p
        if(p>1) {
            unsigned char *bits=(unsigned char*)calloc((p+6)>>3,sizeof(unsigned char));
            ret[cursz++]='(';
            bits[num-1>>3]|=1<<(num-1&7);
            while(1) {
                long long l;
                if(cursz+1>=retsz)
                    ret=(char*)realloc(ret,((retsz+=40)+1)*sizeof(char));
                num*=10;
                ret[cursz++]=num/p+'0';
                num%=p;
                l=num-1;
                if(bits[l>>3]&1<<(l&7))
                    break;
                else
                    bits[l>>3]|=1<<(l&7);
            }
            ret[cursz++]=')';
            ret[cursz]=0;
        }
    }
    return ret;
}
