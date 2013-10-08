/* Imaoye Ekpelu and Mark Tabor
 * SLUSH
 * Operating Systems
 * September 13, 2013
 */

#include <iostream>
#include <signal.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


using namespace std;

/*
 *handle_interrupt
 */

void handle_interrupt(int the_sig)
{
}

//
// main
//   Set up signal handling, then enter a loop that prints a prompt,
//   reads a line of text and echoes it back.


main(int argc, char **argv)
{
  const int MAX_LINE=256;
  
  char line[MAX_LINE];
  //   char *command[256];
  //   char **argv;
  int pid_child;
  // Establish signal handler for SIGINT (^C)
  signal(SIGINT,handle_interrupt);
  siginterrupt(SIGINT,1);
  
  do {
    int i = 0;
    
    cout << "slush% ";
    errno = 0;
    if (cin.getline(line,MAX_LINE)) {
      //       cout << "You typed: " << line << endl;
    }
    else {
      if (errno == EINTR) {
        cin.clear();
        cout << endl;
      }
    }
    argv[0] = strtok(line," ");
    while(argv[i]!=NULL){    
      i++;
    }
    argv[i] = strtok(NULL," ");
      
    //if (argv[i] == "("){
    //  pid_t fork();
    //execvp(line, argv);

  
  //pid_t fork();
    pid_child = fork();
    if (pid_child== 0){
      cout<<"Child pid is " <<getpid()<<".\n";
      execvp(argv[0], argv);
      perror(argv[0]);
      exit(EXIT_SUCCESS);
  }
    
    else 
      if (pid_child== -1){
	perror("Fork");
	exit(0);
      }
      else {
	waitpid(pid_child, int -1,int 0); 
	//wait(NULL);
	cout<<"Parent pid is " <<getpid()<<".\n";
	
      }
  }  
  

  while (cin);

cout << endl;
}
