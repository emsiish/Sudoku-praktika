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
		printf("How many numbers do you want on your sudoku (level of difficulty):\n(min:16 / max:36) ");
		scanf("%d", &quantity);
	} while (quantity < 16 || quantity > 36);
	grid = create_puzzle(quantity + 1, copy, grid);
	printGrid(grid);
	printf("\n\n");
	free(copy);
    if (sudoku_solve(grid) == true)
        printGrid(grid);
    else
        printf("No solution exists");
	free(grid);
    return 0;
}
