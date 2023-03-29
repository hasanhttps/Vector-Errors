#pragma once


template<typename Type>
class Vector {
	Type* _array = nullptr;
	int _size = 0;
	size_t _capacity = 15;
public:

	// Constructors

	Vector();
	Vector(size_t capacity);

	// Operators

	Type& operator[](int index);
	Type& operator()(int index);
	Vector& operator++();
	Vector& operator++(int);
	Vector operator+(const Vector& other);
	bool operator==(const Vector& other);
	bool operator!=(const Vector& other);

	friend ostream& operator<<(ostream& print, const Vector& other) {
		cout << "{ ";
		for (int i = 0; i < other._size; i++) if (i != other._size - 1) cout << other._array[i] << ", "; else cout << other._array[i];
		cout << " }" << endl;
		return print;
	}

	friend istream& operator>>(istream& input, Vector& other) {
		long long int size = 0;
		cout << "Enter the size of count of array : ";
		cin >> size;
		if (size < 0) assert(!"Size cannot be negative!");
		other._size = size;
		if ((other._size / 15) + 1 > (other._capacity / 15)) other._capacity = (other._size / 15 + 1) * 15;
		delete[] other._array;
		Type* newArray = new Type[other._capacity];
		cout << "Please enter the elements of array;" << endl;
		Type element;
		for (int i = 0; i < other._size; i++) {
			cout << i + 1 << " : ";
			cin >> element;
			newArray[i] = element;
		}
		other._array = newArray;
		return input;

	}

	// Functions

	void print();
	Vector& push_back(const Type value);
	Vector& push_front(const Type value);
	Vector& pop_back();
	Vector& pop_front();
	void delete_by_index(int index);
	void insert_by_index(const int index, const Type element);
	int find(const Type element);
	int rfind(const Type element);
	//// reverse true gonderilse, tersine sort olunsun.
	void sort(bool reverse = false);
	size_t len();
	size_t capacity();
	void insert(size_t index, const Type data);
	void remove(const Type data);
	void clear();
	int& first();
	int& last();
	void shuffle();
	const int* getRange(size_t min, size_t max);

	// Destructor

	~Vector();
};


// User Defined Error


class OutOfRange : public exception {
private:
	string message;
	int line;
	const char* time;
	const char* file;
public:
	OutOfRange(string message = "Out Of Range!", int line = 0, const char* time = "", const char* file = "") :
		message(message), line(line) {
		this->time = time;
		this->line = line;
	}

	virtual string what() {
		return message;
	}
};