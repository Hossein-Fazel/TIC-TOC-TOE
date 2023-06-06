#include <iostream>
#include <string>
#include <unistd.h>

#include "game.h"

tictactoe::tictactoe()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }
    wellcome();
}

bool tictactoe::is_end(int x, int y)
{
    char ch;
    if (player == 1)
    {
        ch = 'X';
    }
    else
    {
        ch = 'O';
    }
    if (board[0][0] == ch and board[1][1] == ch and board[2][2] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[0][0] == ch and board[0][1] == ch and board[0][2] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[0][0] == ch and board[1][0] == ch and board[2][0] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[0][1] == ch and board[1][1] == ch and board[2][1] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[0][2] == ch and board[1][2] == ch and board[2][2] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[1][0] == ch and board[1][1] == ch and board[1][2] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[2][0] == ch and board[2][1] == ch and board[2][2] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (board[0][2] == ch and board[1][1] == ch and board[2][0] == ch)
    {
        if (player == 1)
        {
            std::cout << playerName1 << " wins!!!\n";
        }
        else
        {
            std::cout << playerName2 << " wins!!!\n";
        }
        return true;
    }

    else if (total_move == 9)
    {
        std::cout << "that's draw!!!\n";
        return true;
    }

    else
    {
        return false;
    }
}

void tictactoe::toggle_player()
{
    if (total_move % 2 == 1)
    {
        player = 2;
    }

    else
    {
        player = 1;
    }
}

void tictactoe::play()
{
    system("cls");
    std :: cout << "\t\t\t=== TIC TAc TOE ===\n\n";
    player = 1;
    total_move = 0;
    int x;
    std ::string name1, name2;

    std ::cout << "player 1 enter your name => ";
    std ::cin >> name1;

    std ::cout << "player 2 enter your name => ";
    std ::cin >> name2;

    system("cls");
    print();

    setNames(name1, name2);

    while (!is_end(0, 0))
    {
        if (player == 1)
        {
            std::cout << playerName1 << " enter your move\n";
        }
        else
        {
            std::cout << playerName2 << " enter your move\n";
        }

        std::cin >> x;
        while (x <= 0 and x > 9 || board[(x - 1) / 3][(x - 1) % 3] != ' ')
        {

            std::cout << "your entered number is wrong\n";

            if (player == 1)
            {
                std::cout << playerName1 << " enter your move\n";
            }
            else
            {
                std::cout << playerName2 << " enter your move\n";
            }

            std::cin >> x;
        }

        x--;

        if (player == 1)
        {
            board[x / 3][x % 3] = 'X';
        }
        else
        {
            board[x / 3][x % 3] = 'O';
        }

        print();
        if (is_end(x / 3, x % 3))
        {
            break;
        }
        else
        {
            total_move += 1;
            toggle_player();
        }
    }

    std::string answer;
    std::cout << "do yo want to play again? yes / no :\n";
    std::cin >> answer;

    if (answer == "yes" or answer == "Yes" or answer == "YES")
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                board[i][j] = ' ';
            }
        }
        play();
    }
    else
    {
        exit(0);
    }
}

void tictactoe::print()
{
    system("cls");
    std :: cout << "\t\t\t=== TIC TAc TOE ===\n\n";

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << "| " << board[i][j] << " |" << "\t";
        }
        std ::cout << "\n\n\n";
    }
}

void tictactoe::setNames(std::string str1, std::string str2)
{
    playerName1 = str1;
    playerName2 = str2;
}

void tictactoe::wellcome()
{
    std:: cout << "\t\t=== WELLCOME TO TIC TAC TOE GAME ===\n";
    sleep(2);

    system("cls");
}