#include <iostream>
using namespace std;

void Display(char Board[8][8])
{
    int i;
    for (i = 0; i < 8; i++)
    {
        cout << " +---+---+---+---+---+---+---+---+" << endl;
        cout << i + 1 << " | " << Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << " | " << Board[i][3] << " | " << Board[i][4] << " | " << Board[i][5] << " | " << Board[i][6] << " | " << Board[i][7] << " |" << endl;
    }
    cout << "  +---+---+---+---+---+---+---+---+" << endl;
    cout << "    A   B   C   D   E   F   G   H  " << endl;
}
