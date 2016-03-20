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
 * You are playing the following Nim Game with your friend: There is
 * a heap of stones on the table, each time one of you take turns to
 * remove 1 to 3 stones. The one who removes the last stone will be
 * the winner. You will take the first turn to remove the stones.
 *
 * Both of you are very clever and have optimal strategies for the game.
 * Write a function to determine whether you can win the game given
 * the number of stones in the heap.
 *
 * For example, if there are 4 stones in the heap, then you will never
 * win the game: no matter 1, 2, or 3 stones you remove, the last stone
 * will always be removed by your friend.
 *
 * Hint:
 *
 * If there are 5 stones in the heap, could you figure out a way to
 * remove the stones such that you will always be the winner?
 */

bool canWinNim(int n) {
    return !!(n&3);
}
