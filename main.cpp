#include <iostream> 
using namespace std;
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

char getch()
{
/*
lecture d'une touche instantannée 
*/
struct termios oldt, newt;
char ch;
tcgetattr(STDERR_FILENO, &oldt);
newt = oldt;
newt.c_lflag &= ~(ICANON | ECHO);
ch = getchar();
tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
return ch;
}

bool kbhit() {
    termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return true;
    }

    return false;
}


float posPlayerX = 5.0f; // des flottants pour se balader sur les endroits ne contenant que du sol.
float posPlayerY = 5.0f;

float dirX = 0.0f;        // Direction dans laquelle le joueur regarde.
float dirY = 1.0f;

int screenWidth = 80;
int screenHeight = 24;

int grid[10][10] = { // Ici on crée une sorte de carte dans laquel on y met des 0 pour les sols sans murs et 1 pour les murs
        {1,1,1,1,1,1,1,1,1,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,1,0,0,1},
        {1,1,0,0,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,1},
        {1,0,0,1,0,0,0,0,0,1},
        {1,0,1,0,0,0,0,0,0,1},
        {1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,1,1,1,1,1}
}; 



void minimap()
{
    for (int y = 0; y <= 9; y++)
    {
        for (int x = 0; x<= 9; x++)
        {
            if (posPlayerX == x && posPlayerY == y)
            {
                std::cout << "P";
            }
            else if (grid[y][x] == 1)
            {
                std::cout << "#";
            }
            else 
                std::cout << "."; 
          }
    std::cout << std::endl ;
    }
}

void inputs()
{
}


int main()
{
    while (1)
    {
        if (kbhit())
        {
            char z = getch();
            posPlayerY = posPlayerY - 1;
            minimap();

        }
        else if (kbhit())
        {
            char q = getch();
            posPlayerX = posPlayerX -1;
            minimap();

        }
        else if (kbhit())
        {
            char s = getch();
            posPlayerY = posPlayerY + 1;
            minimap();

        }
        else if (kbhit())
        {
            char d = getch();
            posPlayerX = posPlayerX  +1;
            minimap();
            
        }
        

    }
    minimap();
    return 0;
}