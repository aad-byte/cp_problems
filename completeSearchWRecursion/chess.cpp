#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> queens = {0, 1, 2, 3, 4, 5, 6, 7}; // column positions
    vector<int> diagonal_up(8, -1);
    vector<int> diagonal_down(8, -1);
    vector<vector<bool>> board(8, vector<bool>(8, false));
    char x;
    int d1, d2;
    int ans = 0;
    bool works; 
    
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            cin >> x;
            if (x == '*'){
                board[i][j] = true;
            }
        }
    }

    // cout << "did we reach here?" << endl;
    do {
        // check if combination works + no diagonal
        works = true;
        diagonal_up = vector<int>(8, -10);
        diagonal_down = vector<int>(8, -10);
        for (int i = 0; i < 8; i++){
            if (board[i][queens[i]]){
                works = false;
                break;
            }
            d1 = i + queens[i];
            d2 = i - queens[i];
            for (int k = 0; k < 8; k++){
                if (diagonal_up[k] == d1 || diagonal_down[k] == d2){
                    works = false;
                }
            }
            diagonal_up[i] = d1;
            diagonal_down[i] = d2;
        }

        if (works){
            ans++;
        }

        
    } while (next_permutation(queens.begin(), queens.end()));

    cout << ans << endl;

}