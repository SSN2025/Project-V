#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void draw_board(int board[8][8])
{
    system("cls");
    printf("\n     ");
    for (int i = 'a'; i <= 'h'; i++)
    {
        printf("%c ", i);
    }
    printf("\n");
    for (int i = 0; i < 8; i++)
    {
        printf("\n  %d: ", 9 - (i + 1));
        for (int j = 0; j < 8; j++)
        { /*
          pawn = 1
          eleph = 2
          horse =  3
          camel = 4
          queen = 5
          king = 6
          */
            switch (board[i][j])
            {
            case 0:
                printf("_ ");
                break;
            case 1:
                printf("p ");
                break;
            case 2:
                printf("r ");
                break;
            case 3:
                printf("n ");
                break;
            case 4:
                printf("b ");
                break;
            case 5:
                printf("q ");
                break;
            case 6:
                printf("k ");
                break;
            case -1:
                printf("P ");
                break;
            case -2:
                printf("R ");
                break;
            case -3:
                printf("N ");
                break;
            case -4:
                printf("B ");
                break;
            case -5:
                printf("Q ");
                break;
            case -6:
                printf("K ");
                break;
            }
        }
        printf(" :%d", 9 - (i + 1));
    }
    printf("\n\n     ");
    for (int i = 'a'; i <= 'h'; i++)
    {
        printf("%c ", i);
    }
}
void move(int brd[8][8], int c_fr, int r_fr, int c_to, int r_to)
{
    brd[r_to][c_to] = brd[r_fr][c_fr];
    brd[r_fr][c_fr] = 0;
}
int valid(int brd[8][8], int c_fr, int r_fr, int c_to, int r_to,int count)
{
    if (brd[r_to][c_to] * brd[r_fr][c_fr] > 0)
    {
        return 0;
    }
   
    if((brd[r_fr][c_fr])*(count) <0){
        return 0;
    }
    switch (brd[r_fr][c_fr])
    {
    case 0:
        return 0;
    case 1:
        if ((r_fr == 6) && (r_to == r_fr - 2) && (c_to == c_fr) && (brd[r_to][c_to] == 0))
        {
            return 1;
        }
        else if ((r_to == r_fr - 1) && (c_to == c_fr) && (brd[r_to][c_to] == 0))
        {
            return 1;
        }
        else if ((r_to == r_fr - 1) && (c_to != c_fr) && (brd[r_to][c_to] < 0))
        {
            return 1;
        }
        return 0;
    case 2:
        if ((r_to != r_fr) && (c_to != c_fr))
        {
            return 0;
        }
        if (r_to < r_fr)
        {
            for (int i = 1; r_to < r_fr - i; i++)
            {
                if (brd[r_fr - i][c_fr] != 0)
                {
                    return 0;
                }
            }
        }
        else if (r_to > r_fr)
        {
            for (int i = 1; r_to > r_fr + i; i++)
            {
                if (brd[r_fr + i][c_fr] != 0)
                {
                    return 0;
                }
            }
        }
        else if (c_to < c_fr)
        {
            for (int i = 1; c_to < c_fr - i; i++)
            {
                if (brd[r_fr][c_fr - i] != 0)
                {
                    return 0;
                }
            }
        }
        else if (c_to > c_fr)
        {
            for (int i = 1; c_to > c_fr + i; i++)
            {
                if (brd[r_fr][c_fr + i] != 0)
                {
                    return 0;
                }
            }
        }
        return 1;

    case 3:

        if ((r_to == r_fr + 2) && (c_to == c_fr + 1))
        {
            return 1;
        }
        else if ((r_to == r_fr - 2) && (c_to == c_fr + 1))
        {
            return 1;
        }
        else if ((r_to == r_fr + 2) && (c_to == c_fr - 1))
        {
            return 1;
        }
        else if ((r_to == r_fr - 2) && (c_to == c_fr - 1))
        {
            return 1;
        }
        else if ((r_to == r_fr + 1) && (c_to == c_fr + 2))
        {
            return 1;
        }
        else if ((r_to == r_fr - 1) && (c_to == c_fr + 2))
        {
            return 1;
        }
        else if ((r_to == r_fr + 1) && (c_to == c_fr - 2))
        {
            return 1;
        }
        else if ((r_to == r_fr - 1) && (c_to == c_fr - 2))
        {
            return 1;
        }
        return 0;
    case 4:

        if (abs(r_to - r_fr) != abs(c_fr - c_to))
        {
            return 0;
        }
        int a = (r_to - r_fr) / abs(r_to - r_fr);
        int b = (c_to - c_fr) / abs(c_to - c_fr);
        for (; r_fr + a != r_to;)
        {
            if (brd[r_fr + a][c_fr + b] != 0)
            {
                return 0;
            }
            if (a > 0)
            {
                a++;
            }
            else if (a < 0)
            {
                a--;
            }
            if (b > 0)
            {
                b++;
            }
            else if (b < 0)
            {
                b--;
            }
        }
        return 1;
    case 5:

        if (r_to == r_fr)
        {
            if (c_to < c_fr)
            {
                for (int i = 1; c_to < c_fr - i; i++)
                {
                    if (brd[r_fr][c_fr - i] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else if (c_to > c_fr)
            {
                for (int i = 1; c_to > c_fr + i; i++)
                {
                    if (brd[r_fr][c_fr + i] != 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (c_to == c_fr)
        {
            if (r_to < r_fr)
            {
                for (int i = 1; r_to < r_fr - i; i++)
                {
                    if (brd[r_fr - i][c_fr] != 0)
                    {
                        return 0;
                    }
                }
            }
            else if (r_to > r_fr)
            {
                for (int i = 1; r_to > r_fr + i; i++)
                {
                    if (brd[r_fr + i][c_fr] != 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (abs(r_to - r_fr) == abs(c_fr - c_to))
        {
            int a = (r_to - r_fr) / abs(r_to - r_fr);
            int b = (c_to - c_fr) / abs(c_to - c_fr);
            for (; r_fr + a != r_to;)
            {
                if (brd[r_fr + a][c_fr + b] != 0)
                {
                    return 0;
                }
                if (a > 0)
                {
                    a++;
                }
                else if (a < 0)
                {
                    a--;
                }
                if (b > 0)
                {
                    b++;
                }
                else if (b < 0)
                {
                    b--;
                }
            }
            return 1;
        }
        return 0;
    case 6:

        if (((abs(r_to - r_fr) == 0) || (abs(r_to - r_fr) == 1)) && ((abs(c_to - c_fr) == 0) || (abs(c_to - c_fr) == 1)))
        {
            return 1;
        }
        return 0;
    case -1:
        if ((r_fr == 1) && (r_to == r_fr + 2) && (c_to == c_fr) && (brd[r_to][c_to] == 0))
        {
            return 1;
        }
        else if ((r_to == r_fr + 1) && (c_to == c_fr) && (brd[r_to][c_to] == 0))
        {
            return 1;
        }
        else if ((r_to == r_fr + 1) && (c_to != c_fr) && (brd[r_to][c_to] > 0))
        {
            return 1;
        }
        return 0;
        break;
    case -2:
        if ((r_to != r_fr) && (c_to != c_fr))
        {
            return 0;
        }
        if (r_to < r_fr)
        {
            for (int i = 1; r_to < r_fr - i; i++)
            {
                if (brd[r_fr - i][c_fr] != 0)
                {
                    return 0;
                }
            }
        }
        else if (r_to > r_fr)
        {
            for (int i = 1; r_to > r_fr + i; i++)
            {
                if (brd[r_fr + i][c_fr] != 0)
                {
                    return 0;
                }
            }
        }
        else if (c_to < c_fr)
        {
            for (int i = 1; c_to < c_fr - i; i++)
            {
                if (brd[r_fr][c_fr - i] != 0)
                {
                    return 0;
                }
            }
        }
        else if (c_to > c_fr)
        {
            for (int i = 1; c_to > c_fr + i; i++)
            {
                if (brd[r_fr][c_fr + i] != 0)
                {
                    return 0;
                }
            }
        }

        return 1;

    case -3:

        if ((r_to == r_fr + 2) && (c_to == c_fr + 1))
        {
            return 1;
        }
        else if ((r_to == r_fr - 2) && (c_to == c_fr + 1))
        {
            return 1;
        }
        else if ((r_to == r_fr + 2) && (c_to == c_fr - 1))
        {
            return 1;
        }
        else if ((r_to == r_fr - 2) && (c_to == c_fr - 1))
        {
            return 1;
        }
        else if ((r_to == r_fr + 1) && (c_to == c_fr + 2))
        {
            return 1;
        }
        else if ((r_to == r_fr - 1) && (c_to == c_fr + 2))
        {
            return 1;
        }
        else if ((r_to == r_fr + 1) && (c_to == c_fr - 2))
        {
            return 1;
        }
        else if ((r_to == r_fr - 1) && (c_to == c_fr - 2))
        {
            return 1;
        }
        return 0;

    case -4:

        if (abs(r_to - r_fr) != abs(c_fr - c_to))
        {
            return 0;
        }
        a = (r_to - r_fr) / abs(r_to - r_fr);
        b = (c_to - c_fr) / abs(c_to - c_fr);
        for (; r_to != r_fr + a;)
        {
            if (brd[r_fr + a][c_fr + b] != 0)
            {
                return 0;
            }
            if (a > 0)
            {
                a++;
            }
            else if (a < 0)
            {
                a--;
            }
            if (b > 0)
            {
                b++;
            }
            else if (b < 0)
            {
                b--;
            }
        }
        return 1;
    case -5:

        if (r_to == r_fr)
        {
            if (c_to < c_fr)
            {
                for (int i = 1; c_to < c_fr - i; i++)
                {
                    if (brd[r_fr][c_fr - i] != 0)
                    {
                        return 0;
                    }
                }
                return 1;
            }
            else if (c_to > c_fr)
            {
                for (int i = 1; c_to > c_fr + i; i++)
                {
                    if (brd[r_fr][c_fr + i] != 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (c_to == c_fr)
        {
            if (r_to < r_fr)
            {
                for (int i = 1; r_to < r_fr - i; i++)
                {
                    if (brd[r_fr - i][c_fr] != 0)
                    {
                        return 0;
                    }
                }
            }
            else if (r_to > r_fr)
            {
                for (int i = 1; r_to > r_fr + i; i++)
                {
                    if (brd[r_fr + i][c_fr] != 0)
                    {
                        return 0;
                    }
                }
            }
            return 1;
        }
        else if (abs(r_to - r_fr) == abs(c_fr - c_to))
        {
            int a = (r_to - r_fr) / abs(r_to - r_fr);
            int b = (c_to - c_fr) / abs(c_to - c_fr);
            for (; r_fr + a != r_to;)
            {
                if (brd[r_fr + a][c_fr + b] != 0)
                {
                    return 0;
                }
                if (a > 0)
                {
                    a++;
                }
                else if (a < 0)
                {
                    a--;
                }
                if (b > 0)
                {
                    b++;
                }
                else if (b < 0)
                {
                    b--;
                }
            }
            return 1;
        }
        return 0;

    case -6:

        if (((abs(r_to - r_fr) == 0) || (abs(r_to - r_fr) == 1)) && ((abs(c_to - c_fr) == 0) || (abs(c_to - c_fr) == 1)))
        {
            return 1;
        }
        return 0;
    }
}
int main()
{
    int board[8][8] = {{-2, -3, -4, -5, -6, -4, -3, -2}, // 8
                       {-1, -1, -1, -1, -1, -1, -1, -1}, // 7
                       {0, 0, 0, 0, 0, 0, 0, 0},         // 6
                       {0, 0, 0, 0, 0, 0, 0, 0},         // 5
                       {0, 0, 0, 0, 0, 0, 0, 0},         // 4
                       {0, 0, 0, 0, 0, 0, 0, 0},         // 3
                       {1, 1, 1, 1, 1, 1, 1, 1},         // 2
                       {2, 3, 4, 5, 6, 4, 3, 2}};        // 1
                                                         // a  b  c  d  e  f  g  h
    draw_board(board);
    int count = 1;
    int row_fr, column_fr, row_to, column_to;
    while (1)
    {
        if (count > 0)
        {
            printf("\nWhite>");
        }
        else if (count < 0)
        {
            printf("\nBlack>");
        }
        char str[6];
        fgets(str, 6, stdin);
        if (str[0] == '\n')
        {
            fgets(str, 6, stdin);
        }
        column_fr = str[0] - 'a';
        row_fr = 7 - (str[1] - '1');
        column_to = str[3] - 'a';
        row_to = 7 - (str[4] - '1');
        if (valid(board, column_fr, row_fr, column_to, row_to,count))
        {
            move(board, column_fr, row_fr, column_to, row_to);
            (count > 0) ? (count = -1) : (count = 1);
        }
        else
        {
            printf("Move Not valid,try again");
            sleep(2);
        }
        draw_board(board);
    }
    return 0;
}