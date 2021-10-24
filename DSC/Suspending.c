#include<stdlib.h>
#include<sys/types.h>
#include<sys/fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void sig_al(int signo){
    printf("Signal received\n");
}
int main(){
     int s;
    if(signal(SIGINT,sig_al)==SIG_ERR){
        perror("error");
    }
    else{
        printf("suspending\n");
        alarm(5);
        for(int i=0;i<10;i++){
            printf("loop:%d\n",i);
            
        }
                    printf("Main terminated\n");

    }

}