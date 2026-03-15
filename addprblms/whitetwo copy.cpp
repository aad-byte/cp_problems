#include <iostream>
#include <vector>
using namespace std;

long long overlap(long long a1, long long a2, long long a3, long long a4, long long b1, long long b2, long long b3, long long b4){
    long long w1, w2, h1, h2;

    if(b3 <= a1 || a3 <= b1){
        return 0;
    }else if(b4 <= a2 || a4 <= b2){
        return 0;
    }else{
        if(b1 <= a3 && b1 >= a1){
            w1 = b1;
        }else{
            w1 = a1;
        }

        if(b3 <= a3 && b3 >= a1){
            w2 = b3;
        }else{
            w2 = a3;
        }

        if(b2 <= a4 && b2 >= a2){
            h1 = b2;
        }else{
            h1 = a2;
        }

        if(b4 <= a4 && b4 >= a2){
            h2 = b4;
        }else{
            h2 = a4;
        }
        long long area = (h2-h1) * (w2-w1);
        //cout << "\narea: " << area << "\n";
        return area;
    }

}
    vector<long long> coordinates(long long a1, long long a2, long long a3, long long a4, long long b1, long long b2, long long b3, long long b4){
        vector<long long> blah;
        long long w1, w2, h1, h2;
    
        if(b3 <= a1 || a3 <= b1){
            blah.push_back(-1);
        }else if(b4 <= a2 || a4 <= b2){
            blah.push_back(-1);
        }else{
            if(b1 <= a3 && b1 >= a1){
                w1 = b1;
            }else{
                w1 = a1;
            }
    
            if(b3 <= a3 && b3 >= a1){
                w2 = b3;
            }else{
                w2 = a3;
            }
    
            if(b2 <= a4 && b2 >= a2){
                h1 = b2;
            }else{
                h1 = a2;
            }
    
            if(b4 <= a4 && b4 >= a2){
                h2 = b4;
            }else{
                h2 = a4;
            }
            
            blah.push_back(w1);
            blah.push_back(h1);
            blah.push_back(w2);
            blah.push_back(h2);
        }

        return blah;

}

int main(){
    //use PIE, first calculate overlap indisually bettween each blak sheet and white sheet
    //next subtract overlap from two black sheets

    long long w1, w2, w3, w4;
    long long b1, b2, b3, b4;
    long long B1, B2, B3, B4;

    cin >> w1 >> w2 >> w3 >> w4;
    cin >> b1 >> b2 >> b3 >> b4;
    cin >> B1 >> B2 >> B3 >> B4;

    long long whitesheet = (w4-w2)*(w3-w1);

    long long black1 = overlap(w1, w2, w3, w4, b1, b2, b3, b4);
    //cout << "\nblack1 : " << black1;
    long long black2 = overlap(w1, w2, w3, w4, B1, B2, B3, B4);
    //cout << "\nblack2 : " << black2;

    long long extra = overlap(b1, b2, b3, b4, B1, B2, B3, B4);
    //cout << "\nextra : " << extra;

    vector<long long> info;
    long long totalextra;
    totalextra = 0;

    if(extra != 0){
       info = coordinates(b1, b2, b3, b4, B1, B2, B3, B4);
       totalextra = overlap(info[0], info[1], info[2], info[3], w1, w2, w3, w4);
    }

   // cout << "\n totalextra: " << totalextra << "\n";


    whitesheet -= (black1 + black2);
    whitesheet +=  totalextra;

   // cout << "\n white sheet: " << whitesheet;

    if(whitesheet >0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}