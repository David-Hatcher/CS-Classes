#include <fstream>
#include <iostream>

unsigned long long int*** chompArr;

using namespace std;
unsigned long long int chomp(int n, int r, int c);
unsigned long long int chompIter(int, int, int);
int main()
{
    ifstream input("input.txt");
    if (!input){
        cout << "Count not open file 'input.txt'" << endl;
        return 1;
    }

    ofstream output("output.txt");
    if (!output){
        cout << "Count not write file 'output.txt'" << endl;
        return 1;
    }

    int count = 0;
    input >> count;

    for (int i = 0; i < count; i++)
    {
        int n, r, c;
        input >> n >> r >> c;
        output << chomp(n, r, c) << endl;
    }
    return 0;
}

unsigned long long int chomp(int n, int r, int c){
    /*allocating memory for the iterative 3D array*/
    chompArr = new unsigned long long int**[n+1];
    for(int i = 0; i <= n; i++){
        chompArr[i] = new unsigned long long int*[r+1];
        for(int j = 0; j <= r; j++){
            chompArr[i][j] = new unsigned long long int[c+1];
        }
    }
    /*Initializing values for the iterative 3D array*/
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= r; j++){
            for(int k = 0; k <= c; k++){
                /*If i = 0, the value should be initialized at 1, this is used for
                  Finding the subproblem when you're looking at the i-j-k+1 index for i
                  as this can only be accessed when finding the game states for the
                  "current size" and if there are no remaining pieces there is a single
                  valid configuration*/
                if(i == 0){
                    chompArr[i][j][k] = 1;
                }else{
                    chompArr[i][j][k] = 0;
                }
            }
        }
    }
    /*Getting the value for this input*/
    unsigned long long int result = chompIter(n,r,c);
    /*Freeing up heap memory*/
    for (int i = 0; i <= n; i++){
		for (int j = 0; j <= r; j++){
            delete[] chompArr[i][j];
        }
		delete[] chompArr[i];
	}
	delete[] chompArr;
    return result;
}

unsigned long long int chompIter(int n, int r, int c) {
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= r; j++){
            for(int k = 1; k <= c; k++){
                /*If i is 1 there can only be a single configuration where the one piece is the poison piece
                  If i = j*k there can also only be a single configuration as there are as many pieces as there
                  are spaces to put them*/
                if(i == 1 || i == j*k){
                    chompArr[i][j][k] = 1;
                }
                /*If j*k < i there are not enough spaces for the number of pieces therefore there are no possible
                  configurations*/
                else if(j*k < i){
                    chompArr[i][j][k] = 0;
                }
                /*If i - j - k + 1 < 0 that means that we cannot possibly fill every single row and column with at
                  least one piece, thus there are no unique configurations this specific board state with rows = j,
                  columns = k, and pieces = i*/
                else if(i - j - k + 1 < 0){
                    chompArr[i][j][k] = chompArr[i][j-1][k] + chompArr[i][j][k-1] - chompArr[i][j-1][k-1];
                }
                /*Otherwise, the total number of game states for i pieces, j rows, and k columns, is equal to the
                  number of gamestates at i,j-1,k, same pieces and columns but 1 less row, plus the number of game
                  states at i,j,k-1, same pieces and rows but 1 less column, minus the intersection of the previous
                  two factors, which is i,j-1,k-1, plus the total number of game states at the current size. The total
                  number of game states at the current size is where you use ALL the rows and columns, so you start by
                  "putting" one piece in each of them in the only configuration that is valid, the top row filled and
                  the first column filled. This leaves you with i-j-k+1 pieces left. At this point the total number of
                  game states is just game states for a "chocolate bar" that is one row and column smaller, but with
                  the remaining pieces, thus you can get that from pieces = i-j-k+1, rows = j-1, and columns = k-1*/
                else{
                    chompArr[i][j][k] = chompArr[i][j-1][k] + chompArr[i][j][k-1] - chompArr[i][j-1][k-1] + chompArr[i-j-k + 1][j-1][k-1];
                }
            }
        }
    }
    return chompArr[n][r][c];
}
