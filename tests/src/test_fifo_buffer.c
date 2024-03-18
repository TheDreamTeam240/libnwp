/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** test_fifo_buffer.c
*/

#include <criterion/criterion.h>
#include <stdlib.h>

#include "fifo_buffer.h"

Test(fifo_buffer, init_fifo_buffer)
{
    fifo_buffer_t *fifo_buffer = init_fifo_buffer();

    if (fifo_buffer == NULL)
        cr_assert_fail();
    terminate_fifo_buffer(fifo_buffer);
}

Test(fifo_buffer, add_to_fifo_buffer)
{
    fifo_buffer_t *fifo_buffer = init_fifo_buffer();
    char *message = NULL;

    if (fifo_buffer == NULL)
        cr_assert_fail();
    if (add_to_fifo_buffer(fifo_buffer, "Hello, world!") == EXIT_FAILURE)
        cr_assert_fail();
    message = remove_from_fifo_buffer(fifo_buffer, ", ");
    cr_assert_str_eq(message, "Hello");
    free(message);
    message = remove_from_fifo_buffer(fifo_buffer, ", ");
    cr_assert_str_eq(message, "world!");
    free(message);
    message = remove_from_fifo_buffer(fifo_buffer, ", ");
    cr_assert_str_empty(message);
    terminate_fifo_buffer(fifo_buffer);
}