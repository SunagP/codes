#include<stdio.h>
    int main()
    {
         int characters=0, words=0, lines=0;

         FILE *x;
         char ch;
         x=fopen("Input.txt","w");
         printf("Enter the data:\n");
         while((ch=getchar())!=EOF)
    {
    putc(ch,x);
    if(ch==EOF)
        continue;
                characters++;



            if (ch == '\n' || ch == '\0')
                lines++;


            if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
                words++;
        }


        if (characters > 0)
        {
            words++;
            lines++;

    }

     fclose(x);

        printf("\n");
        printf("Total characters = %d\n", characters);
        printf("Total words      = %d\n", words);
        printf("Total lines      = %d\n", lines);





    return 0;
    }
