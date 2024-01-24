#include "PFArray.hpp"
#include <iostream>
#include <memory>

using namespace std;

namespace onur
{
	/*No parameter Iterator constructor*/
	template <class T>
	PFArray<T>::Iterator::Iterator()
	{
		m_ptr = nullptr;
	}

	/*One parameter Iterator constructor*/
	template <class T>
	PFArray<T>::Iterator::Iterator(T* ptr)
	{
		m_ptr = ptr;
	}

	/*
		Destructor
		No need to delete somewhere
		It just assign nullptr
	*/
	template <class T>
	PFArray<T>::Iterator::~Iterator()
	{
		m_ptr = nullptr;
	}

	/*Copy Iterator constructor*/
	template <class T>
	PFArray<T>::Iterator::Iterator(const Iterator& other)
	{
		//cout << "\nCopy constructor" << endl;

		m_ptr = other.m_ptr;
	}

	// move constructor
	template <class T>
	PFArray<T>::Iterator::Iterator(Iterator && rhv) noexcept
	{
		//cout << "\nMove constructor" << endl;

		m_ptr = rhv.m_ptr;

		rhv.m_ptr = nullptr;
	}

	// copy assignment operator
	template <class T>
	PFArray<T>& PFArray<T>::operator=(const PFArray &other)
	{
		int i;
		if(this == &other)
			return *this;
		else
		{
			used = other.used;
			capacity = other.capacity;
			a = nullptr;
			a = shared_ptr<T>(new T[other.capacity]);
			for (i = 0; i < used; i++)
			{
				a.get()[i] = other.a.get()[i];
			}
		}
		return *this;
	}

	

	// move constructor
	template <class T>
	PFArray<T>::PFArray(PFArray &&other) noexcept
	{
		//cout << "\nMove constructor" << endl;

		a = other.a;
		used = other.used;
		capacity = other.capacity;

		other.capacity = 0;
		other.used = 0;
		other.a = nullptr;
	}

	// move assignment operator
	template <class T>
	PFArray<T>& PFArray<T>::operator=(PFArray &&other) noexcept
	{
		//cout << "\nMove assignment operator" << endl;
		if (this != &other)
		{
			a = other.a;
			used = other.used;
			capacity = other.capacity;

			other.capacity = 0;
			other.a = nullptr;
			other.used = 0;
		}
		return *this;
	}

	

	/*
		No parameter PFArray constructor
		It initializes capacity 50, used 0
	*/
	template <class T>
	PFArray<T>::PFArray() :capacity(50), used(0)
	{
		a =shared_ptr<T>(new T[capacity]);
	}
	
	/*
		One parameter Constructor
		It initializes Capacity with given parameter and used 0
	*/
	template<class T>
	PFArray<T>::PFArray(int capacityValue) :capacity(capacityValue), used(0)
	{
		a = shared_ptr<T>(new T[capacity]);
	}
	
	/*  
		PFArray copy constructor
	*/
	template<class T>
	PFArray<T>::PFArray(const PFArray<T>& pfaObject)
		:capacity(pfaObject.getCapacity()), used(pfaObject.size())
	{
		a = shared_ptr<T>(new T[capacity]);

		for(int i = 0; i < used; i++)
			a.get()[i] = pfaObject.a.get()[i];
	}
	
	/* 
		It takes one parameter which is element that user want to add to array 
		It controls used and capacity, if capacity is not enough it increases capacity 50
		It add element last index of the array	
	*/
	template<class T>
	void PFArray<T>::addElement(const T& element)
	{
		int i;
		if(used >= capacity)
		{
			cout << "Attempt to exceed capacity in PFArray. Capacity increased 50.\n";
			capacity += 50;
			shared_ptr<T> temp;
			temp = shared_ptr<T>(new T[used]);
			for(i=0; i<used; i++)
				temp.get()[i] = a.get()[i];
			a = shared_ptr<T>(new T[capacity]);
			for(i=0; i<used; i++)
				a.get()[i] = temp.get()[i];
		}

		a.get()[used] = element;
		used++;
	}
	
	/*It return capacity*/
	template<class T>
	int PFArray<T>::getCapacity() const
	{
		return capacity;
	}
	
	/* Resets the number used to zero, effectively emptying the array. */
	template<class T>
	void PFArray<T>::clear()
	{
		used = 0;
	}

	/*
		It control used
		If it is zero it returns true
		Else false
	*/
	template<class T>
	bool PFArray<T>::empty() const
	{
		if(used == 0)
			return true;
		else
			return false;
	}
	
	/* If boundries are ok it returns context of index. */
	template<class T>
	T& PFArray<T>::operator[](int index)
	{
		if(index >= used)
		{
			throw 12;
		}

		return a.get()[index];
	}

	/* If boundries are ok it returns context of index. */
	template<class T>
	const T& PFArray<T>::operator[](int index) const
	{
		if(index >= used)
		{
			throw 12;			
		}

		return a.get()[index];
	}
	  
	/*
		Destructor
		Used becomes 0
		It does  not delete anything because shared_ptr does it.
	*/
	template<class T>
	PFArray<T>::~PFArray()
	{
		used = 0;
	}

	/*
		It prints array by using iterators
	*/
	template <class T>
	void PFArray<T>::print() const
	{
		for(auto p = begin(); p!= end(); p++)
			cout << *p << " ";
		cout << endl;
	}

	/*
		It delete element which is iterator pointed
	*/
	template <class T>
	void PFArray<T>::erase(const PFArray<T>::Iterator& element)
	{
		PFArray<T>::Iterator go;
		PFArray<T>::Iterator on;

		int i, k;
		T* temp1;
		T* temp2;
		temp1 = new T[capacity];
		temp2 = new T[capacity];
		for(go=this->begin(), i=0; go != element; i++, go++)
		{
			temp1[i] = *go;
		}

		go++;
		for(k=0; go != this->end(); k++, go++)
		{
			temp2[k] = *go;
		}
		used -= 1;

		for(k=0; k<i; k++)
		{
			a.get()[k] = temp1[k];
		}
		for(i=0; i<used-k; i++)
		{
			a.get()[i + k] = temp2[i]; 
		}

		delete[] temp1;
		delete[] temp2;

		temp1 = nullptr;
		temp2 = nullptr;
	}

}
