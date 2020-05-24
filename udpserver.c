/* udpserver.c */ 

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int sock, status;
    struct sockaddr_in my_addr;
    struct iovec iov;
    char   buf[8192];
    struct msghdr msg;

    msg.msg_name = &my_addr;
    msg.msg_namelen = sizeof(struct sockaddr_in);
    msg.msg_iov = &iov;
    msg.msg_iovlen  = 1;
    	
    iov.iov_base = buf;
    iov.iov_len  = sizeof(buf);

    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("Socket");
        exit(1);
    }
 
    memset ((char *)&my_addr, 0, sizeof(struct sockaddr_in));
 
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(5000);
    my_addr.sin_addr.s_addr = INADDR_ANY;

    bzero(&(my_addr.sin_zero),8);

//    if (bind(sock,(struct sockaddr *)&my_addr, sizeof(struct sockaddr)) == -1)
//    {
//        perror("Bind");
//        exit(1);
//    }

    printf("\nUDPServer Waiting for client on port 5000");
    
   iov.iov_base = buf;

   while (1)
   {
       iov.iov_len = sizeof(buf);
       status = recvmsg(sock, &msg, MSG_DONTWAIT);
       printf("ret = %d, %d\n", status, errno);
   }
   return 0;
}
