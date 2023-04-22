bool isValidMove(char Board[8][8], int fromX, int fromY, int toX, int toY)
{
    // ���������, ��� �� ���������� ����� �� ���������
    int dx = toX - fromX;
    int dy = toY - fromY;
    if (abs(dx) != abs(dy))
        return false;
    // ���������, ��� �� ���������� ����� �� ��������� ������
    if (Board[toX][toY] != ' ')
        return false;

    // ���������, ��� �� ���������� ����� �� ���� ������ ��� ������� ����� ����������
    if (!(abs(dx) == 1 || abs(dx) == 2))
        return false;

    // ���������, ��� �� ���� ���� ���� ����� ����������, ������� ����� ������
    if (abs(dx) == 2 && abs(dy) == 2 && Board[(fromX + toX) / 2][(fromY + toY) / 2] == ' ')
        return false;