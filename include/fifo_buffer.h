/*
** EPITECH PROJECT, 2024
** libnwp
** File description:
** fifo_buffer.h
*/

#ifndef LIBNWP_FIFO_BUFFER_H
    #define LIBNWP_FIFO_BUFFER_H

    #include <stddef.h>

    #define FIFO_BUFFER_DEFAULT_CAPACITY 1024

typedef struct fifo_buffer_s {
    char *buffer;
    size_t capacity;
    size_t size;
} fifo_buffer_t;

fifo_buffer_t *init_fifo_buffer(void);
int terminate_fifo_buffer(fifo_buffer_t *fifo_buffer);
int add_to_fifo_buffer(fifo_buffer_t *fifo_buffer, char *message);
char *remove_from_fifo_buffer(fifo_buffer_t *fifo_buffer, char *delimiter);

#endif  // LIBNWP_FIFO_BUFFER_H
