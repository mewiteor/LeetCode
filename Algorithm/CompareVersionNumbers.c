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
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1,
 * otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain
 * only digits and the . character.
 * The . character does not represent a decimal point and is used to
 * separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version
 * three", it is the fifth second-level revision of the second
 * first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */

int compareVersion(char* version1, char* version2) {
    int v1,v2;
    char *tt1,*tt2;
    char *t1=strtok_r(version1,".",&tt1),
         *t2=strtok_r(version2,".",&tt2);
    while(1) {
        if(!t1&&!t2)
            return 0;
        v1=v2=0;
        if(t1)
            sscanf(t1,"%d",&v1);
        if(t2)
            sscanf(t2,"%d",&v2);
        if(v1!=v2)
            return v1<v2?-1:1;
        if(t1)
            t1=strtok_r(NULL,".",&tt1);
        if(t2)
            t2=strtok_r(NULL,".",&tt2);
    }
}
