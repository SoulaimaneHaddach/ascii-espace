#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

int main()
{
    int rows = 20;
    int cols = 50;

    // grid[row][col] holds either ' ' (empty) or '*' (a star)
    std::vector<std::string> grid(rows, std::string(cols, ' '));

    srand(time(0)); // seed random numbers so stars look different each run

    while (true)
    {
        // 1. Clear the screen
        std::cout << "\033[2J\033[1;1H";

        // 2. Shift every row down by one
        //    (row i copies what row i-1 had, starting from the bottom)
        for (int i = rows - 1; i > 0; i--)
            grid[i] = grid[i - 1];

        // 3. Fill the top row with new random stars
        for (int c = 0; c < cols; c++)
        {
            int chance = rand() % 20; // 1 in 20 chance of a star
            grid[0][c] = (chance == 0) ? '*' : ' ';
        }

        // 4. Print the whole grid
        for (int r = 0; r < rows; r++)
            std::cout << grid[r] << std::endl;

        // 5. Pause before next frame
        Sleep(100);
    }
    return 0;
}