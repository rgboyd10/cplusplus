#include <iostream>
#include <cassert>
#include <stdexcept>

class IndexOutOfBoundsException{};

class IntArray
{
	private:
		int* m_ptr{nullptr};
		int m_size{0};

	public:
		//declaring the default constructor
		IntArray() = default;

		explicit IntArray(int size)
		{
			if(size != 0)
			{
				m_ptr = new int[size]{};
				m_size = size;
			}
		}
		
		~IntArray()
		{
			delete[] m_ptr;
		}

		int Size() const //const allows for read only properties in the method.
		{
			return m_size;
		}

		bool IsEmpty() const
	       	{
			return (m_size == 0);
		}

		int& operator[](int index)
		{
			if(!IsValidIndex(index))
			{
				throw IndexOutOfBoundsException{};
			}
			return m_ptr[index];
		}

		int operator[](int index) const
		{
			if(!IsValidIndex(index))
			{
				throw IndexOutOfBoundsException{};
			}
			return m_ptr[index];
		}

		bool IsValidIndex(int index) const
		{
			return (index >= 0) && (index < m_size);
		}
};

int main()
{
	using std::cout;
	using std::cin;

	try
	{
		IntArray a{10};
		for(int i = 0; i < a.Size(); i++)
		{
			a[i] = (i+1)*10;
		}

		cout << "Array elements: ";
		for(int i = 0; i < a.Size(); i++)
		{
			cout << a[i] << ' ';
		}

		cout << '\n';

		cout << "Array size " << a.Size() << "\n";
		cout << "Please enter an array index: ";
		int index{};
		cin >> index;

		cout << "The element at index " << index << " is " << a[index] << '\n';

	}

	catch(const IndexOutOfBoundsException& e)
	{
		cout << "\n *** ERROR: Invalid array index!! \n";
	}

	
/*
	IntArray a{3};
	cout << "Setting a[0] = 10 \n";
	a[0] = 10;
	cout << "a[0] is " << a[0] << '\n'; 
*/

/*
	cout << "Creating an empty array.\n";
	IntArray a{};

	cout << "a.Size() is " << a.Size() << '\n';

	//assert checks conditions at runtime
	assert(a.IsEmpty());

	cout << "---------------------------------\n";
	cout << "Creating an array containing 10 elements.\n";
	IntArray b{10};
	cout << "b.Size is " << b.Size() << '\n';
	assert(!b.IsEmpty());
*/
	}
