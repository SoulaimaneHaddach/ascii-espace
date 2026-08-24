#include <iostream>
#include <windows.h>

int main()
{
    int width = 20;
    int pos = 0;
    int direction = 1;

    while (true)
    {
        std::cout << "\033[2J\033[1;1H";

        for (int i = 0; i < pos; i++)
            std::cout << " ";
        std::cout << "O" << std::endl;

        pos += direction;

        if (pos == width || pos == 0)
            direction = -direction;

        Sleep(100);
    }
    return 0;
}