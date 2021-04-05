#include <zmq.h>
#include "helper.hpp"

using namespace std;



int main(void){

    //Filenames to pull from
    string textFileName = "HW1PlaintextTest.txt";
    string keyFileName = "sharedSecret.txt";
    string bobH = "Bob_h.txt";
    string bobPlainText = "BobPlaintext.txt";
    
    //Getting length of cipher
    int cipherLength = getFileConts(textFileName).length();
    unsigned char Ciphertext[cipherLength + 1] = "";
    unsigned char h[33] = "";

    //Getting information from Alice
    void *context = zmq_ctx_new ();
    void *responder = zmq_socket (context, ZMQ_REP);
    int rc = zmq_bind (responder, "tcp://*:5555");
    assert (rc == 0);
    char buffer [100] = "";
    zmq_recv (responder, Ciphertext, cipherLength, 0);
    cout << "Received Cipher" << endl;
    cout << "Sending Response\n" << "\n";
    sleep (1);          //  Do some 'work'
    zmq_send (responder, "Got it.", 8, 0);
    zmq_recv (responder, h, 32, 0);
    cout << "Received Hashed Message" << endl;
    cout << "Sending Response\n" << buffer << "\n";
    sleep (1);          //  Do some 'work'
    zmq_send (responder, "Got it.", 8, 0);

    //Getting shared seed
    char seed[33] = "";
    strcpy(seed,getFileConts(keyFileName).c_str());

    //Generating key for xor
    unsigned char key[cipherLength + 1] = "";
    generateKey(seed,key,cipherLength);

    //Xoring the key with the Cipher to generate plaintext
    unsigned char Plaintext[cipherLength + 1] = "";
    xorStrings(Ciphertext,key,Plaintext,cipherLength);

    //Creating hash to plaintext to verify accuracy
    unsigned char hPrime[33] = "";
    generateHash(Plaintext,hPrime,strlen((char*)Plaintext));

    //Test for correctness
    if(strcmp((char *)hPrime,(char *)h) == 0){
        cout << "h == h' found to be true" << endl << "writing h' and Plaintext to files" << endl;
        writeToFile(bobH,hPrime);
        writeToFile(bobPlainText,Plaintext);
    }else{
        cout << "h == h' found to be false" << endl << "not writing files" << endl;
    }

    return EXIT_SUCCESS;
}