#include<iostream>
#include<string>

class tictactoe
{
    public:
        tictactoe();
        bool is_end(int x, int y);
        void play();
        void toggle_player();
        void print();
        void setNames(std:: string, std:: string);
        void wellcome();
        
    private:
        int player = 1;
        char board[3][3];
        int total_move = 0;
        std :: string playerName1, playerName2;
};