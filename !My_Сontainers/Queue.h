#pragma once
template<typename T>
class Queue {
	T* q;
	size_t size;//текущий размер
	size_t max_size;//максимальный
public:
	Queue() :q(nullptr), size(0), max_size(0) {}
	void push(T value);
	void pop();
	const T& front_show() { return q[0]; }
	const T& back_show() { return q[size - 1]; }
	bool Empty() { return size == 0; }
	size_t Size() { return size; }
	bool isFull()const { return size == max_size; }
};
template<typename T>
void Queue<T>::push(T value)
{
	if (size >= max_size) {
		++max_size;
		T* tmp = new T[max_size];
		for (int i = 0; i < size; ++i) {
			tmp[i] = q[i];
		}
		delete[] q;
		q = tmp;
	}
	q [size] = value;
	++size;
}
template<typename T>
void Queue<T>::pop()
{
	for (size_t i = 0; i < size - 1; ++i) {
		q [i] = q [i + 1];
	}
	--size;
}