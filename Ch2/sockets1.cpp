#include "winsock.h"
#include "ws2tcpip.h"


int main() {
    // Initialize Winsock version 2.2
    WSADATA winsockdata;
    WSAStartup( MAKEWORD( 2, 2 ), &winsockdata );
    
    // Creating a socket on address family IPV4, TCP socket with TCP protocol. 
    int sock = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP );

    struct sockaddr_in socketaddress;                
    socketaddress.sin_family = AF_INET;                   // AF_INET similar to above           
    socketaddress.sin_port = htons( 1000 );               // Binding socket to port 1000
    socketaddress.sin_addr.s_addr = htonl( INADDR_ANY );  // Bind to any address so the socket will receive from any address
    memset( &(socketaddress.sin_zero), 0, 8 );          

    //socketaddress.sin_addr.s_addr = inet_addr( "127.0.0.1" ); 


    // Bind socket to the sockaddr
    bind( sock, (struct sockaddr*)&socketaddress, sizeof(struct sockaddr)); 
    
    // Make the socket listen to queue up to 16 connections
    listen( sock, 16 );

    // Set the datasock to accept connections
    int datasock;
    struct sockaddr_in socketaddress;
    socklen_t sa_size = sizeof( struct sockaddr_in );
    datasock = accept(sock, (struct sockaddr*)&socketaddress, &sa_size);



}