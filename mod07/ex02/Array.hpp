#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array
{
	private:
		T *_array;
		unsigned int _size;

	public:
		Array() {
			_array = new T[0];
			_size = 0;
		}

		Array(unsigned int n) {
			_array = new T[n];
			_size = n;
		}

		Array(Array &cpy) {
			this->_array = NULL;
			*this = cpy;	
		}

		Array &operator=(Array &cpy) {

			if (this->_array != NULL)
				delete [] this->_array;
			if (cpy.size() != 0) {
				this->_size = cpy.size();
				this->_array = new T[this->_size];
				for (unsigned int i = 0; i < this->_size; i++)
					this->_array[i] = cpy._array[i];
			}
			return *this;
		}	

		T &operator[](unsigned int index) {
			if (index >= _size)
				throw Array<T>::InvalidIndexException();
			return (_array[index]);
		}

		unsigned int size() const {
			return _size;
		}

		void printArray(std::string name) {
			std::cout << name << ": ";
			for (unsigned int i = 0; i < _size; i++)
				std::cout << _array[i];
			std::cout << std::endl;
		}

		~Array() {
			if (_array != NULL)
				delete[] _array;
		}

		class InvalidIndexException : public std::exception
		{
			public:
				const char *what() const throw() {
					return "Invalid index";
				}
		};	
};

#endif
