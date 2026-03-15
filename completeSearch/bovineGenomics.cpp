#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    int N, M;
    cin >> N >> M;
    vector<string> spoty;
    vector<string> plain;
    string temp;

    for(int i = 0; i < N; i++){
        cin >> temp;
        spoty.push_back(temp); //each string has M chars
    }

    for(int i = 0; i < N; i++){
        cin >> temp;
        plain.push_back(temp);
    }

    int totalSets = (M*(M-1)*(M-2))/6;

    //for each spoty cow...   
 
        
    //iterate through all possible 3 set indexes
        for(int i = 0; i < M; i++){
            for(int j = i+1; j < M; j++){
                for(int k = j+1; k < M; k++){
    
                    bool exitloop = false; //reset exit loop to false every time we enter new index set
                    for(int m = 0; m < N && !exitloop; m++){ //iterate through all spotty cows for that 3 set index
                        char Genome1 = spoty[m][i]; // set genomes accrodingly
                        char Genome2 = spoty[m][j];
                        char Genome3 = spoty[m][k];

                        for(int h = 0; h < N; h++){
                        char genome1 = plain[h][i]; // set genomes accrodingly
                        char genome2 = plain[h][j];
                        char genome3 = plain[h][k];
                            if(((Genome1 == genome1) && (Genome2 == genome2))&& (Genome3 == genome3)){
                                totalSets--;
                                exitloop = true;
                                break; //if the sequence every encounters a duplicate in the plain cows, it cannot be counted as a set
                                //two loops are broken, since even 1 matching seqeunce for the set amongst plain and spoty, disreagrds the entire set
                                }
                        }

                    }

                    //iterate through all plain cows, checking if they hold the same sequence at each index
                    //as soon as even 1 cow holds the same sequence, break out of current loop, and subtract 1 from total sets
                }   
            }
        }
    

    cout << totalSets;
    }
    

    //cout << "\t with plain #" << m+1 << " 's of indexs " << i << " " << j << " " << k << "\n"; 