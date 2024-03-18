/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** client_callback.h
*/

#ifndef LIBNWP_CLIENT_CALLBACK_H_
    #define LIBNWP_CLIENT_CALLBACK_H_

    #include "client.h"
    #include "client_pool.h"

typedef struct client_pool client_pool_t;

typedef struct client_callback {
    int (*connect_callback)();
    int (*read_callback)();
    int (*write_callback)();
    int (*except_callback)();
} client_callback_t;

client_callback_t *init_client_callback(void);
int terminate_client_callback(client_callback_t *client_callbacks);

void set_connect_callback(client_callback_t *client_callbacks,
    int (*connect_callback)());
void set_write_callback(client_callback_t *client_callbacks,
    int (*write_callback)());
void set_read_callback(client_callback_t *client_callbacks,
    int (*read_callback)());
void set_except_callback(client_callback_t *client_callbacks,
    int (*except_callback)());

#endif  // LIBNWP_CLIENT_CALLBACK_H_
