#include "generate_sudoku.h"
#include <time.h>

struct board_t* init_board(struct board_t* board)  //create a board full of 0
{
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			board->board[row][col] = FREE;
		}
	}
	return board;
}


bool repetitions_in_row(struct board_t* board, int row, int col)
{
	for (int s = 0; s < col; s++)
	{
		if (board->board[row][col] == board->board[row][s])
		{
			return false;
		}
	}
	return true;
}

bool repetitions_in_col(struct board_t* board, int row, int col)
{
	for (int s = 0; s < row; s++)
	{
		if (board->board[row][col] == board->board[s][col])
		{
			return false;
		}
	}
	return true;
}

bool repetitions_in_box(struct board_t* board, int row, int col)
{
	if (row >= row - row % 3 && row < 3 + row - row % 3)
	{
		if (col >= col - col % 3 && col < 3 + col - col % 3)
		{
			for (int s = row - row % 3; s < 3 + row - row % 3; s++) // box row
			{
				for (int c = col - col % 3; c < 3 + col - col % 3; c++) // box col
				{
					if (board->board[row][col] == board->board[s][c] && (s != row && c != col))
					{
						return false;
					}
				}
			}
		}
	}
	return true;
}

struct board_t* generate_sudoku(struct board_t* board)
{
	int repetitions = 0;

	srand(time(NULL));
	for (int row = 0; row < 9; row++)
	{
		for (int col = 0; col < 9; col++)
		{
			if (repetitions > 45) //random chislo
			{
				for (int c = 0; c < 9; c++)
				{
					board->board[row][c] = FREE;
				}
				row--;
				repetitions = 0;
			}
			board->board[row][col] = (rand() % 9) + 1;

			if (!repetitions_in_row(board, row, col) || !repetitions_in_col(board, row, col) || !repetitions_in_box(board, row, col))
			{
				repetitions++;
				col--;
				continue;
			}
			repetitions = 0;
		}
	}
	return board;
}

struct board_t* create_puzzle(int q, struct board_t* copy, struct board_t* board)
{
	int x, y;

	srand(time(NULL));
	for (int i = 0; i < q; i++)
	{
		x = (rand() % 9);
		y = (rand() % 9);
		if (board->board[x][y] != FREE)
		{
			i--;
			continue;
		}
		board->board[x][y] = copy->board[x][y];
	}
	return board;
}
