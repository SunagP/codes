#include <stdio.h>
#include <stdlib.h>
struct covid
{
    char name[10];
    int age;
    char bg[4];
    char address[100];
    struct sym{

     char cough[4],cold[4],fever[4],bodyPain[4];


         }s;

}cov[100];
int main()
{   int n;
    printf("Number of patients");
    scanf("%d",&n);
    char word;
    for(int i=0;i<n;i++)
    {
        printf("Enter patient %d name\n",i+1);
        scanf("%s",&cov[i].name);
        printf("Enter patient %d age\n",i+1);
        scanf("%d",&cov[i].age);
        printf("Enter patient %d blood group\n",i+1);
        scanf("%s",&cov[i].bg);
        printf("Enter patient %d address\n",i+1);
       // gets(cov[i].address);
        scanf("%s",&cov[i].address);

        printf("Enter patient %d symptoms\n",i+1);
        printf("enter 'yes' if sypmtom else 'no'\n\n");
        printf("Cough\n");
        scanf("%s:",&cov[i].s.cough);
        printf("cold\n");
        scanf("%s:",&cov[i].s.cold);
        printf("fever\n");
        scanf("%s:",&cov[i].s.fever);
        printf("Body pain\n");
        scanf("%s:",&cov[i].s.bodyPain);

    }
    for(int i=0;i<n;i++)

    {
        printf("Name: %s\n",cov[i].name);
        printf("age: %d\n",cov[i].age);
        printf("bloodGroup: %s\n",cov[i].bg);
        printf("address: %s\n",cov[i].address);
        printf("Cough: %s\nCold: %s\nFever: %s\nBody pain: %s\n",cov[i].s.cough,cov[i].s.cold,cov[i].s.fever,cov[i].s.bodyPain);
    }


    return 0;
}
