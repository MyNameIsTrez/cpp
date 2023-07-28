#pragma once

#include <stddef.h>

template <typename T>
void iter(T *array, size_t length, void (*fn)(T &element));

template <typename T>
void iter(T *array, size_t length, void (*fn)(const T &element));

#include "iter.tpp"
