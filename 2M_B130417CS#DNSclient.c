#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>

void main()
{
        struct sockaddr_in remote_server;
        int sock,len,i=0,ln,flag=0,s1,s2,wrdln=0,s_ln,no;
        char msg[100],msg1[2],input[1024],output[1024],fnm[50],ch,un[50],pw[50],wrd[50];
        FILE *fp; char cmp[]="ok";

        sock = socket(AF_INET, SOCK_DGRAM, 0);
        if(sock == -1)
        {
                perror("socket"); exit(-1);
        }

        remote_server.sin_family = AF_INET;
        remote_server.sin_port = htons(8880);
        remote_server.sin_addr.s_addr = inet_addr("127.0.0.1");
        bzero(&remote_server.sin_zero, 8);

        s_ln = sizeof(struct sockaddr_in);
        bzero(input,1024);
        printf("enter host name: ");
        scanf("%s",input);

        s1 = sendto(sock,input,strlen(input),0,(struct sockaddr *)&remote_server,sizeof(remote_server));
        if(s1 < 0)
        { perror("s1:"); }
        printf("IP address is : ");
        bzero(output,1024);
//      len = recvfrom(sock,output,1024,0,(struct sockaddr *)&remote_server,sizeof(remote_server));
        s2 = recvfrom(sock,output,1024,0,(struct sockaddr *)&remote_server,&s_ln);
        if(s2 < 0){  perror("recv2:"); }
        s2 = recvfrom(sock,&no,sizeof(int),0,(struct sockaddr *)&remote_server,&s_ln);
        printf("%s and port number is %d\n",output,no);

}

