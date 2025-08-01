#include <iostream> 

using namespace std;



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



int main()
{
    minimap();
    return 0;
}