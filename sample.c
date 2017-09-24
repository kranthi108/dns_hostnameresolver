#include<stdio.h>
#include<string.h>
void main()
{
int m,k,l,p;
char data[100],data3[100];
int e=1;
scanf("%s",data);
 m=strlen(data);

printf("%s\n",data);
        for(k=m-1;k>0;k--)
        {
             if(data[k]=='.'&&e==0)
             {
              break;
             }
else if(data[k]=='.')
{
e=0;
}
else
{
continue;
}
        }
        p=0;
        for(l=k+1;l<m;l++)
        {
                data3[p]=data[l];
                p++;
        }
data3[p]='\0'; 
printf("%s",data3);
}
