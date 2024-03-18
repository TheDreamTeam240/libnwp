/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** fifo_buffer.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fifo_buffer.h"

fifo_buffer_t *init_fifo_buffer(void)
{
    fifo_buffer_t *fifo_buffer = malloc(sizeof(fifo_buffer_t));

    if (fifo_buffer == NULL)
        return NULL;
    fifo_buffer->buffer = malloc(FIFO_BUFFER_DEFAULT_CAPACITY);
    if (fifo_buffer->buffer == NULL)
        return NULL;
    memset(fifo_buffer->buffer, 0, FIFO_BUFFER_DEFAULT_CAPACITY);
    fifo_buffer->capacity = FIFO_BUFFER_DEFAULT_CAPACITY;
    fifo_buffer->size = 0;
    return fifo_buffer;
}

int terminate_fifo_buffer(fifo_buffer_t *fifo_buffer)
{
    free(fifo_buffer->buffer);
    free(fifo_buffer);
    return EXIT_SUCCESS;
}

int add_to_fifo_buffer(fifo_buffer_t *fifo_buffer, char *message)
{
    size_t message_len = strlen(message);

    if (fifo_buffer->size + message_len > fifo_buffer->capacity) {
        fifo_buffer->buffer = realloc(fifo_buffer->buffer,
            fifo_buffer->capacity + message_len);
        if (fifo_buffer->buffer == NULL)
            return EXIT_FAILURE;
        fifo_buffer->capacity += message_len;
    }
    memcpy(fifo_buffer->buffer + fifo_buffer->size, message, message_len);
    fifo_buffer->size += message_len;
    return EXIT_SUCCESS;
}

char *remove_from_fifo_buffer(fifo_buffer_t *fifo_buffer, char *delimiter)
{
    char *delimiter_position = NULL;
    char *message = NULL;

    delimiter_position = strstr(fifo_buffer->buffer, delimiter);
    if (delimiter_position == NULL)
        delimiter_position = fifo_buffer->buffer + fifo_buffer->size;
    message = strndup(fifo_buffer->buffer, delimiter_position -
        fifo_buffer->buffer);
    if (message == NULL)
        return NULL;
    memmove(fifo_buffer->buffer, delimiter_position + strlen(delimiter),
        fifo_buffer->size - (delimiter_position - fifo_buffer->buffer));
    memset(fifo_buffer->buffer + fifo_buffer->size -
        (delimiter_position - fifo_buffer->buffer), 0,
        delimiter_position - fifo_buffer->buffer);
    fifo_buffer->size -= strlen(message);
    return message;
}
