#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    freopen("herding.in", "r", stdin);
    freopen("herding.out", "w", stdout);
    int cow1, cow2, cow3;
    int mini, maxi;
    
    cin >> cow1 >> cow2 >> cow3;
    //determine minimum
    int dif1 = abs(cow1-cow2);
    int dif2 = abs(cow1-cow3);
    int dif3 = abs(cow2-cow3);

    vector<int> blah(3);
    blah[0] = dif1; blah[1] = dif2; blah[2] = dif3;
    sort(blah.begin(), blah.end());

    if(blah[0] == 1){
        mini = blah[1];
    }else{
        mini = blah[0];
    }

    if(mini == 1){
        mini = 0;
    }else if(mini == 2){
        mini = 1;
    }else{
        mini = 2;
    }
    
    //caluclate second maximum difference

    maxi = max(blah[0], blah[1]) -1;

    cout << mini << "\n" << maxi;
}