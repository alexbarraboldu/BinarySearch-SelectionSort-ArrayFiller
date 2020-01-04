#include "Header.h"

int_array fillArray(int_array _array)
{
	short int ran;
	for (size_t i = 0; i < _array.size(); i++)
	{
		ran = rand() % 60000;
		_array[i] = ran;
	}
	return _array;
};

void printArray(int_array _array)
{
	for (size_t i = 0; i < _array.size(); i++)
	{
		std::cout << _array[i] << ' ';
	}
};

void sortArray(int_array& _array)
{
	int auxHead;
	for (size_t j = 0; j < _array.size(); j++)
	{
		for (size_t i = 0; i < _array.size(); i++)
		{
			if (_array[i] <= _array[j]) { continue; }
			else
			{
				auxHead = _array[j];
				_array[j] = _array[i];
				_array[i] = auxHead;
			}
		}
	}
};