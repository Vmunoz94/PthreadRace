Name  :   Victor Muñoz
Date  :   4/5/2018
Class :   CSC 415-02

Compile Instructions:
     In order to compile the program, first you must download the repository
from GitHub using the "clone or download" link provided by the website.
Once downloaded, go into the csc415-p5-Vmunoz94 folder and compile the pthread_race.c program by using
          gcc pthread_race.c

Run Instructions:
     Once compiled, run the program by using
          ./a.out

Project Description:
     For this assignment we had to expand on project#4 in order to eliminate
all possible race conditions. These race conditions occurred whenever multiple
threads tried to access or modify a variable. To eliminate these racing conditions,
we had to implement a mutex to lock and unlock all possible racing conditions.
The first thread locks a region of code, it will be the only thread allowed
to execute that code until it unlocks that region. Once unlocked, another thread
can come in and do the exact same.

Sample output using mutex:
          hello I'm thread #3
          local thread variable: 0, thread id: 3
          local thread variable: 10, thread id: 3
          hello I'm thread #1
          local thread variable: 10, thread id: 1
          local thread variable: 20, thread id: 1
          hello I'm thread #2
          local thread variable: 20, thread id: 2
          local thread variable: 30, thread id: 2
          hello I'm thread #4
          local thread variable: 30, thread id: 4
          local thread variable: 40, thread id: 4
          hello I'm thread #5
          local thread variable: 40, thread id: 5
          local thread variable: 50, thread id: 5
          hello I'm thread #6
          local thread variable: 50, thread id: 6
          local thread variable: 60, thread id: 6
          hello I'm thread #7
          local thread variable: 60, thread id: 7
          local thread variable: 70, thread id: 7
          hello I'm thread #8
          local thread variable: 70, thread id: 8
          local thread variable: 80, thread id: 8
          hello I'm thread #9
          local thread variable: 80, thread id: 9
          local thread variable: 90, thread id: 9
          hello I'm thread #10
          local thread variable: 90, thread id: 10
          local thread variable: 100, thread id: 10
          globalCounter: 100
