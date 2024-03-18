/*
** EPITECH PROJECT, 2023
** B-NWP-400-RUN-4-1-myftp-clement-antoine.xavier
** File description:
** client_callback_modifiers.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "client_callback.h"

void set_connect_callback(client_callback_t *client_callbacks,
    int (*connect_callback)())
{
    client_callbacks->connect_callback = connect_callback;
}

void set_write_callback(client_callback_t *client_callbacks,
    int (*write_callback)())
{
    client_callbacks->write_callback = write_callback;
}

void set_read_callback(client_callback_t *client_callbacks,
    int (*read_callback)())
{
    client_callbacks->read_callback = read_callback;
}

void set_except_callback(client_callback_t *client_callbacks,
    int (*except_callback)())
{
    client_callbacks->except_callback = except_callback;
}
