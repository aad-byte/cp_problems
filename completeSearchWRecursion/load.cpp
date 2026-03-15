#include <iostream>
#include <vector>
#include <set>

using namespace std;

int calculate(int fencex, int fencey, vector<vector<int>> cows){
    int region1 = 0; int region2 = 0; int region3= 0; int region4 = 0;
    for(int i = 0; i < cows.size(); i++){//iterate through each cow and dtermine which of the 4 regions it falls into, as divided by the fences
        //region 1 is the top right, 2 is top left, 3 is bottom left, 4 is bottom right
        int x = cows[i][0]; int y = cows[i][1];

        if(x > fencex && y > fencey){
            region1++;
        }

        if(x < fencex && y > fencey){
            region2++;
        }

        if(x < fencex && y < fencey){
            region3++;
        }

        if(x > fencex && y < fencey){
            region4++;
        }
    }
    
    int ans = max(max(max(region1, region2), region3), region4);
    
    return ans;
}

int main(){
    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);
    int N, B;
    cin >> N >> B;

    vector<vector<int>> cows(N);
    int input;
    
    set<int> xcd, ycd;

    for(int i = 0; i < N; i++){
        cin >> input;
        cows[i].push_back(input);
        xcd.insert(input);
        cin >> input;
        cows[i].push_back(input);
        ycd.insert(input);
    }

    int M = 101;
    int ans;
    for(auto i = xcd.begin(); i != prev(xcd.end()); i++){
        for(auto j = ycd.begin(); j != prev(ycd.end()); j++){
            auto temp = next(i);
            int fencex = (*i + *temp)/2;
            temp = next(j);
            int fencey = (*j + *temp)/2;
            ans = calculate(fencex, fencey, cows);
            M = min(M, ans);
        }
    }

    cout << M;

}