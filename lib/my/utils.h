/*
** EPITECH PROJECT, 2021
** Utils
** File description:
** Utils header file
*/

#ifndef UTILS_H
    #define UTILS_H

    #define ATOD(x) (x - 48)
    #define DTOA(x) (x + 48)

    #define MIN(x,y) (x < y ? (x) : (y))
    #define MAX(x,y) (x > y ? (x) : (y))

    #define ABS(x) (x < 0 ? -x : x)

static const int FALSE = 0;
static const int TRUE = 1;

static const char END_OF_STRING = '\0';

#endif
