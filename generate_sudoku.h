#include "helper.h"

struct board_t* init_board(struct board_t* board);
bool repetitions_in_row(struct board_t* board, int row, int col);
bool repetitions_in_col(struct board_t* board, int row, int col);
bool repetitions_in_box(struct board_t* board, int row, int col);
struct board_t* generate_sudoku(struct board_t* board);
struct board_t* create_puzzle(int q, struct board_t* copy, struct board_t* board);
