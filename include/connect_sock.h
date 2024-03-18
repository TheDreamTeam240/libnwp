/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** connect_sock.h
*/

#ifndef LIBNWP_CONNECT_SOCK_H_
    #define LIBNWP_CONNECT_SOCK_H_

    #include <netinet/in.h>

typedef struct connect_sock {
    int sock_fd;
    struct sockaddr_in addr;
} connect_sock_t;

connect_sock_t *init_connect_socket(char *ip_addr, unsigned short ip_port);
int terminate_connect_sock(connect_sock_t *connect_sock);
char *read_accept_sock(connect_sock_t *connect_sock);
int write_accept_sock(connect_sock_t *connect_sock, char *msg);
int printf_accept_sock(connect_sock_t *connect_sock, char *format,
    va_list *args);

#endif  // LIBNWP_CONNECT_ACCEPT_H_
