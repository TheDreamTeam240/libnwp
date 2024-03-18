/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client_callback.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "client_callback.h"

client_callback_t *init_client_callback(void)
{
    client_callback_t *client_callback = malloc(sizeof(client_callback_t));

    if (client_callback == NULL)
        return NULL;
    client_callback->connect_callback = NULL;
    client_callback->write_callback = NULL;
    client_callback->read_callback = NULL;
    client_callback->except_callback = NULL;
    return client_callback;
}

int terminate_client_callback(client_callback_t *client_callback)
{
    free(client_callback);
    return EXIT_SUCCESS;
}
