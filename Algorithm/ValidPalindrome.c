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
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good
 * question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid
 * palindrome.
 */

bool isPalindrome(char* s) {
    char *r=s+strlen(s)-1;
    while(s<r) {
        while(*s&&!((*s|0x20)>='a'&&(*s|0x20)<='z'||*s>='0'&&*s<='9'))
            ++s;
        while(*r&&!((*r|0x20)>='a'&&(*r|0x20)<='z'||*r>='0'&&*r<='9'))
            --r;
        if((*s|0x20)>='a'&&(*s|0x20)<='z'&&(*r|0x20)>='a'&&(*r|0x20)<='z') {
            if((*s|0x20)!=(*r|0x20))
                return false;
        } else if(*r!=*s)
            return false;
        ++s;--r;
    }
    return true;
}
