//©Amy SMajstrla
//SPC ID 538337
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream> //for files
#include <string> // for getline
#include <set>
using namespace std;
// opens a specified text file, then displays a list of all the unique words found in the file
//print the total of unique words in the file
//sort each word as an element of a set
//p.674 for files and p.1081 for sets
//function prototypes
bool openFileIn(fstream &, string);
set<string> buildSet(fstream&);
void showContents(set<string>);
int main() {
	fstream myFile;
	//check if file was opened
	if (openFileIn(myFile, "forChap12.txt")) {
        set<string> word_set = buildSet(myFile);
        showContents(word_set);
		//close the file
		myFile.close();			
	}
	else {
		cout << "Error: cannot open file!!\n";
	}
	return 0;
}
bool openFileIn(fstream &file, string name) {
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}
void showContents(set<string> words){
    int count = 0;
    for(auto i = words.begin(); i != words.end(); ++i){
        cout << (*i) << ' ';
        count++;
    }
    cout << endl << "Total Words = " << count;
}

set<string> buildSet(fstream& file){
    set<string> word_set;
    string line;
    while(getline(file,line)){
        line.erase(remove(line.begin(), line.end(), '"'),line.end());
        line.erase(remove(line.begin(), line.end(), '.'),line.end());
        line.erase(remove(line.begin(), line.end(), ','),line.end());
        stringstream current_line(line);
        string current_word;
        while(current_line >> current_word){
            if(current_word != ""){
                word_set.insert(current_word);
            }
        }
    }
    return word_set;
}