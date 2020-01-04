#include "Header.h"

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
	if (_t <= _arr[_left.tail]) { return _left; }
	else { return _right; }
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
	_right.head = (_pivot.tail + 1) - (_pivot.size / 2);
	_right.tail = _pivot.tail;
	_right.size = _pivot.size / 2;

	if (_left.size + _right.size != _pivot.size) { _right.size++; };

	//	RETURN THE PIVOT ZONE (in index)
	if (_t <= _arr[_left.tail]) { return _left; }
	else { return _right; }
}

bool binarySearch(int_array _arr, pivot& _left, pivot& _right, int _t)
{
	//	SET FIRST PIVOT ZONE
	pivot _pivot = setArrayPivot(_arr, _left, _right, _t);
	//	SET SECOND PIVOT ZONE
	_pivot = setArrayPivot(_arr, _pivot, _t);

	std::cout << "\nSecond round - Pivot array values in index" << std::endl;
	std::cout << "Head value: " << _pivot.head << "\tTail value: " << _pivot.tail << std::endl;

	int it = 0;
	//	ITERATE TO FIND THE NUMBER
	for (int i = _pivot.head; i < _pivot.tail + 1; i++)
	{
		it++;
		if (_arr[i] > _t || _arr[i] < _t) { continue; }
		else { std::cout << "\nNum. iterations: " << it << '\n'; return 1; };
	}
	return 0;
};