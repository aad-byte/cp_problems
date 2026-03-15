#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//iterate through all 9! possibilites, once a possible soloution for a color is found break the loop for that color 
int main(){
    freopen("art.in", "r", stdin);
    freopen("art.out", "w", stdout);    
    //aslong as a color doesnt overlap any other colors, (this includes a color not being present), then it can be a first color 
    int input, N;
    cin >> N;
    vector<vector<int>> canvas(N);

    vector<vector<int>> data(9);
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 2; j++){
            data[i].push_back(-2); //max x, max y
            data[i].push_back(N); // min x min y
        }
    }

    int blah;

    for(int i = 0; i < N; i ++){
        cin >> blah;
        for(int j = 0; j < N; j++){
            input = blah / pow(10, (N-(j+1)));
            blah -= input * pow(10, (N-(j+1)));
            canvas[i].push_back(input);
            if(input != 0){
                //max x coordinate
                data[input-1][0] = max(data[input-1][0], j);
                //min x coordinate
                data[input-1][1] = min(data[input-1][1], j);
                //max y coordinate
                data[input-1][2] = max(data[input-1][2], i);
                //min y coordinate
                data[input-1][3] = min(data[input-1][3], i);
            }
        }
    }

    /*cout << "\n data:\n";

    for(int i = 0; i < 9; i++){
        cout << " \ncolour " << (i+1) << "\n";
        cout << "\n max x: " << data[i][0] << "\n";
        cout << "\n min x: " << data[i][1] << "\n";
        cout << "\n max y: " << data[i][2] << "\n";
        cout << "\n min y: " << data[i][3] << "\n";
    }*/

    //store min and max of each color somehow 

    //if a colour's maximum minium dont overlap with the maxium minim coordinate range of another color then it doenst overlap that colour, just need to check each colour with all the other colors and that would work
    //for each color check if 

    //checking if colour i could be first

    //iterate through all colours other than i, j


    bool poss = true;
    int total = 0;
    for(int i = 0; i < 9; i++){
        poss = true;
        for(int j =0; j < 9; j++){
            if(j !=i){
                //iterate through possible range for rectangle for j, check if i every interfres with this range
                if(data[j][0] != -2){
                    for(int m = data[j][1]; m <= data[j][0]; m++){
                        for(int n = data[j][3]; n < data[j][2]; n++){
                            if(canvas[n][m] == (i+1)){
                                poss = false;
                            }
                        }
                    }
                }
            }
        }
        if(poss == true){
            total++;
        }
        if(data[i][0] == -2){
            total--;
        }
    }

    cout <<total;
}