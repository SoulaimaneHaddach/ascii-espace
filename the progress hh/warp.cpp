#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>

struct Star
{
    double x;
    double y; 
    double z;
};

void resetStar(Star &s)
{
    s.x = ((rand() % 2000) / 1000.0) - 1.0;
    s.y = ((rand() % 2000) / 1000.0) - 1.0;
    s.z = 1.0;
}

int main()
{
    int width = 80;
    int height = 24;
    int numStars = 150;
    double speed = 0.02;

    std::vector<Star> stars(numStars);
    srand(time(0));

    for (int i = 0; i < numStars; i++)
        resetStar(stars[i]);

    while (true)
    {
        std::vector<std::string> screen(height, std::string(width, ' '));

        for (int i = 0; i < numStars; i++)
        {
            stars[i].z -= speed;

            if (stars[i].z <= 0.0)
                resetStar(stars[i]);

            int screenX = (int)(width / 2 + (stars[i].x / stars[i].z) * (width / 2));
            int screenY = (int)(height / 2 + (stars[i].y / stars[i].z) * (height / 2));

            if (screenX >= 0 && screenX < width && screenY >= 0 && screenY < height)
            {
                char c;
                if (stars[i].z > 0.66)
                    c = '.';
                else if (stars[i].z > 0.33)
                    c = '*';
                else
                    c = '@'; 

                screen[screenY][screenX] = c;
            }
        }

        std::cout << "\033[2J\033[1;1H";
        for (int r = 0; r < height; r++)
            std::cout << screen[r] << "\n";

        Sleep(30);
    }
    return 0;
}