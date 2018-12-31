#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

#define NUM_THREADS 10


/**
 * Can use the following struct for
 * the nanosleep function.
 * the first value is sleep time in seconds
 * the second vaue is sleep time in nanoseconds.
 *
 * struct timespec ts = {2, 0 };
 *
 * you can call nano sleep as nanosleep(&ts, NULL);
*/

//create global variable to change in threads
int globalCounter = 0;
//initialize mutex
pthread_mutex_t lock;

struct timespec ts = {2, 0};

void *startRoutine(void *threadID){
     //store threadID into tid
     nanosleep(&ts, NULL);
     int tid = (int) threadID;
     //lock thread
     pthread_mutex_lock(&lock);
     fprintf(stderr, "hello I'm thread #%d\n", tid);
     //store the global variable into a local thread variable
     nanosleep(&ts, NULL);
     //pthread_mutex_lock(&lock);
     int localVariable = globalCounter;
     fprintf(stderr, "local thread variable: %d, thread id: %d\n", localVariable, tid);
     //increment the local thread varible by 10
     nanosleep(&ts, NULL);
     localVariable += 10;
     fprintf(stderr, "local thread variable: %d, thread id: %d\n", localVariable, tid);
     //copy new local thread value back into global variable
     nanosleep(&ts, NULL);
     globalCounter = localVariable;
     //unlock thread
     pthread_mutex_unlock(&lock);
     pthread_exit(NULL);
}

int main() {
     //initialize threads
     pthread_t threads [NUM_THREADS];
     int checkForThreadError = 0;

     //initialize mutex
     if(pthread_mutex_init(&lock, NULL) == -1){
          perror("*** Failed to initialize mutex");
     }

     //create all  threads
     for(long t = 1; t <= NUM_THREADS; t++){
          checkForThreadError = pthread_create(threads, NULL, startRoutine, (void *) t);
          if(checkForThreadError != 0){
               perror("*** Failed to create Thread:\n");
          }
     }

     //wait for all threads to complete
     for (long t = 0; t < NUM_THREADS; t++){
          pthread_join(threads[t], NULL);
     }

     printf("globalCounter: %d\n", globalCounter);
     return(0);
}
