#include "core/global.h"
//#include <curses.h>
#include <fstream>
#include <iostream>


int printboard(vector<vector<int>>& board, int n)
{
    //ofstream debug;
    //debug.open("test", ios::out);

    //keypad(initscr(),1);
    //curs_set(0);

    system("clear");

    //move(5*n, 5*n);

    printf("SCORE : %d", score);

    cout << endl << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            //string s = to_string(board[i][j]);
            //char const *c = s.c_str();


            //mvaddch(i, j, (char)(board[i][j] + 48));
            //mvprintw(6*i, 6*j, c);


            //move(4*i, 4*j);

            if (board[i][j])
                printf("%d", board[i][j]);
            
            else 
                printf("%d", board[i][j]);

            //debug << board[i][j] << " ";
            
            cout << "    "; 
            
        }
        //debug << endl;
        cout << endl;
    }
    
    //debug.close();

    //emptypos;
    emptycell(board, n);

    //checks if no move possible and game ended.

    if (emptypos.empty() && !checkmove(board, n))
    {
        //move(6*n, 0);
        system("clear");
        printf("\n\nGame Ended, Out of Moves.\nFinal Score : %d \nPress any key to quit.", score);
        cin.get();
        //return endwin();
        return 0;
    }

    //exected only if move possible

    tilemove(board, n); 

    //ideally control never reaches here
    return 0; 
}


int tilemove (vector<vector<int>>& board, int n)
{
    //noecho();
    char dir; // = getch();
    cin >> dir;

    emptycell(board, n);

    if (dir == ESC)
    {
        system("clear");
        printf("Final Score : %d \nPress any key to quit.", score);
        cin.get();
        //return endwin();
        return 0;
    }

    switch (dir)
    {
        case UP :   up(board, n);
                    break;
                    
        case DOWN : down(board, n);
                    break;

        case LEFT : left(board, n);
                    break;

        case RIGHT: right(board, n);
                    break;

        default:
                    printboard(board, n);
                    break;
    }

    addrandom(board);
    emptycell(board, n);
    /*
    if (emptypos.empty() && !checkmove(board, n))
    {
        move(6*n, 0);
        printw("\n\nGame Ended, Out of Moves.\nFinal Score : %d \nPress any key to quit.", score);
        getch();
        return endwin();
    }
    */
    printboard(board, n);

    return 0;
}
