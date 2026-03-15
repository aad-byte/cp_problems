#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int queens(int row, int position, vector<int> queen, vector<vector<char>> board, set<int> remain)
{
    if (board[row][position] == '*')
    {
        return 0; // if the square is reserved, prematurely return 0 for the permutation because then this permutation is not possible
    }

    queen[row] = position; // determine a queens placement (column number) in row (build the permuation)

    set<int> nremain = remain;
    nremain.erase(position); // remove occupied column from avalible spots

    if (row == 7)
    { // once a permuation is compelete, check if it satisfys landing on unqie diagnoals

        set<int> neg;
        for (int i = 0; i < 8; i++)
        {
            neg.insert(i - queen[i]);
        }

        set<int> pos;
        for (int i = 0; i < 8; i++)
        {
            pos.insert(i + queen[i]); // add x and y coordinates (each pos diagnoal has a unique sum)
        }
        bool posd = false;
        if (pos.size() == 8)
        { // this means queens lie on unique postive diagnoals
            posd = true;
        }

        bool negd = false;
        if (neg.size() == 8)
        { // this means queens lie on unique postive diagnoals
            negd = true;
        }

        if (posd && negd)
        { // if queen lies on both unqie positive and negative diagenal, then count permuataion, esle dont
            return 1;
        }
        else
        {
            return 0;
        }
    }

    //if row is NOT 7
    // dont call on all, only on remaining columns i
    int total = 0;
    for (int i : nremain)
    {
        total += queens(row + 1, i, queen, board, nremain);
    }

    return total;
}

int main()
{
    vector<vector<char>> board;

    board.resize(8);
    for (int i = 0; i < 8; i++)
    {
        board[i].resize(8);
        for (int j = 0; j < 8; j++)
        {
            cin >> board[i][j];
        }
    }

    vector<int> queen;
    queen.resize(8);

    set<int> remain = {0, 1, 2, 3, 4, 5, 6, 7};
    int total = 0;

    for (int i = 0; i < 8; i++)
    {
        total += queens(0, i, queen, board, remain);
    }

    cout << total;
}