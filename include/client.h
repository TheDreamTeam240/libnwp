/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** client.h
*/

#ifndef LIBNWP_CLIENT_H_
    #define LIBNWP_CLIENT_H_

    #include "accept_sock.h"

typedef enum exit_status {
    SUCCESS = 0,
    FAILURE = 84,
    CONTINUE = 1
} exit_status_t;

typedef struct client {
    accept_sock_t *accept_sock;
} client_t;

client_t *init_client(int listen_sock_fd);
int terminate_client(client_t *client);
int get_client_sock_fd(client_t *client);
char *read_client(client_t *client);
int write_client(client_t *client, char *msg);
int printf_client(client_t *client, char *format, ...);

#endif  // LIBNWP_CLIENT_H_
