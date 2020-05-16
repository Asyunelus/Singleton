#include "stdafx.h"


std::vector<int> SplitNumber(int base, int* types, int size)
{
	std::deque<int> first;
	while (base >= 10) {
		first.push_front(base % 10);
		base /= 10;
	}
	first.push_front(base);

	std::vector<int> result;
	for (int i = 0; i < size; ++i) {
		int Value = 0;
		for (int j = 0; j < types[i]; ++j) {
			if (first.size() == 0) break;
			Value = Value * 10 + first[0];
			first.pop_front();
		}
		result.push_back(Value);
	}

	return result;
}
