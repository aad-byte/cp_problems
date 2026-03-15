#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    //key insight I was missing =>  the most contigious array will always be the most optimal of the two sets to chose
    int N, K;
    cin >> N >> K;

    vector<int> data(N);

    for(auto &i: data){
        cin >> i;
    }

    sort(data.begin(), data.end());

    int maxPrev;
    int indexL = 0;
    int indexR = 0;
    int maxi = 0; 
    int preR = 0; int preL = 0; 
    bool status = true; 

    //cout << "\ntest1";

    while(indexL < N){
    // what ahppens wehn two contigious arrays of the same max length exist? 
        //cout << "\ntest1";
        status = true; 
        while(status){
            if(indexR < N){
                //cout << "\ntest1";
                if(data[indexR] - data[indexL] <= K){
                    maxPrev = maxi;
                    maxi = max(indexR - indexL + 1, maxi);

                    if(maxi > maxPrev){
                        //cout << "\ntest1";
                        preR = indexR;
                        preL = indexL;
                    }

                    indexR++;
                }else{
                    status = false; 
                    //cout << "\ntest1";
                }
            }else{
                status = false; 
            }
        }

        indexL ++; 
    }

   
    indexR = 0; 
    indexL = 0;
    maxi = 0;
    maxPrev = 0;

    //cout << "\ntest1";
    int overlap;
    while(indexL < N){
        status = true; 
        while(status){
            //cout << "\ntest1";
            if(indexR < N){
                //cout << "\ntest1";
                if(data[indexR] - data[indexL] <= K){
                    overlap = 0;
                    if(max(indexL, preL) < min(indexR, preR)){
                        overlap =  min(indexR, preR) - max(indexL, preL) +1;
                        //cout << "\n\nflag1";
                    }else if((indexL == preL && indexR == preR)){
                        overlap = indexR - indexL + 1;
                        //cout << "\n\nflag2";
                    }else{
                        //cout << "\n\nflag3";

                    }

                    //cout << "\n\toverlap: " << overlap;

                    maxPrev = maxi; 
                    maxi = max(indexR - indexL + 1 - overlap + (preR - preL + 1), maxi);

                    //cout << "\n\n\n";
                    //cout << "\nMax prev : " << maxPrev;
                    //cout << "\nMaxi " << maxi;
                    //cout << "\n index R " << indexR;
                    //cout << "\n index L " << indexL;

                    indexR++;
                 
                }else{
                    status = false; 
                    ////cout << "\ntest1";
                }
            }else{
                status = false; 
                ////cout << "\ntest1";
            }
        }

        ////cout << "\ntest1";

        indexL ++; 
    }

    ////cout << "\ntest1";
    //cout << "\nindex L: " << indexL;
    //cout << "\nindex R: " << indexR;
    //cout << "\nmaxi: " << maxi;
    //cout << "\npre L: " << preL;
    //cout << "\npre R: " << preR;

    cout << maxi;
}
