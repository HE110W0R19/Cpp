#pragma once
class Queue_Priority {
	double* pq;
	size_t size;
	size_t max_size;
public:
	Queue_Priority() :pq(nullptr), size(0), max_size(0) {}
	void push(double Val);
	void pop();
	double top();
	double back() { return pq[size - 1]; };
	bool Empty() { return size == 0; }
};
void Queue_Priority::push(double Val)
{
	if (size >= max_size) {
		++max_size;
		double* tmp = new double[max_size];
		for (int i = 0; i < size; ++i) {
			tmp [i] = pq [i];
		}
		delete[] pq;
		pq = tmp;
	}
	*(pq + size) = Val;
	++size;
}
void Queue_Priority::pop()
{
	size_t poz = 0;
	for (int i = 0; i < size; ++i) {
		if (pq [ poz] < pq [ i]) {
			poz = i;
		}
	}
	--size;
	for (int i = poz; i < size; ++i) {
		pq [ i] = pq [ i + 1];
	}
}
double Queue_Priority::top()
{
	size_t poz = 0;
	for (int i = 0; i < size; ++i) {
		if (pq[ poz] < pq[i]) {
			poz = i;
		}
	}
	return pq [ poz];
}


class Double_Priority {
	double* pq;//массив значений
	int* index;//массив приоритетов
	size_t size;
	size_t max_size;
public:
	Double_Priority() :pq(nullptr), index(nullptr), size(0), max_size(0) {}
	void push(double Val, int pr);
	void pop();
	double top();
	double back() { return pq [ size - 1]; };
	bool Empty() { return size == 0; }
};
void Double_Priority::push(double Val, int pr)
{
	if (size >= max_size) {
		++max_size;
		double* tmp = new double[max_size];
		int* tmp_ind = new int[max_size];
		for (int i = 0; i < size; ++i) {
			*(tmp + i) = *(pq + i);
			*(tmp_ind + i) = *(index + i);
		}
		delete[] pq;
		pq = tmp;
		delete[] index;
		index = tmp_ind;
	}
	*(pq + size) = Val;
	*(index + size) = pr;
	++size;
}

void Double_Priority::pop()
{
	size_t poz = 0;
	for (int i = 0; i < size; i++) {
		if (*(index + poz) < *(index + i)) {
			poz = i;
		}
	}
	--size;
	for (int i = poz; i < size; i++) {
		*(pq + i) = *(pq + i + 1);
		*(index + i) = *(index + i + 1);
	}
}

double Double_Priority::top()
{
	size_t poz = 0;
	for (int i = 0; i < size; i++) {
		if (*(index + poz) < *(index + i)) {
			poz = i;
		}
	}
	return *(pq + poz);
}