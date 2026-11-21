#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void handle_sigterm(int sig){
   printf("I don\'t care I will return to sleep\n");
}

int main(){
   int status_p1;
   int status_p2;
   char command[31];
 system("ps o stat,uid,pid,ppid,pri,start_time,comm");
 pid_t P1 = fork(); // fork1 for P1 
 if(P1 == 0) {

   while(1){
      sleep(3);
      signal(SIGTERM, handle_sigterm);
      printf("I have just awakened, I feel tied, I need to sleep again.\n");
   }

} else if(P1 > 0){
   pid_t P2 = fork(); // fork2 for P2
   if(P2 == 0){

      sleep(2);
      printf("Process %d, stop sleeping it is a warning!\n",P1);
      snprintf(command,sizeof(command),"kill -19 %d",P1);
      system(command);

      sleep(2);
      printf("%d,I awake you don\'t sleep again\n",P1);
      snprintf(command,sizeof(command),"kill -18 %d",P1);
      system(command);

      sleep(4);
      printf("You slept again I will try to kill you %d\n",P1);
      snprintf(command,sizeof(command),"kill -15 %d",P1);
      system(command);

      sleep(4);
      printf("I kill you, %d you are a dead process\n",P1);
      snprintf(command,sizeof(command),"kill -9 %d",P1);
      system(command);
      exit(0);
   } 
   pid_t t1 = 0;
   pid_t t2 = 0;
   int i = 0;
   while(i < 20 ){
      sleep(1);
      t1 =  waitpid(P1,&status_p1,WNOHANG);
      t2 =  waitpid(P2,&status_p2,WNOHANG);
      i++;
      system("ps o stat,uid,pid,ppid,pri,start_time,comm");
      if ((t1 == P1) && (t2 == P2)) break;
   }
   if(t1 == 0){
      snprintf(command,sizeof(command),"kill -9 %d",P1);
      system(command);   
      waitpid(P1, &status_p1, 0);
   }
   if(t2 == 0){
      snprintf(command,sizeof(command),"kill -9 %d",P2);
      system(command);   
      waitpid(P2, &status_p2, 0);
   }
   if(WIFSIGNALED(status_p1)){
      if(WTERMSIG(status_p1) == SIGKILL) printf("Process %d is killed",P1);
   }
   if(WIFSIGNALED(status_p2)){
      if(WTERMSIG(status_p2) == SIGKILL) printf("Process %d is killed",P2);
   }
 } else {
      printf("Fork1 failed!");
   }
 return 0; 
}