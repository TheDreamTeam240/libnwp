/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** server.h
*/

#ifndef LIBNWP_SERVER_H_
    #define LIBNWP_SERVER_H_

    #include "listen_sock.h"
    #include "client_pool.h"

typedef struct server {
    char *ip_addr;
    unsigned short ip_port;
    client_callback_t *client_callback;
    void *data[MAX_CLIENTS];
    listen_sock_t *listen_sock;
    client_pool_t *client_pool;
} server_t;

server_t *init_server(char *ip_addr, unsigned short ip_port,
    client_callback_t *client_callback, void *data[MAX_CLIENTS]);
int terminate_server(server_t *server);
int server_routine(server_t *server);

#endif  // LIBNWP_SERVER_H_
