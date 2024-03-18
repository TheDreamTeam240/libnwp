/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** test_server.c
*/

#include <criterion/criterion.h>

#include "client_callback.h"
#include "server.h"

Test(server, init_server)
{
    char *data[MAX_CLIENTS] = {NULL};
    client_callback_t *client_callback = init_client_callback();
    if (client_callback == NULL)
        cr_assert_fail();
    server_t *server = init_server("0.0.0.0", 4242, client_callback, (void **)data);
    terminate_server(server);
}
