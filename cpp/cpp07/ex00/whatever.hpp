template<typename T>
void swap(T & x1, T & x2) {
	T tmp = x1;
	x1 = x2;
	x2 = tmp;
}

template<typename T>
T & min(T & x1, T & x2) {
	return ((x1 < x2) ? x1 : x2);
}

template<typename T>
T & max(T & x1, T & x2) {
	return ((x1 > x2) ? x1 : x2);
}
