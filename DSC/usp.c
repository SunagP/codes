#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
if(signo==SIGINT)
{
printf("recieved signal from keyboard");
}
}
int main(void)
{
if(signal(SIGINT,sig_handler)==SIG_ERR)
{
printf("unable to recieve signal from keyboard");
}
while(1)
  sleep(1);
return 0;
}