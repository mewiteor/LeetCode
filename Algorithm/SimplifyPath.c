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
 * Given an absolute path for a file (Unix-style), simplify it.
 *
 * For example,
 * path = "/home/", => "/home"
 * path = "/a/./b/../../c/", => "/c"
 * click to show corner cases.
 *
 * Corner Cases:
 * Did you consider the case where path = "/../"?
 * In this case, you should return "/".
 * Another corner case is the path might contain multiple slashes
 * '/' together, such as "/home//foo/".
 * In this case, you should ignore redundant slashes and return "/home/foo".
 */

char* simplifyPath(char* path) {
    char **stacks=NULL;
    size_t size=0,rsize=0,i,j,k;
    char *p=strtok(path,"/"),*r=NULL;
    if(p)
        do {
            if(!strcmp(p,"..")) {
                if(size) {
                    if(stacks[size-1])
                        free(stacks[size-1]);
                    stacks=(char**)realloc(stacks,--size*sizeof(char*));
                }
            }
            else if(strcmp(p,".")) {
                stacks=(char**)realloc(stacks,++size*sizeof(char*));
                stacks[size-1]=(char*)malloc(sizeof(char)*(strlen(p)+1));
                strcpy(stacks[size-1],p);
            }
        }while(p=strtok(NULL,"/"));
    for(i=0;i<size;++i)
        rsize+=1+strlen(stacks[i]);
    r=(char*)malloc(sizeof(char)*(rsize+1));
    for(i=0,j=0;i<size;++i) {
        r[j++]='/';
        if(stacks[i]) {
            for(k=0;stacks[i][k];++k)
                r[j++]=stacks[i][k];
            free(stacks[i]);
        }
    }
    r[j]=0;
    if(stacks)
        free(stacks);
    return j?r:"/";
}

