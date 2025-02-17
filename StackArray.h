#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>

template <typename T>
class StackArray {
public:

	StackArray(unsigned int capacity):
		capacity_(capacity),
		size_(0)
	{
		array_ = new T[capacity];
	}

	//copy constructor
	StackArray(const StackArray<T>& other) {

	}

	//move constructor
	StackArray(const StackArray<T>&& other) {

	}

	//copy assignment operator
	const StackArray<T>& operator=(const StackArray<T>& other) {

	}

	//move assignment operator
	const StackArray<T>& operator=(const StackArray<T>&& other) noexcept {

	}

	~StackArray() {

	}

	void push(const T& element) {

	}
	
	const T& pop() {

	}

	boolean isEmpty() const {
		return size_ == 0;
	}

	unsigned int getCapacity() const {
		return capacity_;
	}
	
	template <typename T1>
	friend std::ostream& operator<<(std::ostream& os, const StackArray&<T1> stackArray);

private:
	T* array_;
	unsigned int capacity_;
	unsigned int size_;

	void swap(const StackArray<T>& other) {

	}

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const StackArray<T>& stackArray) {
	for (int i = 0; i < size_; ++i) {
		os << array_[i] << " ";
	}
	os << "\n";
}

#endif //STACK_ARRAY_H
