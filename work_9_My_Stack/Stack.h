#pragma once

template<typename T>
class Stack {
	T* st;
	const size_t size;
	size_t cur_size;
public:
	Stack(int s = 10) :size(s), cur_size(0) {
		st = new T[size];
	}
	~Stack() { delete[] st; }
	void push(T value);
	void pop();
	T show();
	bool isFull() { return cur_size == size; }//size
	bool empty() { return cur_size == 0; }
};
template<typename T>
void Stack<T>::push(T value)//Stroka value
{
	if (cur_size == size)
		return;// можно использовать throw()
//	*(st + cur_size) = value;//operator=(const Stroka&)
	st[cur_size] = value;//operator=(const Stroka&)
	cur_size++;
}
template<typename T>
void Stack<T>::pop()
{
	if (cur_size == 0)
		return;// можно использовать throw()
	--cur_size;
}
template<typename T>
T Stack<T>::show()//copy consruct
{
	//return cur_size ? *(st + cur_size - 1) : 0;
	return cur_size ? st [cur_size - 1] : 0;
}
