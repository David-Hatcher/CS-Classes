#include <iostream>
#include <array>
#include <string>
#include <limits>

using namespace std;

const char x_char = 'X';
const char o_char = 'O';
const string x_wins = "XXX";
const string o_wins = "OOO";
const int len = 3;

struct Space{
    int row;
    int column;
    char piece;
    bool isChoiceValid();
};

struct Game{
    array<array<char,len>,len> board{{{' ', ' ',' '},{' ',' ',' '},{' ',' ',' '}}};
    bool gameState;
    array<string,8> getSets();
    Space askChoice();
    bool isGameOver();
    string whoIsWinner();
    void takeTurn(char player);
    bool isSpaceOpen(Space current_space);
    void takeSpace(Space current_space);
    void printBoard();
};


void dispTitle();
int getInt();

int main(){
    dispTitle();
    Game current_game;
    int i = 0;
    current_game.printBoard();
    while(!current_game.isGameOver()){
        char current_player = (i++ % 2 == 0) ? 'X' : 'O';
        current_game.takeTurn(current_player);
        current_game.printBoard();
        if(i == 9){ //game over, must be winner or cats game
            break;
        }
    }
    cout << current_game.whoIsWinner() << endl << endl << "Game Over!";
    return 0;
}

array<string,8> Game::getSets(){
    string set,set_diag_down = "",set_diag_up = "",set_col_1 = "",set_col_2 = "",set_col_3 = "";
    array<string,8> sets;
    int i = 0;
    for(unsigned int r = 0; r < board.size(); ++r){
        set = "";
        for(unsigned int c = 0; c < board[r].size(); ++c){
            if(r == c){
                set_diag_down += board[r][c];
            }
            if(r + c == 2){
                set_diag_up += board[r][c];
            }
            if(c == 0){
                set_col_1 += board[r][c];
            }else if(c == 1){
                set_col_2 += board[r][c];
            }
            else{
                set_col_3 += board[r][c];
            }
            set += board[r][c];
        }
        sets[i++] = set;
    }
    sets[i++] = set_col_1;
    sets[i++] = set_col_2;
    sets[i++] = set_col_3;
    sets[i++] = set_diag_down;
    sets[i++] = set_diag_up;
    return sets;
}

bool Game::isGameOver(){
    array<string,8> sets = getSets();
    for(unsigned int j = 0; j < sets.size(); ++j){
        if(sets[j] ==  x_wins || sets[j] == o_wins){
            return true;
        }
    }
    return false;
}

string Game::whoIsWinner(){
    array<string,8> sets = getSets();
    for(unsigned int j = 0; j < sets.size(); ++j){
        if(sets[j] ==  x_wins){
            return "X Wins!";
        }else if(sets[j] == o_wins){
            return "O Wins!";
        }
    }
    return "Cat's Game!";
}

void Game::takeTurn(char player){
        cout << player << "'s Turn!" << endl << endl;
        Space current_space = askChoice();
        current_space.piece = player;
        while(!isSpaceOpen(current_space)){
            cout << "Space is taken please select again" << endl;
            current_space = askChoice();
            current_space.piece = player;
        }
        takeSpace(current_space);
}


bool Game::isSpaceOpen(Space current_space){
    if(board[current_space.row][current_space.column] == 'X' || board[current_space.row][current_space.column] == 'O'){
        return false;
    }
    return true;
}

void Game::takeSpace(Space current_space){
    board[current_space.row][current_space.column] = current_space.piece;
}

void Game::printBoard(){
    for(unsigned int r = 0; r < board.size(); ++r){
        cout << endl << "+---+---+---+" << endl << "| ";
        for(unsigned int c = 0; c < board[r].size(); ++c){
            cout << board[r][c] << " | ";
        }
    }
    cout << endl << "+---+---+---+" << endl;
}


bool Space::isChoiceValid(){
    if(row > 2 || row < 0 || column > 2 || column < 0){
        return false;
    }
    return true;
}

Space Game::askChoice(){
    Space current_space;
    cout << endl <<"Pick a row (1,2,3): ";
    current_space.row = getInt();
    cout << endl << "Pick a column (1,2,3): ";
    current_space.column = getInt();
    current_space.row--;
    current_space.column--;
    if(current_space.isChoiceValid()){
        return current_space;
    }else{
        cout << "Invalid please enter 1, 2 or 3 for both row and column." << endl;
        return askChoice();
    }

}

void dispTitle(){
    cout << "Welcome to Tic Tac Toe" << endl << endl;
}

int getInt(){
    int value;
    cin >> value;
    if(cin.good()){
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return value;
    }else{
        cout << endl << "Value must be a number, please try again: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        return getInt();
    }
}