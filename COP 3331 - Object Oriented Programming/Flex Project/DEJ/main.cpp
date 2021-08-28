#include "Game.h"
#include "Helper.h"
#include "Player.h"

using namespace std;
void displayTitle();
void rollCredits();


int main(){
    displayTitle();
    Helper::writeConsole("\n\nPlease enter your name:");
    string name = Helper::readConsoleNoSani();
    Player player(name);
    Helper::writeConsole("\n\nChoose and option:\nType 1 for New Game or 2 to Continue: ");
    string choice = Helper::readConsoleNoSani();
    Game game(name,player);
    if(choice == "2"){
        game.load();   
    }
    Helper::writeConsole("Commands:\njournal - opens your journal to give you an idea of what to do next.\ntouch, look, check, open, break, read - allows you to interactive with different objects in the room, some verbs only with with certain objects and some objects work with multiple verbs differently. Objects in brackets can be interacted with.\ngo room_name - moves to into a different room from the list of exits\nquit - exits game and saves data");
    while(game.checkGameRunning()){
        Helper::writeConsole(game.runGame());
    }
    if(!game.checkGameRunning() && player.checkFlags("Beaten_game")){
        rollCredits();
    }
    return 0;
}

void displayTitle(){
    Helper::writeConsole("___________.__              ________   .__                                                                                       \n\\__    ___/|  |__    ____   \\______ \\  |__|  ___________   ______  ______    ____  _____  _______ _____     ____    ____   ____  \n  |    |   |  |  \\ _/ __ \\   |    |  \\ |  | /  ___/\\__  \\  \\____ \\ \\____ \\ _/ __ \\ \\__  \\ \\_  __ \\\\__  \\   /    \\ _/ ___\\_/ __ \\ \n  |    |   |   Y  \\\\  ___/   |    `   \\|  | \\___ \\  / __ \\_|  |_> >|  |_> >\\  ___/  / __ \\_|  | \\/ / __ \\_|   |  \\\\  \\___\\  ___/ \n  |____|   |___|  / \\___  > /_______  /|__|/____  >(____  /|   __/ |   __/  \\___  >(____  /|__|   (____  /|___|  / \\___  >\\___  >\n                \\/      \\/_____  ___________    \\/   .__\\.____|    |__|     ____./      \\/             \\/      \\/      \\/     \\/ \n                   ____ _/ ____\\ \\_   _____/  _____  |__||  |  ___.__.     |    |_____     ____    ____                          \n                  /  _ \\\\   __\\   |    __)_  /     \\ |  ||  | <   |  |     |    |\\__  \\   /    \\ _/ __ \\                         \n                 (  <_> )|  |     |        \\|  Y Y  \\|  ||  |__\\___  | /\\__|    | / __ \\_|   |  \\\\  ___/                         \n                  \\____/ |__|    /_______  /|__|_|  /|__||____// ____| \\________|(____  /|___|  / \\___  >                        \n                                         \\/       \\/           \\/                     \\/      \\/      \\/   \n");
}

void rollCredits(){
    Helper::writeConsole("\n\nSpecial Thanks\n\nLead Developer\n\nDavid Hatcher\n\nPlay Testers\n\nJackie Van Wert\nJamie McCaw\n");
}