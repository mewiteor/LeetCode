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
 * You are playing the following Bulls and Cows game with your friend:
 * You write down a number and ask your friend to guess what the number is.
 * Each time your friend makes a guess, you provide a hint that indicates
 * how many digits in said guess match your secret number exactly in
 * both digit and position (called "bulls") and how many digits match
 * the secret number but locate in the wrong position (called "cows").
 * Your friend will use successive guesses and hints to eventually
 * derive the secret number.
 *
 * For example:
 *
 * Secret number:  "1807"
 * Friend's guess: "7810"
 * Hint: 1 bull and 3 cows. (The bull is 8, the cows are 0, 1 and 7.)
 * Write a function to return a hint according to the secret number and
 * friend's guess, use A to indicate the bulls and B to indicate the cows.
 * In the above example, your function should return "1A3B".
 *
 * Please note that both secret number and friend's guess may contain
 * duplicate digits, for example:
 *
 * Secret number:  "1123"
 * Friend's guess: "0111"
 * In this case, the 1st 1 in friend's guess is a bull, the 2nd or
 * 3rd 1 is a cow, and your function should return "1A1B".
 * You may assume that the secret number and your friend's guess only
 * contain digits, and their lengths are always equal.
 */

char* getHint(char* secret, char* guess) {
    char* ret=NULL;
    size_t s[10]={0},g[10]={0},A=0,B=0,len;
    while(*secret) {
        if(*secret==*guess)
            ++A;
        else {
            ++s[*secret-'0'];
            ++g[*guess-'0'];
        }
        ++secret;
        ++guess;
    }
    for(len=0;len<10;++len)
        B+=s[len]>g[len]?g[len]:s[len];
    len=snprintf(NULL,0,"%zuA%zuB",A,B)+1;
    ret=malloc(len*sizeof(char));
    snprintf(ret,len,"%zuA%zuB",A,B);
    return ret;
}
