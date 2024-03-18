/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** listen_sock.h
*/

#ifndef LIBNWP_LISTEN_SOCK_H_
    #define LIBNWP_LISTEN_SOCK_H_

    #include <netinet/in.h>

typedef struct listen_sock {
    int sock_fd;
    struct sockaddr_in addr;
} listen_sock_t;

listen_sock_t *init_listen_sock(char *ip_addr, unsigned short ip_port);
int init_listen_sock_socket(listen_sock_t *listen_sock,
    char *ip_addr, unsigned short ip_port);
int listen_sock_bind(listen_sock_t *listen_sock, char *ip_addr,
    unsigned short ip_port);
int listen_sock_listen(listen_sock_t *listen_sock);
int get_listen_sock_fd(listen_sock_t *listen_sock);
int terminate_listen_sock(listen_sock_t *listen_sock);

#endif  // LIBNWP_LISTEN_SOCK_H_
