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
 * Implement a basic calculator to evaluate a simple expression string.
 *
 * The expression string contains only non-negative integers, +, -, *,
 * / operators and empty spaces . The integer division should truncate toward zero.
 *
 * You may assume that the given expression is always valid.
 *
 * Some examples:
 * "3+2*2" = 7
 * " 3/2 " = 1
 * " 3+5 / 2 " = 5
 * Note: Do not use the eval built-in library function.
 */

int calculate(char *s) {
    int *nums=NULL,*n;
    char *op=NULL,*o;
    size_t ns=0,os=0;
    long long res=0;
    while(*s) {
        while(*s==' ')
            ++s;
        n=(int*)realloc(nums,++ns*sizeof(int));
        if(!n) {
            if(nums)
                free(nums);
            if(op)
                free(op);
            return 0;
        }
        nums=n;
        nums[ns-1]=0;
        while(*s>='0'&&*s<='9')
            nums[ns-1]=nums[ns-1]*10+*s++-'0';
        while(*s==' ')
            ++s;
        if(!*s) {
            while(os) {
                switch(op[os-1]) {
                    case '+':nums[ns-2]+=nums[ns-1];break;
                    case '-':nums[ns-2]-=nums[ns-1];break;
                    case '*':nums[ns-2]*=nums[ns-1];break;
                    case '/':nums[ns-2]/=nums[ns-1];break;
                }
                --ns;
                --os;
            }
            res=nums[0];
            if(nums)
                free(nums);
            if(op)
                free(op);
            return res;
        } else {
            o=(char*)realloc(op,++os*sizeof(char));
            if(!o) {
                if(nums)
                    free(nums);
                if(op)
                    free(op);
                return 0;
            }
            op=o;
            op[os-1]=*s++;
            while(os>1&&(op[os-1]=='+'||op[os-1]=='-'||op[os-2]=='*'||op[os-2]=='/')) {
                switch(op[os-2]) {
                    case '+':nums[ns-2]+=nums[ns-1];break;
                    case '-':nums[ns-2]-=nums[ns-1];break;
                    case '*':nums[ns-2]*=nums[ns-1];break;
                    case '/':nums[ns-2]/=nums[ns-1];break;
                }
                --ns;
                op[os-2]=op[os-1];
                --os;
            }
        }
    }
    return res;
}
