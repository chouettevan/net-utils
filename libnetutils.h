#ifndef NETUTILS_H_
#define NETUTILS_H_
/**
 * creates a socket,binds it to the specified port,and listens for up to 
 * count connections.returns the file descriptor
 */
int serve_tcp(int port,int count);
#endif
