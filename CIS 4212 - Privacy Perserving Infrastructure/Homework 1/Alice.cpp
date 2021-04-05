#include <zmq.h>
#include "helper.hpp"

int main (void)
{   
    //Filenames to pull from
    string textFileName = "HW1PlaintextTest.txt";
    string keyFileName = "sharedSecret.txt";
    
    //Getting the shared secret and the message
    string messageToSend = getFileConts(textFileName);
    int messageLength = messageToSend.length();
    string sharedSecret = getFileConts(keyFileName);

    //Plaintext container
    unsigned char Plaintext[messageLength + 1];
    strcpy((char *)Plaintext,messageToSend.c_str());

    //Seed container
    char seed[33];
    strcpy(seed,sharedSecret.c_str());

    //Initializing and settings Key array
    unsigned char key[messageLength + 1] = "";

    //Generating the key of the same length as the plaintext
    generateKey(seed,key,messageLength);

    //Cipher container
    unsigned char Ciphertext[messageLength + 1];
    Ciphertext[messageLength] = '\0';

    //Generating Ciphertext
    xorStrings(key,Plaintext,Ciphertext,messageLength);

    //Generating hash of plaintext
    unsigned char h[33] = "";
    generateHash(Plaintext,h,strlen((char *)Plaintext));

    //Connecting to bob
    void *context = zmq_ctx_new ();
    void *requester = zmq_socket (context, ZMQ_REQ);
    zmq_connect (requester, "tcp://localhost:5555");

    //Sending bob the cipher and hash
    char buffer[messageLength + 1];
    cout << "Sending Ciphertext" << endl;
    zmq_send (requester, Ciphertext, messageLength, 0);
    sleep (1);          //  Do some 'work'
    zmq_recv (requester, buffer, messageLength, 0);
    cout << "Recieved Response" << endl << endl;
    cout << "Sending Hashed Message" << endl;
    zmq_send (requester, h, strlen((char*)h), 0);
    sleep (1);          //  Do some 'work'
    zmq_recv (requester, buffer, messageLength, 0);
    cout << "Recieved Response" << endl;

    //Closing connection to bob
    zmq_close (requester);
    zmq_ctx_destroy (context);
    
    return EXIT_SUCCESS;
}