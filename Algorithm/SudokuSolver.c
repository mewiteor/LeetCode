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
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 *
 * Empty cells are indicated by the character '.'.
 *
 * You may assume that there will be only one unique solution.
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
 * A sudoku puzzle...
 *
 * +-+-+-+-+-+-+-+-+-+
 * |5|3|4|6|7|8|9|1|2|
 * +-+-+-+-+-+-+-+-+-+
 * |6|7|2|1|9|5|3|4|8|
 * +-+-+-+-+-+-+-+-+-+
 * |1|9|8|3|4|2|5|6|7|
 * +-+-+-+-+-+-+-+-+-+
 * |8|5|9|7|6|1|4|2|3|
 * +-+-+-+-+-+-+-+-+-+
 * |4|2|6|8|5|3|7|9|1|
 * +-+-+-+-+-+-+-+-+-+
 * |7|1|3|9|2|4|8|5|6|
 * +-+-+-+-+-+-+-+-+-+
 * |9|6|1|5|3|7|2|8|4|
 * +-+-+-+-+-+-+-+-+-+
 * |2|8|7|4|1|9|6|3|5|
 * +-+-+-+-+-+-+-+-+-+
 * |3|4|5|2|8|6|1|7|9|
 * +-+-+-+-+-+-+-+-+-+
 *
 * ...and its solution numbers marked in red.
 */

typedef struct {
	unsigned char n;
	unsigned char num[9];
	bool bOldOne;
} SudokuNums;

void rmv(SudokuNums* sn, unsigned char x) {
	int i;
	if (!sn)return;
	for (i = 0; i < sn->n; ++i)
		if (sn->num[i] == x) {
			unsigned char t = sn->num[i];
			sn->num[i] = sn->num[--sn->n];
			sn->num[sn->n] = t;
			break;
		}
}

bool clears(SudokuNums tmps[9][9], int i, int j, unsigned char nm)
{
	int k;
	bool isNew = true;
	tmps[i][j].bOldOne = true;
	for (k = 0; k < 9; ++k)
		if (k != j)
			rmv(&tmps[i][k], nm);
	for (k = 0; k < 9; ++k)
		if (k != i)
			rmv(&tmps[k][j], nm);
	for (k = 0; k < 9; ++k)
		if (k != i % 3 * 3 + j % 3)
			rmv(&tmps[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3], nm);
	while (isNew) {
		isNew = false;
		for (i = 0; i < 9; ++i)
			for (j = 0; j < 9; ++j) {
				if (!tmps[i][j].n) return false;
				else if (!tmps[i][j].bOldOne&&tmps[i][j].n == 1) {
					tmps[i][j].bOldOne = true;
					for (k = 0; k < 9; ++k)
						if (k != j)
							rmv(&tmps[i][k], tmps[i][j].num[0]);
					for (k = 0; k < 9; ++k)
						if (k != i)
							rmv(&tmps[k][j], tmps[i][j].num[0]);
					for (k = 0; k < 9; ++k)
						if (k != i % 3 * 3 + j % 3)
							rmv(&tmps[i / 3 * 3 + k / 3][j / 3 * 3 + k % 3], tmps[i][j].num[0]);
					isNew = true;
				}
			}
	}
	return true;
}

bool subcalculator(SudokuNums tmps[9][9], int i, int j) {
	if (i >= 9)
        return true;
	if (j >= 9)
        return subcalculator(tmps, i + 1, 0);
	else {
		if (!tmps[i][j].n)
            return false;
		else if (tmps[i][j].n == 1)
			return subcalculator(tmps, i, j + 1);
		else {
			SudokuNums tt[9][9];
			int k;
			memcpy(tt, tmps,sizeof tt);
			for (k = 0; k < tmps[i][j].n; ++k) {
				tmps[i][j].n = 1;
				tmps[i][j].num[0] = tmps[i][j].num[k];
				if (clears(tmps, i, j, tmps[i][j].num[0])) {
					if(subcalculator(tmps, i, j + 1))
						return true;
				}
				memcpy(tmps, tt, sizeof tt);
			}
			return false;
		}
	}
}

void solveSudoku(char** board, int boardRowSize, int boardColSize) {
	SudokuNums tmps[9][9];
	int i, j, k;
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j) {
			tmps[i][j].n = 9;
			tmps[i][j].bOldOne = false;
			for (k = 0; k < 9; ++k)
				tmps[i][j].num[k] = (unsigned char)( k + 1 );
		}
	for (i = 0; i < 9; ++i)
		for (j = 0; j < 9; ++j)
			if (board[i][j]!='.') {
				tmps[i][j].n = 1;
				tmps[i][j].num[0] = board[i][j]-'0';
				clears(tmps, i, j, board[i][j]-'0');
			}
	for(i=0;i<9;++i) {
		for(j=0;j<9;++j)
			if(tmps[i][j].n!=1)
				break;
		if(j<9)break;
	}
	if(i<9)
        subcalculator(tmps, 0, 0);
	for(i=0;i<9;++i)
		for(j=0;j<9;++j)
			board[i][j]=tmps[i][j].num[0]+'0';
}
