#pragma once
#include <iostream>
#include <array>

const int length = 40000;
typedef std::array<short int, length> int_array;

void printArray(int_array _array);
int_array fillArray(int_array _array);
void sortArray(int_array& _array);