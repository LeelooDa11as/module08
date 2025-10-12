#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <deque>
#include <algorithm>

template< typename T>

typename T::iterator	easyfind(T &container, int n) {
	typename	T::iterator	start = container.begin();
	typename	T::iterator	end = container.end();
	typename	T::iterator	res = std::find(start, end, n);
	if (res == end)
		throw("No such value found");
	return res;	
}