#ifndef SERVER_H
#define SERVER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>

#include <fcntl.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <QDebug>
#include <QThread>


class Server : public QThread
{
public:
    Server(QObject *parent = Q_NULLPTR);
    void init_server();
    void read_request();
    void send_file();
    void send_helper(char *, int);
    void run();
    int getSuccess();
    int local_host();

protected:
    struct sockaddr_in s_addr;
    struct sockaddr_in c_addr;
    socklen_t c_addr_size;
    int s_sock;// server socket
    int c_sock;// clinet socket


    char buf[4096];// user agent
    char msg[4096];// file content
    char head[1024];// http header
    char fileRequest[128];// which file requested
    char fileSend[256];// file send to client
    char type[128];// file format
    const char *rootDir = "/home/lynx/fuck_mount/QtProj/test2/http";

    int success;// bind success
};

#endif // SERVER_H
