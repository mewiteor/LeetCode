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
 * Design a stack that supports push, pop, top, and retrieving the
 * minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

typedef struct {
    struct Data{int value,min;} *data;
    int maxSize,size;
} MinStack;

void minStackCreate(MinStack *stack, int maxSize) {
    stack->maxSize=maxSize;
    stack->size=0;
    stack->data=(struct Data*)malloc(maxSize*sizeof*stack->data);
}

void minStackPush(MinStack *stack, int element) {
    if(stack->size<stack->maxSize) {
        stack->data[stack->size].value=element;
        stack->data[stack->size].min=element;
        if(stack->size&&stack->data[stack->size-1].min<element)
            stack->data[stack->size].min=stack->data[stack->size-1].min;
        ++stack->size;
    }
}

void minStackPop(MinStack *stack) {
    if(stack->size)
        --stack->size;
}

int minStackTop(MinStack *stack) {
    if(!stack->size)
        return 0;
    else
        return stack->data[stack->size-1].value;
}

int minStackGetMin(MinStack *stack) {
    if(!stack->size)
        return 0;
    else
        return stack->data[stack->size-1].min;
}

void minStackDestroy(MinStack *stack) {
    if(stack) {
        if(stack->data) {
            free(stack->data);
            stack->data=NULL;
        }
        stack->size=0;
        stack->maxSize=0;
    }
}
