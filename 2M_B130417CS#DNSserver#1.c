#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<unistd.h>
#include<arpa/inet.h>


main()
{
        int sock,cli,sock1,no;
        struct sockaddr_in local_server, client,root_server,tld_server,auth_server;
        unsigned int len = sizeof(struct sockaddr_in);
        char msg[] = "hello to the  world of sockets \n";
        char msg1[] = "invalid host name"; char msg2[]="no";
        char data[1024],datar[1024],data2[1024],wrd[100],ch1[50],ch2[50],ch[1],un[50],pw[50],output[1024],data3[1024],output1[1024],data4[1024];
        int ln,sent,data_len,wrd_len,i=0,cpln=0,j,cnt=0,flag=0,s_ln,s1,s2;
        FILE *fp,*fp1;

        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock == -1)
        {
                perror("socket: ");
                exit(-1);
        }

        local_server.sin_family = AF_INET;
        local_server.sin_port = htons(8880);
        local_server.sin_addr.s_addr = inet_addr("127.0.0.1");
        bzero(&local_server.sin_zero, 8);

        s_ln = sizeof(struct sockaddr_in);

if( (bind(sock, (struct sockaddr *)&local_server, len)) == -1 )
        {
                perror("bind ");
                exit(-1);
        }

        bzero(data,1024);
        data_len = recvfrom(sock,data,1024,0,(struct sockaddr *)&client,&s_ln);
        if(data_len < 0)
        { perror("recv1:"); }
        printf("host name is %s \n",data);
        fp = fopen("cacheddns.txt","r");
        if(fp == NULL)
        { perror("error in opening file");exit(-1); }
     // printf("\n%s %s\n",un,pw);
int pong;
        while( fscanf(fp, "%s %s %d",ch1,ch2,&pong ) != EOF )
        {
     //      fgets(&ch1,10,fp);fgets(&ch2,10,fp);
                if((strcmp(data, ch1) == 0)){
                flag = 1; bzero(datar,1024);
                strcpy(datar,ch2);
//              sendto(sock,datar,strlen(datar),0,(struct sockaddr *)&server,&s_ln);
                printf("%s %s ",ch1,ch2);printf("%d\n",flag);
printf("present in the cache record\n");
                break;
                }
         }
        
        if(flag == 1){
           sent = sendto(sock,datar,strlen(datar),0,(struct sockaddr *)&client,sizeof(client));
sent = sendto(sock,&pong,sizeof(int),0,(struct sockaddr *)&client,sizeof(client));
           if(sent < 0) { perror("sent:"); }
fclose(fp);
        }
        else
        {
                
                sock1 = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock1 == -1)
        {
                perror("socket: ");
                exit(-1);
        }

        root_server.sin_family = AF_INET;
        root_server.sin_port = htons(8881);
        root_server.sin_addr.s_addr = inet_addr("127.0.0.10");
        bzero(&root_server.sin_zero, 8);

              s_ln = sizeof(struct sockaddr_in);

int k,l;
 int m=strlen(data);
        for(k=m-1;k>0;k--)
        {
             if(data[k]=='.')
             {
                break;
             }
        }
        int p=0;
        for(l=k+1;l<m;l++)
        {
                data2[p]=data[l];
                p++;
        }
data2[p]='\0';  
s1 = sendto(sock1,data2,strlen(data2),0,(struct sockaddr *)&root_server,sizeof(root_server));
   if(s1 < 0)
        { perror("s1:"); }

s2 = recvfrom(sock1,output,1024,0,(struct sockaddr *)&root_server,&s_ln);
s2 = recvfrom(sock1,&no,sizeof(int),0,(struct sockaddr *)&root_server,&s_ln);
printf("the tld ip is %s and port number is %d\n",output,no);
         int sock2 ;
sock2= socket(AF_INET, SOCK_DGRAM, 0);
        if(sock2 == -1)
        {
                perror("socket: ");
                exit(-1);
        }
    tld_server.sin_family = AF_INET;
        tld_server.sin_port = htons(no);
        tld_server.sin_addr.s_addr = inet_addr(output);
        bzero(&tld_server.sin_zero, 8);
   s_ln = sizeof(struct sockaddr_in);

int e=1;
int y=strlen(data);
printf("%s %d\n",data,y);
int v;


printf("%s",data);
s1 = sendto(sock2,data,strlen(data),0,(struct sockaddr *)&tld_server,sizeof(tld_server));
   if(s1 < 0)
        { perror("s1:"); }
int no1;
s2 = recvfrom(sock2,output1,1024,0,(struct sockaddr *)&tld_server,&s_ln);
s2 = recvfrom(sock2,&no1,sizeof(int),0,(struct sockaddr *)&tld_server,&s_ln);
printf("the aut address for %s is %s and the port number is %d\n",data3,output1,no);

  int sock3 = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock3 == -1)
        {
                perror("socket: ");
                exit(-1);
        }
  auth_server.sin_family = AF_INET;
        auth_server.sin_port = htons(no1);
        auth_server.sin_addr.s_addr = inet_addr(output1);
        bzero(&auth_server.sin_zero, 8);
   s_ln = sizeof(struct sockaddr_in);
s1 = sendto(sock2,data,strlen(data),0,(struct sockaddr *)&auth_server,sizeof(auth_server));
if(s1 < 0)
        { perror("s1:"); }

s2 = recvfrom(sock2,output1,1024,0,(struct sockaddr *)&auth_server,&s_ln);
s2 = recvfrom(sock2,&no,sizeof(int),0,(struct sockaddr *)&auth_server,&s_ln);
printf("the actual ip address for %s is %s and the port number is %d\n",data3,output1,no);
  sent = sendto(sock,output1,strlen(output1),0,(struct sockaddr *)&client,sizeof(client));
  sent = sendto(sock,&no,sizeof(no),0,(struct sockaddr *)&client,sizeof(client));
 fp1 = fopen("cacheddns.txt","w");
fprintf(fp1,"%s %s %d",data,output1,no);
fclose(fp1);
}
}
