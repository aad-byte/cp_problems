#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int n;
    int q;
    cin >> n >> q;

    //

    vector<vector<int>> data;
    vector<int> ans;
    vector<int> temp;
    string input;
    for(int i = 0; i < n; i++){
        cin >> input;
        temp.clear();

        for(int j = 0; j < n; j++){
            if(input[j] == '.'){
                temp.push_back(0);
            }else if(input[j] == '*'){
                temp.push_back(1);
            }

            if(j != 0){
                temp[j] += temp[j-1]; //prefix for the rows 
            }
        }

        data.push_back(temp);
        
    }

    //iterate through the columns and prefix them tooo
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j!= 0 ){
                data[j][i] += data[j-1][i];
            }
        }
    }

    //check that values are being stored correctly 
    /*for(int i = 0; i < n; i ++){
        for(int j =0 ; j < n; j++){
            cout<< data[i][j] << " ";
        }
        cout << "\n";    
    }*/

    int y1, x1, y2, x2;
    int start;

    bool one;
    bool two;
    for(int i = 0; i < q; i++){
        //cout << "\n\n\t\tcase " << i << "\n";
        one = false;
        two = false;

        cin >> y1 >> x1 >> y2 >> x2;
        start = data[y2-1][x2-1];

        //cout << "\n start " << start << "\n";

        if(y1 - 2 >=0){
            start -= data[y1 - 2][x2-1];
            one = true;

            //cout << "\n y1 - 2 is equal to " << (y1-2) << "\n";

            //cout << "\n one " << data[x2-1][y1 - 2] << "\n";
        }

        if(x1 - 2 >=0){
            start -= data[y2-1][x1 - 2];
            two = true;

            //cout << "\n two " << data[x1 - 2][y2-1] << "\n";
        }

        //if there is a region of overlap
        if(one && two){
            start += data[y1-2][x1 - 2];

            //cout << "\n" << "flag1" << "\n";
        }
    
        ans.push_back(start);


    }

    for(int i = 0; i < q; i++){
        cout << ans[i] << "\n";
    }


}