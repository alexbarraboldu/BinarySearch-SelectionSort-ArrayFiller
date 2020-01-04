#include "Header.h"

//	DECLARE ARRAY
int_array arr1;

int searchInt;

struct pivot
{
	int head, tail, size;
};
pivot left, right;

pivot setArrayPivot(int_array _arr, pivot& _left, pivot& _right, int _t)
{
	//	SET LEFT PIVOT ZONE (first round)
	_left.head = _arr.size() - _arr.size();
	_left.tail = (_arr.size() / 2) - 1;
	_left.size = _arr.size() / 2;

	//	SET RIGHT PIVOT ZONE (first round)
	_right.head = _arr.size() / 2;
	_right.tail = _arr.size() - 1;
	_right.size = _arr.size() / 2;

	if (_left.size + _right.size != _arr.size()) { _right.size++; };

	//	RETURN THE PIVOT ZONE (in index)
	if (_t < _arr[_left.tail]) { return _left; }
	else if (_t > _arr[_right.head]){ return _right; }
	else { return _left; }
}

pivot setArrayPivot(int_array _arr, pivot _pivot, int _t)
{ 
		//	Aux pivots
		pivot _left, _right;

		//	SET LEFT PIVOT ZONE (second+ round)
		_left.head = _pivot.head;
		_left.tail = _pivot.tail - (_pivot.size / 2);
		_left.size = _pivot.size / 2;

		//	SET RIGHT PIVOT ZONE (second+ round)
		_right.head = _pivot.tail - (_pivot.size / 2) + 1;
		_right.tail = _pivot.tail;
		_right.size = _pivot.size / 2;

		if (_left.size + _right.size != _pivot.size) { _left.size++; };

		//	RETURN THE PIVOT ZONE (in index)
		if (_t < _arr[_left.tail]) { return _left; }
		else if (_t > _arr[_right.head]) { return _right; }
		else { return _left; }
}

bool binarySearch(int_array _arr, pivot& _left, pivot& _right, int _t)
{
	//	SET FIRST PIVOT ZONE
	pivot _pivot = setArrayPivot(_arr, _left, _right, _t);
	std::cout << "\nFirst round - Pivot array values in index";
	std::cout << "\nHead value: " << _pivot.head << "\t\tTail value: " << _pivot.tail;
	std::cout << "\tSize value: " << _pivot.size;
	std::cout << "\nHead value in array: " << arr1[_pivot.head] << "\tTail value in array: " << arr1[_pivot.tail] << std::endl;
	//	SET OTHER PIVOT ZONE
	if (_arr[_pivot.head] == _t || _arr[_pivot.tail] == _t) { std::cout << "\nNum. iterations: " << 0 << '\n'; return 1; };

	int it = 0;
	for (size_t i = 0; i < _pivot.size; i++)
	{
		it++;
		_pivot = setArrayPivot(_arr, _pivot, _t);
		std::cout << "\n" << it + 1 << " round - Pivot array values in index" << std::endl;
		std::cout << "Head value: " << _pivot.head << "\t\tTail value: " << _pivot.tail;
		std::cout << "\tSize value: " << _pivot.size << std::endl;
		std::cout << "Head value in array: " << _arr[_pivot.head] << "\tTail value in array: " << _arr[_pivot.tail] << std::endl;
		if (_arr[_pivot.head] == _t || _arr[_pivot.tail] == _t) { std::cout << "\nNum. iterations: " << 0 << '\n'; return 1; };
		if (_pivot.size <= i + 1 && _pivot.size != 1) { i = 0; };
	}

	it = 0;
	//	ITERATE TO FIND THE NUMBER
	for (int i = _pivot.head; i < _pivot.tail + 1; i++)
	{
		it++;
		if (_arr[i] == _t ) { std::cout << "\nNum. iterations: " << it << '\n'; return 1; }
	}
	return 0;
};

int main()
{
	//	FILL ARRAY
	arr1 = fillArray(arr1);
	//	PRINT THINGS
	printArray(arr1);
	std::cout << "\n\nSorted array values:\n";
	sortArray(arr1);
	bool bull = true;
	while (bull) {
		printArray(arr1);

		std::cout << "\nintroduce a number to search: ";
		std::cin >> searchInt;

		/*pivot auxPivot = setArrayPivot(arr1, left, right, searchInt);*/

		std::cout << "\nDid it find it?\n" << binarySearch(arr1, left, right, searchInt) << std::endl;

		std::cin.ignore();
		char hey;
		std::cout << "Want to continue?: (S/n) ";
		std::cin >> hey;
		if (hey == 'n') { bull = false; }
		else { system("cls"); continue; };
	}
	return 0;
}