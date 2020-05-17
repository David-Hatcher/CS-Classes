#include "Office.h"

Office::Office(std::string file_path, Player& player) : Room(file_path){
    readDescriptions();
    setDescription(player);
    Interactive mirror("Mirror","Mirror");
    addInteractive("mirror",mirror);
}
void Office::setDescription(Player& player){
    updateDescription(player);
}
void Office::addInteractive(std::string name,Interactive interactive){
    this->interactives.insert(std::pair<std::string,Interactive>(name,interactive));
}
std::string Office::interactWith(std::string action,std::string name,Player& player){
        auto i = this->interactives.begin();
        for(; i != this->interactives.end(); ++i){
            if((*i).first == name){
                break;
            }
        }
        if(i == this->interactives.end()){ return "You can't do anything with that item.";}
        if(action == "break"){
            return breakMirror(player);            
        }else if(action == "touch"){
            return touchMirror(player);
        }else if(action == "look"){
            return lookMirror(player);
        }
        return "Huh?";
}
void Office::readDescriptions(){
    this->mirror_broken_desc = Game::readFile("Rooms/" + this->file_path + "/" + this->file_path + "mirrorbrokendesc.txt");
    this->mirror_not_broken_desc = Game::readFile("Rooms/" + this->file_path + "/" + this->file_path + "mirrornotbrokendesc.txt");

}
std::string Office::breakMirror(Player& player){
    Item hammer = Game::buildItem("Hammer");
    if(player.checkFlags("Mirror_broken")){
        return "The mirror is already broken.";
    }else if(player.checkInventory(hammer) && player.checkFlags("Has_talked_to_emily") && player.checkFlags("Has_released_emily")){
        player.setFlag("Mirror_broken",true);
        return "As you swing the hammer the mirror shatters into hundreds of pieces and you hear a screech from the front of the house.";
    }else if(!player.checkInventory(hammer)){
        return "You don't have an item capable of that.";
    }else if(!player.checkFlags("Has_talked_to_emily")){
        return "Why would you break the mirror?";
    }else if(!player.checkFlags("Has_released_emily")){
        return "You might want to release Emily from the mirror first!";
    }else{
        return "Huh?";
    }
}
std::string Office::touchMirror(Player& player){
    Item mirror_key = Game::buildItem("Mirror Key");
    if(player.checkFlags("Mirror_broken")){
        return "The mirror is broken";
    }else if(!player.checkInventory(mirror_key)){
        return "You touch the mirror, but nothing happens. Maybe you should find the mirror key.";
    }else{
        player.setFlag("Has_released_emily",true);
        return "As you touch the mirror the key momentarily feels warm. Suddenly Emily steps out of the mirror and into the room next to you, \"Let\'s get out of this house as soon as possible!\" she says to you.";
    }

}
std::string Office::lookMirror(Player& player){
    if(player.checkFlags("Mirror_broken")){
        return "You see a the frame of a shattered mirror hanging on the wall, beneath shards of reflective glass cover the floor";
    }else if(player.checkFlags("Has_released_emily")){
        return "In the clouded mirror you see the reflection of the room you are standing in, with one thing missing... you.";
    }else if(player.checkFlags("Has_talked_to_emily")){  
        return "You seem emily in the mirror talking to you, \"Please, you've got to help me get out of here, go to the basement and get the key, I think that's where the beast took it. If it's too dark to see down there, CHECK the kitchen drawers for a Flash Light.";
    }else{
        player.setFlag("Has_talked_to_emily",true);
        return "As you look into the clouded mirror, you see a perfect reflection of Emily's office, the only thing missing from the reflection is you... After a moment of staring at the mirror you suddenly see a young woman walk across the room behind were you would be. You look behind you but see nothing, as you look back at the mirror you seem the young woman walk closer towards you. She get within a foot of the mirror and says \"Hello, my name is Emily. You've got to help me, I've been stuck inside this thing for what feels like ever, When I hung it up there was a key on the back of it, once I touched the mirror while holding that key I was transported inside and the key was taken by some sort of beast. He ran off down to the basement which can be accessed from my office. There is a book on the shelf that can be moved to open the secret door, you should CHECK it out. If it's too dark down there you should CHECK the drawers in the kitchen to get the Flash Light.\"";
    }
}
void Office::updateDescription(Player& player){
    this->description = player.checkFlags("Mirror_broken") ? mirror_broken_desc : mirror_not_broken_desc;
}
