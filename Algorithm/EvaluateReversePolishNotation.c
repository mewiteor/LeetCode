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
 * Evaluate the value of an arithmetic expression in Reverse Polish Notation.
 *
 * Valid operators are +, -, *, /. Each operand may be an integer or another expression.
 *
 * Some examples:
 *   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
 *   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */

int evalRPN(char** tokens, int tokensSize) {
    int *stack=NULL,size=0;
    int i;
    for(i=0;i<tokensSize;++i)
        if(!strcmp(tokens[i],"+")) {
            stack[size-2]+=stack[size-1];
            stack=(int*)realloc(stack,--size*sizeof(int));
        } else if(!strcmp(tokens[i],"-")) {
            stack[size-2]-=stack[size-1];
            stack=(int*)realloc(stack,--size*sizeof(int));
        } else if(!strcmp(tokens[i],"*")) {
            stack[size-2]*=stack[size-1];
            stack=(int*)realloc(stack,--size*sizeof(int));
        } else if(!strcmp(tokens[i],"/")) {
            stack[size-2]/=stack[size-1];
            stack=(int*)realloc(stack,--size*sizeof(int));
        } else {
            stack=(int*)realloc(stack,++size*sizeof(int));
            stack[size-1]=atoi(tokens[i]);
        }
    i=stack[0];
    free(stack);
    return i;
}
