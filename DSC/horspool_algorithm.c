#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int main()
{
    char text[10000],patt[100];
    FILE *fptr;
    fptr = fopen("file1.txt","r");
    if(fptr==NULL)
    {
        printf("Error file not found!");
        exit(1);
    }
    char c;
    int j=0;
    while((c=fgetc(fptr))!=EOF)
    {
        text[j]=c;
        j++;
    }
    text[j]='\0';
    fclose(fptr);
    for(int i=0;i<strlen(text);i++)
    {
        printf("%c",text[i]);
    }


    printf("\n\nenter the pattern: ");
    scanf("%[^\n]%*c",&patt);
    int jumps[122];

    for(int i=0;i<122;i++)
        jumps[i]=strlen(patt);

    for(int i=0;i<strlen(patt)-1;i++)
        jumps[(int)patt[i]]=strlen(patt)-i-1;


  int i=0;
  clock_t stime,etime;
  stime=clock();
    while(i<=strlen(text)-strlen(patt))
    {
        int n=strlen(patt)-1;
        while(text[i+n]==patt[n] && n>-1)
            n--;

        if(n==-1)
        {
            printf("the pattern is found at %d",i+1);
            etime=clock();
            printf("\n\nthe time taken is %e",difftime(etime,stime));
            exit(1);
        }
        else{i+=jumps[(int)text[i+strlen(patt)-1]];}
    }
    printf("pattern not found");
}
