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
 * Given an array of words and a length L, format the text such that
 * each line has exactly L characters and is fully (left and right) justified.
 *
 * You should pack your words in a greedy approach; that is, pack as many words
 * as you can in each line. Pad extra spaces ' ' when necessary so that
 * each line has exactly L characters.
 *
 * Extra spaces between words should be distributed as evenly as possible.
 * If the number of spaces on a line do not divide evenly between words,
 * the empty slots on the left will be assigned more spaces than the slots on the right.
 *
 * For the last line of text, it should be left justified and no extra
 * space is inserted between words.
 *
 * For example,
 * words: ["This", "is", "an", "example", "of", "text", "justification."]
 * L: 16.
 *
 * Return the formatted lines as:
 * [
 *   "This    is    an",
 *   "example  of text",
 *   "justification.  "
 * ]
 * Note: Each word is guaranteed not to exceed L in length.
 *
 * Corner Cases:
 * A line other than the last line might contain only one word. What should you do in this case?
 * In this case, that line should be left-justified.
 */

/*
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int i,j,lastLength;
    char **ret;
    for(i=0,j=0;i<wordsSize;++i)
        if(strlen(words[i]))
            words[j++]=words[i];
    if(!wordsSize) {
        *returnSize=0;
        return (char**)malloc(0);
    }
    ret=(char**)malloc(sizeof(char*));
    *returnSize=1;
    *ret=(char*)malloc((maxWidth+1)*sizeof(char));
    strcpy(*ret,words[0]);
    lastLength=strlen(words[0]);
    for(i=1,j=0;i<wordsSize;++i) {
        int curLength=strlen(words[i])+1;
        if(lastLength+curLength<=maxWidth) {
            ret[*returnSize-1][lastLength]=' ';
            strcpy(ret[*returnSize-1]+lastLength+1,words[i]);
            lastLength+=curLength;
        } else {
            if(i-j<=1)
                memset(ret[*returnSize-1]+lastLength,' ',maxWidth-lastLength);
            else {
                int p=(maxWidth-lastLength)%(i-j-1),q=i-j-1-p,all=i-j-1;
                int lessSpace=(maxWidth-lastLength)/(i-j-1);
                char *l=ret[*returnSize-1]+lastLength-1,*r=ret[*returnSize-1]+maxWidth-1;
                ret[*returnSize-1][maxWidth]=0;
                while(all--) {
                    int t;
                    while(*l!=' ')
                        *r--=*l--;
                    *r--=*l--;
                    if(q) {
                        --q;
                        t=lessSpace;
                    } else {
                        --p;
                        t=lessSpace+1;
                    }
                    while(t--)
                        *r--=' ';
                }
            }
            ret[*returnSize-1][maxWidth]=0;
            j=i;
            ret=(char**)realloc(ret,sizeof(char*)*(*returnSize+1));
            ret[*returnSize]=(char*)malloc((maxWidth+1)*sizeof(char));
            strcpy(ret[(*returnSize)++],words[i]);
            lastLength=curLength-1;
        }
    }
    memset(ret[*returnSize-1]+lastLength,' ',maxWidth-lastLength);
    ret[*returnSize-1][maxWidth]=0;
    return ret;
}

