#include <stdio.h>
#include <stdbool.h>

#define FREE 0
#define SIZE 9


struct board_t {

    int board[SIZE][SIZE];
};

bool find_free_space(struct board_t *board, int* row, int* column)
{
    for (int x = 0; x < 9; x++) 
    {
        for (int y = 0; y < 9; y++) 
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

bool in_row(struct board_t *board, int row, int num)
{
    for (int col = 0; col < SIZE; col++)
        if (board->board[row][col] == num)
            return true;
    return false;
}


bool in_col(struct board_t *board, int col, int num)
{
    for (int row = 0; row < SIZE; row++)
        if (board->board[row][col] == num)
            return true;
    return false;
}

bool in_box(struct board_t *board, int box_row, int box_col, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (board->board[row + box_row][col + box_col] == num)
                return true;
    return false;
}

bool is_safe(struct board_t *board, int row, int col, int num)
{
    return !in_row(board, row, num) && !in_col(board, col, num) && !in_box(board, row - row % 3, col - col % 3, num)
        && board->board[row][col] == FREE;
}

bool sudoku_solve(struct board_t *board)
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

void printGrid(struct board_t *board)
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

int main()
{
    struct board_t* grid = malloc(sizeof(struct board_t));
   
    int board[9][9] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    memcpy(grid->board, board, sizeof(board));
    if (sudoku_solve(grid) == true)
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}