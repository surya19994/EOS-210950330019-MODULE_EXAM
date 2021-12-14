#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

pid_t c1_pid, c2_pid;

(c1_pid = fork()) && (c2_pid = fork()); // Creates two children

if (c1_pid == 0) {
    
} else if (c2_pid == 0) {
   
} else {
    
}