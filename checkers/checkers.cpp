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