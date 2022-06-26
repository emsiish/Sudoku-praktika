#include "solve_sudoku.h"

bool find_free_space(struct board_t* board, int* row, int* column)
{
    for (int x = 0; x < SIZE; x++)
    {
        for (int y = 0; y < SIZE; y++)
        {
            if (!board->board[x][y])
            {
                *row = x;
                *column = y;

                return true;
            }
        }
    }
    return false;
}

bool is_num_in_row(struct board_t* board, int row, int num)
{
    for (int col = 0; col < SIZE; col++)
        if (board->board[row][col] == num)
            return true;
    return false;
}


bool is_num_in_col(struct board_t* board, int col, int num)
{
    for (int row = 0; row < SIZE; row++)
        if (board->board[row][col] == num)
            return true;
    return false;
}

bool is_num_in_box(struct board_t* board, int box_row, int box_col, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board->board[row + box_row][col + box_col] == num)
                return true;
    return false;
}

bool is_safe(struct board_t* board, int row, int col, int num)
{
    if (!is_num_in_row(board, row, num) && !is_num_in_col(board, col, num) && !is_num_in_box(board, row - row % 3, col - col % 3, num) && board->board[row][col] == FREE)
    {
        return true;
    }
    return false;
}

bool sudoku_solve(struct board_t* board)
{
    int row, col;


    if (!find_free_space(board, &row, &col))
        return true;

    for (int num = 1; num <= 9; num++)
    {

        if (is_safe(board, row, col, num))
        {

            board->board[row][col] = num;

            if (sudoku_solve(board))
                return true;

            board->board[row][col] = FREE;
        }
    }

    return false;
}

void printGrid(struct board_t* board)
{
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            printf("%d ", board->board[row][col]);
            if (col == 2 || col == 5)
                printf("| ");
        }
        printf("\n");
        if (row == 2 || row == 5)
        {
            printf("------+-------+------");
            printf("\n");
        }

    }
}
