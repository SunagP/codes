#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>



// ALGORITHM:
// Step 1:call the fork function to create child process
// Step2 :close writing option
// Step 3:copy the old file descriptor
// Step 4:exec the command ls –l(long listing files)
// This process will be executed by child
// Step 5: else
// Close reading option
// Copy old file descriptor
// exec the command wc t count no of lines, words, characters
// step 6: both commands concurrently executed by pipe
// step 7:stop
void getFileCreationTime(char *path) {
struct stat attr;
stat(path, &attr);
printf("Last modified time: %s", ctime(&attr.st_mtime));
}
void printFileProperties(struct stat stats)
{
printf("\nFile access: ");
if (stats.st_mode & R_OK)
printf("read ");
if (stats.st_mode & W_OK)
printf("write ");
if (stats.st_mode & X_OK)
printf("execute"); 
printf("\n");
  }
int main(int argc, char *argv[]){
const char *filename;
int st,i;  
struct stat stats;
if (stat(argv[1], &stats) == 0)
{
        
for (i = 1; i < argc; ++i) {
if (stat(argv[i], &stats) == -1) {
perror(argv[i]);
}
else {
filename = argv[i];
st = stat(filename,&stats);
if( st==-1 )
{
fprintf(stderr,"File error!\n");
exit(1);
}
if( S_ISREG(stats.st_mode) )
printf(" '%s' is regular file\n",filename);
else
printf(" '%s' is not a regular file\n",filename);
printf("%s has %ld hard links\n", argv[i], stats.st_nlink);printFileProperties(stats);
getFileCreationTime(argv[1]); 
}
}
}
else
{
printf("Unable to get file properties.\n");
  //  printf("Please check whether '%s' file exists.\n", path);
}
}