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

    // �������� ��� �����
    char piece = Board[fromX][fromY];

    // ���� ����� - �����
    if (piece == 'K' || piece == 'Q') {
        // ���������, ��� �� ���������� ����� �� ���������
        if (abs(fromX - toX) != abs(fromY - toY))
            return false;
    }
    else {
        // ���������, ��� �� ���������� ����� �� ���� ������ ��� ������� ����� ����������
        if (!(abs(dx) == 1 || abs(dx) == 2))
            return false;
    }


    // ���� ����� ��������� ���������� ���� ����������, ��� ������������ � �����
    if (toX == 0 && Board[toX][toY] == 'B') {
        Board[toX][toY] = 'Q';
        Board[fromX][fromY] = ' '; // ������� ����� � �����
    }
    else if (toX == 7 && Board[toX][toY] == 'A') {
        Board[toX][toY] = 'K';
        Board[fromX][fromY] = ' '; // ������� ����� � �����
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
        // ���������, ��� �� ���� ���� ���� ����� ����������, ������� ����� ������
        if (abs(dx) == 2 && abs(dy) == 2 && Board[(fromX + toX) / 2][(fromY + toY) / 2] == ' ')
            return false;
    }

    return true;
}
bool movePiece(char Board[8][8], int fromX, int fromY, int toX, int toY)
{
    // ���������, ��� �� ���������� ����� �� ��������� ������
    if (Board[toX][toY] != ' ')
        return false;

    // ���������, ��� �� ���������� ����� �� ���������
    if ((fromX + fromY) % 2 != (toX + toY) % 2)
        return false;

    // ���������, ��� �� ���������� ����� �� ���� ������ ��� ������� ����� ����������
    if (!(abs(fromX - toX) == 1 || abs(fromX - toX) == 2))
        return false;

    // ���������, ��� �� ���� ���� ���� ����� ����������, ���� �� ������� �����
    if (abs(fromX - toX) == 2 && abs(fromY - toY) == 2 && Board[(fromX + toX) / 2][(fromY + toY) / 2] == ' ')
        return false;

    // ���� ��� ��������, ���������� ����� �� ����� ������
    Board[toX][toY] = Board[fromX][fromY];
    Board[fromX][fromY] = ' ';

    // ���� �� ���� ���� ���� ����� ����������, �� ������� ��
    if (abs(toX - fromX) == 2 && abs(toY - fromY) == 2)
        Board[(fromX + toX) / 2][(fromY + toY) / 2] = ' ';

    // ���� ����� ��������� ���������� ���� ����������, ��� ������������ � �����
    if (toX == 0 && Board[toX][toY] == 'B') {
        Board[toX][toY] = 'Q';
        Board[fromX][fromY] = ' '; // ������� ����� � �����
    }
    else if (toX == 7 && Board[toX][toY] == 'A') {
        Board[toX][toY] = 'K';
        Board[fromX][fromY] = ' '; // ������� ����� � �����
    }
    // �������� ��� �����
    char piece = Board[fromX][fromY];

    // ���� ����� - �����
    if (piece == 'K' || piece == 'Q') {
        // ���������, ��� �� ���������� ����� �� ���������
        if (abs(fromX - toX) != abs(fromY - toY))
            return false;
    }
    else {
        // ���������, ��� �� ���������� ������� ����� ������ ��� �����
        if (piece != 'A' && toX > fromX)
            return false;
        if (piece != 'B' && toX < fromX)
            return false;
        // ���������, ��� �� ���������� ������� ����� �� ���� ������ �� ���������
        if (abs(fromX - toX) != 1 || abs(fromY - toY) != 1)
            return false;
    }


    // ���� ����� - �����, ��������� ����������� ������������ �� ����� ��������� ������ �� ���������
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
    // ���������, ���� �� ��� ����� ��� ������ ����� �� �����
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

    // ���� ���� � �����, ���� � ������ �� �������� �����, ���� ��������
    if (!whitePiecesLeft || !blackPiecesLeft)
    {
        return true;
    }

    // ���� ����� ��� ������ �� ����� ������� ���, ���� ��������
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
