// file: TwoPipesThreeChildren.cpp
// author: Rodolfo Galarza
// date: 04/06/17
// purpose: CS3376

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char **argv){
    int status;
    int childpid, childpid2, childpid3;
    char *cat_args[] = {"ls", "-ltr", NULL};
    char *grep_args[] = {"grep", "main", NULL};
    char *wc_args[] = {"wc", "-l", NULL};
    // create one pipe to send the output of "ls" process to "grep" process
    int pipes[2];
    pipe(pipes);

    int pipe2[2];
    pipe(pipe2);
    // fork the first child (to execute cat)
    if((childpid = fork()) == -1){
    perror("Error creating a child process");
    exit(1);
}else if (( childpid2 = fork()) == -1) {
    perror("error creating a child process");
    exit(1);
}else if (( childpid3 = fork()) == -1) {
    perror("error creating a child process");
    exit(1);
}


if (childpid == 0) {
    // replace cat's stdout with write part of 1st pipe
    dup2(pipes[1], 1);
    // close all pipes (very important!); end we're using was safely copied
    close(pipes[0]);
    
    
   close(pipes[1]);
   execvp(*cat_args, cat_args);
   exit(0);
}

if (childpid2 = 0) {
	dup2(pipe2[1], 1);
	close(pipe2[0]);

   close(pipe2[1]);
   execvp(*grep_args, grep_args);
}

if (childpid3 = 0) {
	dup2(pipe2[0], 0);
	close(pipe2[0]);
	close(pipe2[1]);

    execvp(*wc_args, wc_args);
  
 }
return(0);
}
