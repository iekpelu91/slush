/* Imaoye Ekpelu and Mark Tabor
 * SLUSH
 * Operating Systems
 * September 13, 2013
 *
 *
 *
 */


//for strtok, strcmp
#include <string.h>
//for close, dup2, pipe, execvp, fork
#include <unistd.h>
//for dup2, pipe
#include <fcntl.h>
//for pipe
#define _GNU_SOURCE
//for wait
#include <sys/types.h>
//for wait
#include <sys/wait.h>
//for signal, siginterrupt
#include <signal.h>
