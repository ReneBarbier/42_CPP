#pragma once

#include <iostream>

template <typename T>
void iter(T* array, int lenght, void(*f)(T &))
{
	for (int i = 0; i < lenght; i++) {
		f(array[i]);
	}
}

