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
  int i = 0;
//   char **argv;
  // Establish signal handler for SIGINT (^C)
  signal(SIGINT,handle_interrupt);
  siginterrupt(SIGINT,1);

  do {
    cout << "slush% ";
    errno = 0;
    if (cin.getline(line,MAX_LINE)) {
      cout << "You typed: " << line << endl;
    } else {
      if (errno == EINTR) {
        cin.clear();
        cout << endl;
      }
    }
    while (argv[i]!= NULL)
      {
	argv[i] = strtok(line," ");
	i++;
	
	execvp(line, argv);
      }
      
  } while (cin);

  cout << endl;
}
