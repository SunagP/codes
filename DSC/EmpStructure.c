#include<stdio.h>

struct employe
{
    char name[10];
    int eid;
    int age;
    int sal;
}emp_details[100];

int main()
{
    int i,n;
   struct employe *emp;

   emp=&emp_details;

   printf("Enter number of employees\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
      printf("\nEnter employee %d name : ",i+1);
      //gets(emp->name);
      scanf("%s",(emp+i)->name);
      printf("Enter employee %d ID : ",i+1);
      scanf("%d",&(emp+i)->eid);
      printf("Enter employee %d age : ",i+1);
      scanf("%d",&(emp+i)->age);
      printf("Enter employee %d salary : ",i+1);
      scanf("%d",&(emp+i)->sal);
   }
   printf("---------------------------------------------\n");
   printf("Employees details\n\n");
   for(i=0;i<n;i++)
   {
       printf("Name        : %s\nEmployee ID : %d\nAge         : %d\nSalary      : %d\n\n",(emp+i)->name,(emp+i)->eid,(emp+i)->age,(emp+i)->sal);

   }
return 0;

}
