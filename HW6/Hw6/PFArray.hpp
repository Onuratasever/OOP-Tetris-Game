#ifndef PFARRAY_H
#define PFARRAY_H

#include <iostream>
#include <memory>

using namespace std;

namespace onur
{
	template<class T>
	class PFArray
	{
		public:

			class Iterator
			{
				public:
					Iterator();
					Iterator(T* ptr);
					Iterator(const Iterator& other);
					Iterator(Iterator &&rhv) noexcept; // Move constructor
					~Iterator();

					T& operator*()const{return *m_ptr;};
					T* operator ->(){return m_ptr;};
					Iterator& operator++() { m_ptr++; return *this; };
					Iterator operator++(int) { Iterator temp = *this; ++(*this); return temp; };
					Iterator& operator--() { m_ptr--; return *this; };
					Iterator operator--(int) { Iterator temp = *this; --(*this); return temp; };
					bool operator== (const Iterator& rhs) { return this->m_ptr == rhs.m_ptr; };
					bool operator!= (const Iterator& rhs) { return !(this->m_ptr == rhs.m_ptr); };
					Iterator& operator =(const Iterator& rhs){this->m_ptr = rhs.m_ptr; return (*this);};
					Iterator &operator=(Iterator &&rhv) noexcept
					{
						//cout << "\nMove assignment operator" << endl;
						if (this != &rhv)
						{
							m_ptr = rhv.m_ptr;

							rhv.m_ptr = nullptr;
						}
						return *this;
					}; // Move assignment operator


					int operator-(const Iterator& other){return (this->m_ptr - other.m_ptr);};

					int operator+(const Iterator& other){return (this->m_ptr + other.m_ptr);};

					friend bool operator<(const Iterator &lhs, const Iterator& rhs)
					{
						return (*lhs) < (*rhs);
					}

					friend Iterator operator+(const Iterator& l, int r)
					{
						return Iterator(l.m_ptr + r);
					}

					friend Iterator operator+(int l,const Iterator& r)
					{
						return Iterator(r.m_ptr + l);
					}

					friend Iterator operator-(const Iterator& l, int r)
					{
						return Iterator(l.m_ptr - r);
					}


					using value_type = T;
					using pointer = T *;
					using reference = T &;
					using difference_type = ptrdiff_t;
					using iterator_category = random_access_iterator_tag;
				private:
					T* m_ptr; 
			};

			PFArray( );
			PFArray(int capacityValue);
			PFArray(const PFArray<T>& pfaObject);// copy constructor
			PFArray(PFArray<T> &&other) noexcept; // Move constructor
			virtual ~PFArray( );

			void addElement(const T& element);
			int getCapacity( ) const;
			void clear( );
			bool empty( ) const;
			const int size() const{return used;};
			Iterator begin()const { return PFArray::Iterator(&(a.get()[0]));};
			Iterator end()const{ return PFArray::Iterator(&(a.get()[used])); };
			const Iterator cbegin(){ return PFArray::Iterator(&(a.get()[0]));};
			const Iterator cend(){ return PFArray::Iterator(&(a.get()[used]));};
			void print() const;
			void erase(const PFArray<T>::Iterator& element);

			PFArray<T> &operator=(PFArray<T> &&other) noexcept; // Move assignment operator
			T& operator[](int index); //index operator
			const T& operator[](int index) const;//index operator for const 
			PFArray<T>& operator =(const PFArray<T>& rightSide); //Assignment operator


		private:
			shared_ptr<T> a;
			int capacity;
			int used;

	};

}

#endif