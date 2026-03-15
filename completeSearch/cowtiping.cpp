#include<iostream>
#include<vector>
using namespace std;

int main(){
    freopen("cowtip.in", "r", stdin);
    freopen("cowtip.out", "w", stdout);
    int n;
    cin >> n;
    vector<vector<int>> grid;

    string input;
    //cout << "\nflag1";
    for(int i = 0; i < n; i++){
        vector<int> temp;
        cin >> input;
        //cout << "\nflag1a";
        for(int j = 0; j < n; j++){
            //cout << "\nflag1b";
            int number = input[j] - 48;
            temp.push_back(number);
        }
        //cout << "\nflag1c";
        grid.push_back(temp);
        //cout << "\nflag2";
    }

    /*cout << "Grid:\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }*/

    int flips = 0;
    for(int i = n-1; i >=0; i--){
        //cout << "\nflag3";
        for(int j = n-1; j >= 0; j--){
            //cout << "\nflag4";
            if(grid[i][j] ==1){
                //cout << "flag5";
                flips++;
                for(int h = i; h >= 0; h--){
                    //cout << "\nflag6";
                    for(int g = j; g >= 0; g--){
                        //cout << "\nflag7";
                        grid[h][g] = (grid[h][g] +1 ) %2;
                    }
                }
            }
        }
    }

    cout << flips;
}