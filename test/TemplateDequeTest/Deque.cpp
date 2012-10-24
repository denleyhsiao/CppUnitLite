#include "Deque.h"

template <class T>
inline Deque<T>::Deque() : itsSize(0), itsCap(10)
{
	itsData = new T[itsCap];
}

template <class T>
inline Deque<T>::Deque(const Deque<T>& other) : itsSize(other.size()),
                                   itsCap(other.capacity())
{
	copy_data(other.itsData);
}

template <class T>
inline Deque<T>::~Deque()
{
	delete[] itsData;
}

template <class T>
inline int Deque<T>::capacity() const
{
	return itsCap;
}

template <class T>
inline int Deque<T>::size() const
{
	return itsSize;
}

template <class T>
inline void Deque<T>::push_back(const T& i)
{
	if (itsSize >= itsCap)
	{
		grow(0);
	}
	itsData[itsSize++] = i;
}

template <class T>
inline void Deque<T>::push_front(const T& i)
{
	itsSize++;
	grow(1);
	itsData[0] = i;
}

template <class T>
inline T& Deque<T>::pop_back()
{
	return itsData[--itsSize];
}

template <class T>
inline T Deque<T>::pop_front()
{
	T value = itsData[0];
	shrink();
	itsSize--;
	return value;
}

template <class T>
inline void Deque<T>::grow(int place)
{
	itsCap *= 2;
	array_copy(place);
}

template <class T>
inline void Deque<T>::array_copy(int place, int start)
{
	T* temp = new T[itsCap];
	array_copy(itsData, temp, start, place);
	delete [] itsData;
	itsData = temp;
}

template <class T>
inline void Deque<T>::array_copy(const T* source,
					  T* destination,
					  int source_start,
					  int destination_start)
{
	for (int i = 0; i <= itsSize; i++)
		destination[i + destination_start] = source[i + source_start];
}

template <class T>
inline void Deque<T>::shrink()
{
	array_copy(0, 1);
}

template <class T>
inline void Deque<T>::copy_data(int* data)
{
	itsData = new T[itsCap];
	array_copy(data, itsData);
}

template <class T>
inline Deque<T>& Deque<T>::operator=(const Deque<T>& d)
{
	if (this != &d)
	{
		itsCap = d.capacity();
		itsSize = d.size();
		delete [] itsData;
		copy_data(d.itsData);
	}
	return *this;
}