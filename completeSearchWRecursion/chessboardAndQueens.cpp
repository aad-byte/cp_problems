#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int queens(int x, int y, vector<vector<char>> board){ //given an index, determine how many indexs are compatible with it? 
    //some base case, like when row is greater than 7
    if(x == 7){
        return 1; //add this permuation to the sum of total 
    }


    //mark spots whihc lie in the queens path as reserved 

    //update the column to be reserved
    for(int i =  0; i < 8; i++){
        board[x][i] = '*';
    }

    //update row to be reserved
    for(int i =  0; i < 8; i++){
        board[i][y] = '*';
    }

    //positve diagnol (buggy)
    if(x+y > 7){
        for(int i = 7; i >= (x+y) -7; i++){
            board[i][x+y - i] = '*';
        }
    }
    else{
        for(int i = 0; i <= x+y; i++){
            board[i][x+y-i] = '*';
        }
    }
    

    //negative diagnoal
    if(x - y > 0){
        for(int i = x - y; i <= 7; i++){
            board[i][i-(x-y)] = '*';
        }
    }else{
        for(int i = 0; i <= 7-(y-x); i++){
            board[i][(y-x) + i] = '*';
        }
    }

    cout << "\n";
    cout << "\nboard after eliminating (" << x << "," << y << ")...\n \n";

    //iterate through free spots in the next row
    //GO BACK AND MAKE SURE BASE CASE DOSE NOT CONFLICT WITH THIS GOING OUT OF BOUNDS
    
    cout<< "here";
    cout<< " gone";
    bool avaliable = false;


    //check to see if there are any free spots in the next row (if not then return 0, ending prematurely)
    for(int i = 0; i < 8; i++){
        if(board[x+1][i] == '.'){
            avaliable = true;
        }
    }

    int total = 0;
    if(avaliable == true){
        for(int i = 0; i < 8; i++){
            if(board[x+1][i] == '.'){
                total += queens(x+1, i, board);
            }
        }
    }
    else{
        cout << "the function returned 0 cause this permutation is not possible";
        return 0; // end prematurely 
    }
    return total;

}   

int main(){
    vector<vector<char>> board;

    board.resize(8);

    for(int i = 0; i < 8; i++){
        board[i].resize(8);
    }

    //store board's inputs
    for(int i = 0; i < 8; i ++){
        for(int j = 0; j < 8; j++){
            cin >> board[i][j];
        }
    }
    int total = 0;
    cout << "\n";

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << board[i][j];
        }
        cout << "\n";
    }

    for(int i = 0; i < 8; i++){
        if(board[0][i] == '.'){
            total += queens(0, i, board);
        }
    }
}