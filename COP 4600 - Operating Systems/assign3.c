//David Hatcher
//Sleeps on lines 71, 76, 81, 86, 118, 120, These lines call function which is on line 135 that uses the sleep function, wait functions on 98, 99, 102, 105 & 108
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define SHMKEY ((key_t) 5492)

typedef struct{
    char array[3000];
} shared_mem;
shared_mem *stringValue;


void addCharsToBuffer(char name[], char letter[], int iterations,shared_mem *stringValue);
void waitMe(int time, char value);

int main(int argc, char* argv[]){
    char useSleep = 'N';
    if(argc > 1){
        useSleep = *argv[1];
    }
    key_t key = 123; /*Shared memory key*/
    int shmid;
    char *shmadd;
    int status;
    int waitTime;
    shmadd = (char*) 0;
    printf("Parent Process has been created.\n");
    if ((shmid  = shmget(SHMKEY, sizeof(shared_mem),  IPC_CREAT | 0666)) < 0){
        perror ("shmget");
        exit (1);
    }
    if ((stringValue = (shared_mem  *) shmat(shmid,  shmadd, 0)) == (shared_mem  *) -1){
        perror ("shmat");
        exit (0);
    }
    strcat(stringValue->array,"");
    fflush(stdout);
    printf("Shared memory created was successfully.\n");
    int child = -1, gchild1 = -1, gchild2 = -1, ggchild1 = -1, ggchild2 = -1;
    child = fork();
    if(child == 0){
        gchild1 = fork();
        if(gchild1 == 0){
            ggchild1 = fork();
        }
        if(gchild1 != 0){
            gchild2 = fork();
            if(gchild2 == 0){
                ggchild2 = fork();
            }
        }
    }
    if(child != 0){
        printf("From the Parent process - all processes have been created.\n");
    }
    char letter[1];
    char* name;
    int iterations;
    int ggc2Wait = 8, ggc1Wait = 4, gc1Wait = 2, gc2Wait = 6, cWait = 0;
    /*Setting character value and process name*/
    name = "Parent";
    if(ggchild2 == 0){
        iterations = 300;
        strcat(letter,"z");
        name = "Great-Grandchild2";
        waitMe(ggc2Wait, useSleep);
    }else if(ggchild1 == 0){
        iterations = 700;
        strcat(letter,"y");
        name = "Great-Grandchild1";
        waitMe(ggc1Wait, useSleep);
    }else if(gchild1 == 0){
        iterations = 700;
        strcat(letter,"x");
        name = "Grandchild1";
        waitMe(gc1Wait, useSleep);
    }else if(gchild2 == 0){
        iterations = 300;
        strcat(letter,"w");
        name = "Grandchild2";
        waitMe(gc2Wait, useSleep);
    }else if(child == 0){
        iterations = 1000;
        strcat(letter,"w");
        name = "Child";
    }

    if(child == 0){
        addCharsToBuffer(name,letter,iterations,stringValue);
    }

    if(gchild1 > 0 && gchild2 > 0){
        waitTime = wait(&status);
        waitTime = wait(&status);
    }
    if(ggchild1 > 0){
        waitTime = wait(&status);
    }
    if(ggchild2 > 0){
        waitTime = wait(&status);
    }
    if(child > 0){
        waitTime = wait(&status);
        printf("From Parent process - I am exiting and final buffer size = %d\n",strlen(stringValue->array));
        if ((shmctl  (shmid,  IPC_RMID, (struct shmid_ds  *) 0)) == -1){
            perror ("shmctl");
            exit (-1);
        }
        printf("Shared memory has been released.\n");
        exit(0);
    }
    if(gchild2 == 0){
        waitMe(3, useSleep);
    }else if(gchild1 == 0){
        waitMe(4, useSleep);
    }
    printf("The %s process terminated normally.\n",name);
    return 0;
}

void addCharsToBuffer(char name[], char letter[],int iterations,shared_mem *stringValue){
    int i = 0;
    while(i < iterations){
        strcat(stringValue->array,letter);
        i++;
    }
    printf("From %s process - I just finished and the buffer size = %d\n",name,strlen(stringValue->array));
}

void waitMe(int time, char value){
    if(value == 'Y'){
        sleep(time);
    }
}
