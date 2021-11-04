// socket program to send and receive data

void check(char *ip, int port)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    // create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("create socket error: %s(errno: %d)\n", strerror(errno), errno);
        return;
    }

    // init servaddr


    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;

    if (inet_pton(AF_INET, ip, &servaddr.sin_addr) <= 0)
    {
        printf("inet_pton error for %s\n", ip);
        return;
    }

    servaddr.sin_port = htons(port);

    // connect to server

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        printf("connect error: %s(errno: %d)\n", strerror(errno), errno);
        return;
    }


    // send message to server

    while (fgets(sendline, MAXLINE, stdin) != NULL)
    {
        send(sockfd, sendline, strlen(sendline), 0);
        if (strcmp(sendline, "exit\n") == 0)
        {
            break;
        }

        // recv a reply from server

        if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0)
        {
            printf("recv error: %s(errno: %d)\n", strerror(errno), errno);
            return;
        }
        recvline[n] = 0;
        if (fputs(recvline, stdout) == EOF)
        {
            printf("fputs error\n");
        }
    }


    // close socket

    close(sockfd);

    return;
}


int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("usage: %s <IPaddress> <port>\n", argv[0]);
        return 1;
    }

    check(argv[1], atoi(argv[2]));

    return 0;
}


// Language: c