#include <stdio.h>
#include <stdlib.h>

int main()
{
    int upper,lower=1,middle,m=0,count=0,x,y;
    FILE *f=fopen("data.txt","r");
    fseek(f,0,2);
    upper=ftell(f)/4;
     printf("Which value are you looking for? : \n");
     scanf("%d",&x);
     while(lower<=upper)
     {
         middle=(lower+upper)/2;
         fseek(f,(middle-1)*4,0);
         fscanf(f,"%d\n",&m);
         count++;
         printf("Middle is %d\n",m);
         if(x==m)
         {
             printf("The number you are looking for is %d\n",m);
             break;
         }
         else if(x<m)
         {
             upper=middle-1;
         }
         else
            lower=middle+1;

     }
 if(lower>upper)
    printf("I could not find your number\n# of probes = %d\n",count+1);
   else
   printf("# of probes = %d",count);
    return 0;
}
