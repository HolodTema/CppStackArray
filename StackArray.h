#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include <iostream>
#include "stackArrayExceptions.h"

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
	StackArray(const StackArray<T>& other):
		capacity_(other.capacity_),
		size_(other.size_)
	{
		array_ = new T[capacity];

		try {
			for (int i = 0; i < size_; ++i) {
				array_[i] = other.array_[i];
			}
		}
		catch (const std::bad_alloc& e) {
			delete[] array;
		}
	}

	//move constructor
	StackArray(const StackArray<T>&& other):
		capacity_(other.capacity_),
		size_(other.size_),
		array_(other.array_)
	{
	
	}

	//copy assignment operator
	const StackArray<T>& operator=(const StackArray<T>& other) {
		if (&other == this) {
			return *this;
		}

		StackArray<T> stackArrayCopy = StackArray(other);
		swap(*this, stackArrayCopy);
		return *this;
	}

	//move assignment operator
	const StackArray<T>& operator=(const StackArray<T>&& other) noexcept {
		swap(*this, other);
		return *this;
	}

	~StackArray() {
		delete[] array_;
	}

	void push(const T& element) {
		if (size_ < capacity_) {
			array_[size_++] = element;
		}
		else {
			throw StackOverFlowException();
		}
	}
	
	const T& pop() {
		if (size_ > 0) {
			return array_[--size_];
		}
		else {
			throw StackUnderFlowException();
		}
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
		std::swap(capacity_, other.capacity_);
		std::swap(size_, other.size_);
		std::swap(array_, other.array_);
	}

};

template <typename T>
std::ostream& operator<<(std::ostream& os, const StackArray<T>& stackArray) {
	os << "head ";
	for (int i = 0; i < size_; ++i) {
		os << array_[i] << " ";
	}
	os << "tail\n";
}

#endif //STACK_ARRAY_H
