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
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

char* intToRoman(int num) {
	char *r=(char*)malloc(16*sizeof(char));
	char *cr=r;
	int i;
	for(i=num/1000;i>0;--i)*cr++='M';
	num%=1000;
	if(num>=900) {cr[0]='C';cr[1]='M';cr+=2;num-=900;}
	else if(num>=500) {*cr++='D';num-=500;}
	else if(num>=400) {cr[0]='C';cr[1]='D';cr+=2;num-=400;}
	for(i=num/100;i>0;--i)*cr++='C';
	num%=100;
	if(num>=90) {cr[0]='X';cr[1]='C';cr+=2;num-=90;}
	else if(num>=50) {*cr++='L';num-=50;}
	else if(num>=40) {cr[0]='X';cr[1]='L';cr+=2;num-=40;}
	for(i=num/10;i>0;--i)*cr++='X';
	num%=10;
	if(9==num){cr[0]='I';cr[1]='X';cr+=2;num-=9;}
	else if(num>=5) {*cr++='V';num-=5;}
	else if(4==num){cr[0]='I';cr[1]='V';cr+=2;num-=4;}
	for(i=num;i>0;--i)*cr++='I';
	*cr=0;
	return r;

}
