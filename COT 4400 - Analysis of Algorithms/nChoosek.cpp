#include <iostream>
int** binomArr;
using namespace std;


int** chompGF;

unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) /*return*/ k = n-k;  //remove the commented section
    if (k == 0) return 1;
    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}

int getChompGS(int n,int r, int c){
    cout << "CHOMP" << endl;
    int row = r-1, col = c-1;
    if(chompGF[row][col] == -1){
        if(r*c < n){
            chompGF[row][col] = 0;
        }else if(r == 0 || c == 0){
            chompGF[row][col] = 0;
        }else if(r*c == n || r*c == n + 1){
            chompGF[row][col] = 1;
        }else if(r*c < n-1){
            chompGF[row][col] = 1;
        }else if(r == 1 && c >= n){
            chompGF[row][col] = 1;
        }else if(c == 1 && r >= n){
            chompGF[row][col] = 1;
        }else{
            chompGF[row][col] = getChompGS(n,r-1,c) + getChompGS(n,r,c-1) + nChoosek(n - r - c + 1 , r - 2);
        }
    }
    return chompGF[row][col];
}


int chomp(int n, int r, int c){
    chompGF = new int*[r];
    for(int i = 0; i < r; i++){
        chompGF[i] = new int[c];
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            chompGF[i][j] = -1;
        }
    }
    return getChompGS(n,r,c);
}




int main(void)
{
    // cout << chomp(8,3,3) << endl;
    // cout << chomp(8,3,4) << endl;
    // cout << chomp(8,3,5) << endl;
    cout << chomp(8,4,5) << endl;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout << chompGF[i][j] << '\t';
        }
        cout << endl;
    }
    // cout << chomp(8,5,5) << endl;
    // cout << chomp(8,6,5) << endl;
    // cout << chomp(8,7,5) << endl;
    // cout << chomp(8,8,5) << endl;
    // cout << chomp(8,8,6) << endl;
    // cout << chomp(8,8,7) << endl;
    // cout << chomp(8,8,8) << endl;

    return 0;
}