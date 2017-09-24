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
        int sock,cli,no;
        struct sockaddr_in local_server,root_server;
        unsigned int len = sizeof(struct sockaddr_in);
        char msg[] = "hello to the  world of sockets \n";
        char msg1[] = "invalid host name"; char msg2[]="no";
        char data[1024],datar[1024],wrd[100],ch1[50],ch2[50],ch[1],un[50],pw[50],data2[1024],output[1024];
        int ln,sent,data_len,wrd_len,i=0,cpln=0,j,cnt=0,flag=0,s_ln,s1;
        FILE *fp;

        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock == -1)
        {
                perror("socket: ");
                exit(-1);
        }   
        local_server.sin_family = AF_INET;
        local_server.sin_port = htons(7004);
        local_server.sin_addr.s_addr = inet_addr("127.0.0.4");
        bzero(&local_server.sin_zero, 8);

        s_ln = sizeof(struct sockaddr_in);
        if( (bind(sock, (struct sockaddr *)&local_server, len)) == -1 )
        {
                perror("bind ");
                exit(-1);
        }
 bzero(data,1024);
        data_len = recvfrom(sock,data2,1024,0,(struct sockaddr *)&local_server,&s_ln);
        
        if(data_len < 0)
        { perror("recv1:"); }
        fp = fopen("resource_record.txt","r");
        if(fp == NULL)
        { perror("error in opening file");exit(-1); }
       

//printf("%s length is %d",data2,strlen(data2));
          while( fscanf(fp, "%s %s %d",ch1,ch2,&no ) != EOF )
        {
     //      fgets(&ch1,10,fp);fgets(&ch2,10,fp);
                if((strcmp(data2, ch1) == 0)){
                flag = 1; bzero(datar,1024);
                strcpy(datar,ch2);
//              sendto(sock,datar,strlen(datar),0,(struct sockaddr *)&server,&s_ln);
                printf("%s %s ",ch1,ch2);
                break;
                }
         }
if(flag == 1){
           sent = sendto(sock,datar,strlen(datar),0,(struct sockaddr *)&local_server,sizeof(local_server));
           if(sent < 0) { perror("sent:"); }
sent = sendto(sock,&no,sizeof(int),0,(struct sockaddr *)&local_server,sizeof(local_server));
        }

        else{
        sent = sendto(sock,msg1,strlen(msg1),0,(struct sockaddr *)&local_server,sizeof(local_server));
        if(sent < 0) { perror("sent else:"); }
        }

}
