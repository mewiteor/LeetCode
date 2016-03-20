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
 * Validate if a given string is numeric.
 *
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous.
 * You should gather all requirements up front before implementing one.
 *
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still
 * see your function signature accepts a const char * argument,
 * please click the reload button  to reset your code definition.
 */

bool isNumber(char* s) {
    while(*s==' '||*s=='\t')
        ++s;
    if(!*s)
        return false;
    if(*s=='+'||*s=='-')
        ++s;
    if(*s=='0') {
        ++s;
        if(*s=='x') { // hex
            bool another=false;
            ++s;
            while((*s>='0'&&*s<='9')||((*s|0x20)>='a'&&(*s|0x20)<='f')) {
                ++s;
                another=true;
            }
            if(!another)
                return false;
        } else {
            while(*s>='0'&&*s<='9')
                ++s;
            if(*s=='.') // float
                do{
                    ++s;
                }while(*s>='0'&&*s<='9');
            if((*s|0x20)=='e') {
                bool another=false;
                ++s;
                if(*s=='+'||*s=='-')
                    ++s;
                while(*s>='0'&&*s<='9') {
                    ++s;
                    another=true;
                }
                if(!another)
                    return false;
            }
        }
    }
    else if(*s=='.') {
        bool another=false;
        ++s;
        while(*s>='0'&&*s<='9') {
            ++s;
            another=true;
        }
        if(!another)
            return false;
        if((*s|0x20)=='e') {
            another=false;
            ++s;
            if(*s=='+'||*s=='-')
                ++s;
            while(*s>='0'&&*s<='9') {
                ++s;
                another=true;
            }
            if(!another)
                return false;
        }
    } else if(*s>='1'&&*s<='9') {
        do {
            ++s;
        }while(*s>='0'&&*s<='9');
        if(*s=='.') // float
            do {
                ++s;
            }while(*s>='0'&&*s<='9');
        if((*s|0x20)=='e') {
            bool another=false;
            ++s;
            if(*s=='+'||*s=='-')
                ++s;
            while(*s>='0'&&*s<='9') {
                ++s;
                another=true;
            }
            if(!another)
                return false;
        }
    }
    while(*s==' '||*s=='\t')
        ++s;
    return !*s;
}
