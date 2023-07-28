#pragma once

template <typename T>
void iter(T *array, size_t length, void (*fn)(T &element))
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}

template <typename T>
void iter(T *array, size_t length, void (*fn)(const T &element))
{
	for (size_t i = 0; i < length; i++)
	{
		fn(array[i]);
	}
}
