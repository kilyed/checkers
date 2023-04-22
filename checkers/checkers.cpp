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

bool isValidMove(char Board[8][8], int fromX, int fromY, int toX, int toY)
{
    // Проверяем, что мы перемещаем шашку по диагонали
    int dx = toX - fromX;
    int dy = toY - fromY;
    if (abs(dx) != abs(dy))
        return false;
    // Проверяем, что мы перемещаем шашку на свободную клетку
    if (Board[toX][toY] != ' ')
        return false;

    // Проверяем, что мы перемещаем шашку на одну клетку или съедаем шашку противника
    if (!(abs(dx) == 1 || abs(dx) == 2))
        return false;

    // Проверяем, что на пути хода есть шашка противника, которую можно съесть
    if (abs(dx) == 2 && abs(dy) == 2 && Board[(fromX + toX) / 2][(fromY + toY) / 2] == ' ')
        return false;

    // Получаем тип шашки
    char piece = Board[fromX][fromY];

    // Если шашка - дамка
    if (piece == 'K' || piece == 'Q') {
        // Проверяем, что мы перемещаем дамку по диагонали
        if (abs(fromX - toX) != abs(fromY - toY))
            return false;
    }
    else {
        // Проверяем, что мы перемещаем шашку на одну клетку или съедаем шашку противника
        if (!(abs(dx) == 1 || abs(dx) == 2))
            return false;
    }


    // Если шашка достигает последнего ряда противника, она превращается в дамку
    if (toX == 0 && Board[toX][toY] == 'B') {
        Board[toX][toY] = 'Q';
        Board[fromX][fromY] = ' '; // удаляем шашку с доски
    }
    else if (toX == 7 && Board[toX][toY] == 'A') {
        Board[toX][toY] = 'K';
        Board[fromX][fromY] = ' '; // удаляем шашку с доски
    }


    if (piece == 'K' || piece == 'Q') {
        int xDir = (toX - fromX) > 0 ? 1 : -1;
        int yDir = (toY - fromY) > 0 ? 1 : -1;

        int i = fromX + xDir;
        int j = fromY + yDir;

        while (i != toX && j != toY) {
            if (Board[i][j] != ' ') {
                return false;
            }
            i += xDir;
            j += yDir;
        }
    }
    else {
        // Проверяем, что на пути хода есть шашка противника, которую можно съесть
        if (abs(dx) == 2 && abs(dy) == 2 && Board[(fromX + toX) / 2][(fromY + toY) / 2] == ' ')
            return false;
    }

    return true;
}
bool movePiece(char Board[8][8], int fromX, int fromY, int toX, int toY)
{
    // Проверяем, что мы перемещаем шашку на свободную клетку
    if (Board[toX][toY] != ' ')
        return false;

    // Проверяем, что мы перемещаем шашку по диагонали
    if ((fromX + fromY) % 2 != (toX + toY) % 2)
        return false;

    // Проверяем, что мы перемещаем шашку на одну клетку или съедаем шашку противника
    if (!(abs(fromX - toX) == 1 || abs(fromX - toX) == 2))
        return false;

    // Проверяем, что на пути хода есть шашка противника, если мы съедаем шашку
    if (abs(fromX - toX) == 2 && abs(fromY - toY) == 2 && Board[(fromX + toX) / 2][(fromY + toY) / 2] == ' ')
        return false;

    // Если ход допустим, перемещаем шашку на новую клетку
    Board[toX][toY] = Board[fromX][fromY];
    Board[fromX][fromY] = ' ';

    // Если на пути хода была шашка противника, то удаляем ее
    if (abs(toX - fromX) == 2 && abs(toY - fromY) == 2)
        Board[(fromX + toX) / 2][(fromY + toY) / 2] = ' ';

    // Если шашка достигает последнего ряда противника, она превращается в дамку
    if (toX == 0 && Board[toX][toY] == 'B') {
        Board[toX][toY] = 'Q';
        Board[fromX][fromY] = ' '; // удаляем шашку с доски
    }
    else if (toX == 7 && Board[toX][toY] == 'A') {
        Board[toX][toY] = 'K';
        Board[fromX][fromY] = ' '; // удаляем шашку с доски
    }
    // Получаем тип шашки
    char piece = Board[fromX][fromY];

    // Если шашка - дамка
    if (piece == 'K' || piece == 'Q') {
        // Проверяем, что мы перемещаем дамку по диагонали
        if (abs(fromX - toX) != abs(fromY - toY))
            return false;
    }
    else {
        // Проверяем, что мы перемещаем обычную шашку вперед или назад
        if (piece != 'A' && toX > fromX)
            return false;
        if (piece != 'B' && toX < fromX)
            return false;
        // Проверяем, что мы перемещаем обычную шашку на одну клетку по диагонали
        if (abs(fromX - toX) != 1 || abs(fromY - toY) != 1)
            return false;
    }


    // Если шашка - дамка, проверяем возможность передвижения на любую свободную клетку по диагонали
    if (piece == 'K' || piece == 'Q') {
        int xDir = (toX - fromX) > 0 ? 1 : -1;
        int yDir = (toY - fromY) > 0 ? 1 : -1;

        int i = fromX + xDir;
        int j = fromY + yDir;

        while (i != toX && j != toY) {
            if (Board[i][j] != ' ') {
                return false;
            }
            i += xDir;
            j += yDir;
        }
    }

    return true;
}





bool isGameOver(char Board[8][8])
{
    bool whitePiecesLeft = false;
    bool blackPiecesLeft = false;
    // Проверяем, есть ли еще белые или черные шашки на доске
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i][j] == 'A' || Board[i][j] == 'K')
            {
                whitePiecesLeft = true;
            }
            else if (Board[i][j] == 'B' || Board[i][j] == 'Q')
            {
                blackPiecesLeft = true;
            }
        }
    }

    // Если либо у белых, либо у черных не осталось шашек, игра окончена
    if (!whitePiecesLeft || !blackPiecesLeft)
    {
        return true;
    }

    // Если белые или черные не могут сделать ход, игра окончена
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (Board[i][j] == 'A' || Board[i][j] == 'K')
            {
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (isValidMove(Board, i, j, i + k, j + l))
                        {
                            return false;
                        }
                    }
                }
            }
            else if (Board[i][j] == 'B' || Board[i][j] == 'Q')
            {
                for (int k = -1; k <= 1; k++)
                {
                    for (int l = -1; l <= 1; l++)
                    {
                        if (isValidMove(Board, i, j, i + k, j + l))
                        {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}
