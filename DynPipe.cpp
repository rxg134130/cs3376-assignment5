// file:Cynpipe.cpp

#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
#include <fcntl.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include <string>
#include <sstream>
int main(int argc, char **argv){
    int status;
    int x = argc - 1;

    int childpid, childpid2, childpid3, childpid4, childpid5;
    char *cat_args[] = {"ls", "-ltr", NULL};
    char *grep_args[] = {"grep", "main", NULL};
    char *wc_args[] = {"wc", "-l", NULL};

    char *fisrt_arg[] = {"", "", NULL};
    char *second_arg[] = {"","", NULL};
    char *third_arg[] = {"", "", NULL};
    char *fourth_arg[] = {"", "", NULL};
    char *fifth_arg[]  = {"","", NULL};
    // create one pipe to send the output of "ls" process to "grep" process
    int pipe1[2];
    pipe(pipe1);

    int pipe2[2];
    pipe(pipe2);

    int pipe3[2];
    pipe(pipe3);

    int pipe4[4];
    pipe(pipe4);

    
    if ( x < 1 || x > 5) {
	perror("incorrect number of arguments");
	return(1);
    }
    
    // if number of arguments is 2
   
   if ( x == 2) {

	pipe(pipe1);

	if ((childpid = fork()) == -1){
		perror("Error creating a child process ");
		exit(1);
	}
	else if(childpid == 0){
	std::stringstream sstream;
 	sstream << argv[2];
	string str1;
	string str2;
	sstream >> str1;
	sstream >> str2;
	arg2[0] = (char*) str1.c_str();
	arg2[1] = (char*) str2.c_str();

	dup2(pipe1[0], 0);

	close(pipe1[0]);
	close(pipe1[1]);
	execvp(*second_arg, second_arg);
	}

	if ((childpid2 = fork()) == -1){
		perror("Error creating a child process");'
		exit(1)
	}
	else if (childpid2 == 0){

	  std::stringstream sstream;
	  sstream << argv[1];
	  string str1;
	  string str2;
	  sstream >> str1;
	  sstream >> str2;
		
	arg1[0] = (char*) str1.c_str();
	arg2[1] = (char*) str2.c_str();	
	
	dup2(pipe1[1],1);

	close(pipe1[0]);
	close(pipe1[1]);
	execvp(*first_arg, first_arg);


   }


  if ( x == 3){
	pipe(pipe1);
	pipe(pipe2);

	if ((childpid1 = fork()) == -1){
		perror("Error creating a child process");
		exit(1);
	}
	else if (childpid1 == 0){
	  	std::stringstream sstream;
		sstream << argv[3];
		string str1;
		string str2;
		third_arg[0] = (char*) str1.c_str();
		third_arg[1] = (char*) str2.c_str();

		dup2(pipe2[0],0);

		close(pipe1[0]);
		close(pipe2[1]);
		close(pipe2[0]);
		close(pipe2[1]);
		execvp(*third_arg, third_arg);
	}

	if ((childpid2 = fork()) == -1){
		perror("Error creating a child process");
		exit(1);

	}
	else if(childpid2 == 0) {
		std::stringstream sstream;
		sstream << argv[2];
		string str1;
		string str2;
		sstream >> str1;
		sstream >> str2;
		second_arg[0] = (char*) str1.c_str();
		second_arg[1] = (char*) str2.c_str();
		dup2(pipe1[0],0)
		dup2(pipe2[1],1);
		close(pipe1[0]);
		close(pipe2[1]);
		execvp(*second_arg, second_arg);
	}
	if ((childpid3 = fork()) == -1){
	                perror("Error creating a child process");
			                exit(1);
 		}
	   else if(childpid3  == 0) {
		std::stringstream sstream;
		sstream << argv[2];
		string str1;
		 string str2;
		 first_arg[0] = (char*) str1.c_str();
		 first_arg[1] = (char*) str2.c_str();
		 dup2(pipe1[1],1);

		 close(pipe1[0]);
		 close(pipe2[1]);
		 close(pipe1[1]);
		 close(pipe2[0]);
	   }
  }
 
// Same process for 4 and 5
if(x == 4){
	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);

}


if (x == 5) {
	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);
	pipe(pipe4);
}















return(0);
}
