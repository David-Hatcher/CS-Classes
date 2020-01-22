#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

int randomGen(int min, int range);
/*
 *This program will ask a users name then random generate 2 scores 
 *between 0 and 100 and then find the average of both scores, 
 *display them on the console. Then ask the user for feedback 
 *relay that feed back to them with heartfelt sympathies followed 
 *by a proclaimation of its best efforts. After all, it is only a computer.
 */
int main(){
    //Program variables definition
    string midterm_tell = "Midterm Grade:\t\t";
    string final_tell = "Final Exam Grade:\t";
    string average_tell = "Average:\t\t";
    string first_name;
    string user_feedback;
    string system_response = "Maybe I didn't do so good... What do you think?\n";
    string greeting = "Hi! Enter your first name: ";
    string terminal_output;
    int grade_max = 100;
    int grade_min = 0;
    //End program variables definition

    //Pass greeting string and ask for first name
    cout << greeting;
    cin >> first_name;
    cout << "Welcome, " << first_name << ". Were these your grades last semester?" << endl << endl;

    //Create random numbers for grades
    srand(time(0)); //define rand seed outside of method to allow for different numbers
    int midterm_grade = randomGen(grade_min,grade_max);
    int final_grade = randomGen(grade_min,grade_max);
    int average_grade = (midterm_grade + final_grade)/2;

    //output grades
    cout << midterm_tell << midterm_grade << endl;
    cout << final_tell << final_grade << endl;
    cout << average_tell << average_grade << endl;

    //output system response
    cout << system_response;
    cin.ignore(1000,'\n'); //dump newline character from input buffer
    
    //Get and assign user feedback to terminal output string
    getline(cin,user_feedback);
    terminal_output += first_name + ", I understand. You feel \"" + user_feedback + "\"; I assure you I tried my best!";

    //give user feedback with static response
    cout << terminal_output << endl;

    return 0;

}


/*
 * randomGen will randomly genarate a number between min and max parameters
 */
int randomGen(int min, int max){
    int range = max - min + 1;
    return (rand() % range) + min;
}
