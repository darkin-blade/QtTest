#ifndef SERVER_H
#define SERVER_H

void init_server();
void read_request();
void send_file();
void send_helper(char *, int);
int local_host();

#endif // SERVER_H
