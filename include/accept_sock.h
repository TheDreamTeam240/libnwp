/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** accept_sock.h
*/

#ifndef LIBNWP_ACCEPT_SOCK_H_
    #define LIBNWP_ACCEPT_SOCK_H_

    #define BUFFER_SIZE 1024

    #include <netinet/in.h>
    #include <stdarg.h>

typedef struct accept_sock {
    int sock_fd;
    struct sockaddr_in addr;
    socklen_t addr_len;
    char *buffer;
} accept_sock_t;

accept_sock_t *init_accept_sock(int listen_sock_fd);
int terminate_accept_sock(accept_sock_t *accept_sock);
int get_accept_sock_fd(accept_sock_t *accept_sock);
char *read_accept_sock(accept_sock_t *accept_sock);
int write_accept_sock(accept_sock_t *accept_sock, char *msg);
int printf_accept_sock(accept_sock_t *accept_sock, char *format,
    va_list *args);

#endif  // LIBNWP_ACCEPT_SOCK_H_
