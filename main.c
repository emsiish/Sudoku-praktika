#define _CRT_SECURE_NO_WARNINGS
#include "generate_sudoku.h"
#include "solve_sudoku.h"

int main()
{
	int quantity = 0;
	struct board_t* grid = malloc(sizeof(struct board_t));
	struct board_t* copy = malloc(sizeof(struct board_t));

	copy = init_board(copy);
	grid = init_board(grid);
	copy = generate_sudoku(copy);
	do {
		//system("cls");
		printf("How many numbers do you want on your sudoku:\n(min:16 / max:32) ");
		scanf("%d", &quantity);
	} while (quantity < 16 || quantity>32);
	grid = create_puzzle(quantity, copy, grid);
	printGrid(grid);
	printf("\n\n");
    if (sudoku_solve(grid) == true)
        printGrid(grid);
    else
        printf("No solution exists");

    return 0;
}
