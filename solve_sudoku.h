#include "generate_sudoku.h"

bool find_free_space(struct board_t* board, int* row, int* column);
bool is_num_in_row(struct board_t* board, int row, int num);
bool is_num_in_col(struct board_t* board, int col, int num);
bool is_num_in_box(struct board_t* board, int box_row, int box_col, int num);
bool is_safe(struct board_t* board, int row, int col, int num);
bool sudoku_solve(struct board_t* board);
void printGrid(struct board_t* board);
