#include <fstream>
#include "core/global.h"
#include <cstdlib>
#include <ctime>

using namespace std;

void boardinit(int n)
{
    ofstream fout;
    fout.open("./inputfile", ios::trunc);

    srand((unsigned) time(0));


    int x1 = rand() % n;
    int x2 = rand() % n;
    int y1 = rand() % n;
    int y2 = rand() % n;

    while (x1==x2 && y1==y2)
    {
        y1 = rand() % n;
        x1 = rand() % n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i == x1 && j == y1) || (i == x2 && j == y2))
                fout << 2 << " ";
            else
                fout << 0 << " ";
        }
        
        fout << endl;
    }
}

void input(vector<vector<int>>& board, int n)
{
    ifstream fin;
    fin.open("./inputfile", ios::in);

    for (auto& row : board)
    {
        for (int& i : row)
            fin >> i;
    }

    emptycell(board, n);

    fin.close();
}