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
 * Determine if a Sudoku is valid, according to:
 * Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty
 * cells are filled with the character '.'.
 *
 * +-+-+-+-+-+-+-+-+-+
 * |5|3| | |7| | | | |
 * +-+-+-+-+-+-+-+-+-+
 * |6| | |1|9|5| | | |
 * +-+-+-+-+-+-+-+-+-+
 * | |9|8| | | | |6| |
 * +-+-+-+-+-+-+-+-+-+
 * |8| | | |6| | | |3|
 * +-+-+-+-+-+-+-+-+-+
 * |4| | |8| |3| | |1|
 * +-+-+-+-+-+-+-+-+-+
 * |7| | | |2| | | |6|
 * +-+-+-+-+-+-+-+-+-+
 * | |6| | | | |2|8| |
 * +-+-+-+-+-+-+-+-+-+
 * | | | |4|1|9| | |5|
 * +-+-+-+-+-+-+-+-+-+
 * | | | | |8| | |7|9|
 * +-+-+-+-+-+-+-+-+-+
 *
 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable.
 * Only the filled cells need to be validated.
 */

bool isValidSudoku(char** board, int boardRowSize, int boardColSize) {
	int i,j;
	unsigned short n;
	for(i=0;i<9;++i) {
		n=0;
		for(j=0;j<9;++j) {
			char c=board[i][j];
			if(c!='.') {
				if(n&1<<(c-'1'))
                    return false;
				n|=1<<(c-'1');
			}
		}
	}
	for(i=0;i<9;++i) {
		n=0;
		for(j=0;j<9;++j) {
			char c=board[j][i];
			if(c!='.') {
				if(n&1<<(c-'1'))
                    return false;
				n|=1<<(c-'1');
			}
		}
	}
	for(i=0;i<9;++i) {
		n=0;
		for(j=0;j<9;++j) {
			char c=board[i/3*3+j/3][i%3*3+j%3];
			if(c!='.') {
				if(n&1<<(c-'1'))
                    return false;
				n|=1<<(c-'1');
			}
		}
	}
	return true;
}
