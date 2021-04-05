#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <tomcrypt.h>

using namespace std;

/*read a single line from a file*/
string getFileConts(string fileName){
    string line;
    ifstream file;
    file.open(fileName);
    getline(file,line);
    file.close();
    return line;
}

/*write a single string to a text file*/
void writeToFile(string fileName, unsigned char text[]){
    ofstream file(fileName);
    file << text;
    file.close();
}

/*xors two strings of specified length and places the result in dest*/
void xorStrings(unsigned char first[],unsigned char second[],unsigned char dest[],int length){
    int i;
    for(i = 0; i < (int)strlen((char*)second); i++){
        dest[i] = (first[i] ^ second[i]);
    }
}

/*Generates a key of length provided based on a seed provided and places it in the key char[]*/
void generateKey(char seed[], unsigned char key[], int messageLength){
    unsigned char buf[33];
    unsigned long len;
    len = sizeof(buf);
    /* register algos */
    register_hash(&sha256_desc);
    register_cipher(&aes_desc);
    int hashCount = messageLength / 32;
    for(int i = 1; i <= hashCount; i++){
        string appendedSeed = seed + to_string(i);
        hash_memory(find_hash("sha256"),(unsigned char*)appendedSeed.c_str(),appendedSeed.length(),buf,&len);
        //Setting final value in buf to null char to signify end of string
        buf[32] = '\0';
        //Handling issues with a hash having a null char inside and seeing the generated value as not 32 length
        //Basically skip this hash and go to the next
        if(strlen((char*)buf) != 32){
            hashCount++;
            continue;
        }
        strcat((char *)key,(char *)buf);
    }
}

//Generate a single hash based on a seed and length, then place it in the destination
void generateHash(unsigned char seed[],unsigned char dest[],int seedLength){
    unsigned char buf[33];
    unsigned long len;
    len = sizeof(buf);
    /* register algos */
    register_hash(&sha256_desc);
    register_cipher(&aes_desc);
    hash_memory(find_hash("sha256"),seed,seedLength,buf,&len);
    //Setting final value in buf to null char to signify end of string
    buf[32] = '\0';
    strcpy((char *)dest,(char *)buf);
}