/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** client_pool.h
*/

#ifndef LIBNWP_CLIENT_POOL_H_
    #define LIBNWP_CLIENT_POOL_H_

    #include "client.h"
    #include "client_callback.h"

    #include <sys/select.h>

    #define MAX_CLIENTS (FD_SETSIZE - 1)

typedef struct client_callback client_callback_t;

typedef enum client_pool_state {
    CLIENT_NOT_USED = 0,
    CLIENT_USED = 1
} client_pool_state_t;

typedef struct client_pool {
    int listen_sock_fd;
    client_callback_t *client_callback;
    client_t *clients[MAX_CLIENTS];
    client_pool_state_t clients_state[MAX_CLIENTS];
    void *data[MAX_CLIENTS];
    fd_set read_fds;
    fd_set write_fds;
    fd_set error_fds;
    int max_fd;
    size_t last_client_index;
} client_pool_t;

typedef struct fd_set_callback {
    fd_set *fd_set;
    int (*callback)(client_pool_t *client_pool, size_t client_index);
} fd_set_callback_t;


client_pool_t *init_client_pool(int listen_sock_fd,
    client_callback_t *client_callback, void *data[MAX_CLIENTS]);
int terminate_client_pool(client_pool_t *client_pool);
int add_client(client_pool_t *client_pool, client_t *client);
int remove_client(client_pool_t *client_pool, client_t *client);
int refresh_client_pool(client_pool_t *client_pool);
int iterate_client_pool(client_pool_t *client_pool);
int client_pool_routine(client_pool_t *client_pool);
int handle_readable_listen_sock(client_pool_t *client_pool);
int handle_writable_client(client_pool_t *client_pool, size_t client_index);
int handle_readable_client(client_pool_t *client_pool, size_t client_index);
int handle_error_client(client_pool_t *client_pool, size_t client_index);

#endif  // LIBNWP_CLIENT_POOL_H_
