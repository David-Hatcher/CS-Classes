#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>
#define  SHMKEY ((key_t) 7890)
typedef struct{
    int value;
} shared_mem;
shared_mem  *counter;

/*----------------------------------------------------------------------This function  increases the value of shared variable  "counter"by one all the way to 50000----------------------------------------------------------------------*/
process1 (){
    int line = 0;
    while (line  < 50000){
        line++;counter->value  = counter->value  + 1;
    }
    printf ("from  process1 counter = %d\n", counter->value);
    exit (0);
}
/*----------------------------------------------------------------------This function  increases the value of shared memory  variable  "counter"by one all the way to 50000----------------------------------------------------------------------*/
process2 (){
    int line = 0;
    while (line  < 50000){
        line++;
        counter->value  = counter->value  + 1;
    }
    printf("from  process2 counter = %d\n", counter->value);
    exit (0);
}
main(){
    key_t key = 123;
     /* shared memory  key */
    int   shmid;
    int   pid1,pid2,pid3;
    int   status;
    char *shmadd;
    shmadd  = (char *) 0;
    if ((shmid  = shmget  (SHMKEY, sizeof(int),  IPC_CREAT | 0666)) < 0){
        perror ("shmget");
        exit (1);
    }
    if ((counter = (shared_mem  *) shmat (shmid,  shmadd, 0)) == (shared_mem  *) -1){
        perror ("shmat");
        exit (0);
    }
    counter->value  = 0;
    fflush  (stdout);
    if ((pid1 = fork()) == 0) process1();
    /*sleep(2); use this statement to reach the correct count*/
    if ((pid1 != 0) && (pid2 = fork()) == 0) process2();
    if ((pid1 != 0) && (pid2 != 0)){
        pid3 = wait(&status);/*  parent waits for one process to end*/
        pid3 = wait(&status);/*  parent waits for the other process to end*/
        printf ("from  parent counter = %d\n",  counter->value);
        printf ("\t\t  End of simulation\n");/* the next set of statements releases the shared memory  */
        if ((shmctl  (shmid,  IPC_RMID, (struct shmid_ds  *) 0)) == -1){
            perror ("shmctl");
            exit (-1);
        }
        exit (0);
    }
}