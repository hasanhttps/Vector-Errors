#pragma once


template<typename Type>
Vector<Type>::Vector() {
	_array = new Type[_capacity];
}

template<typename Type>
Vector<Type>::Vector(size_t capacity) {
	if (_capacity < 15) {
		_array = new Type[_capacity];
		return;
	}
	_capacity = capacity;
	_array = new Type[_capacity];
}

template<typename Type>
void Vector<Type>::print() {
	cout << "{ ";
	for (int i = 0; i < _size; i++) if (i != _size - 1) cout << _array[i] << ", "; else cout << _array[i];
	cout << " }" << endl;
}


template<typename Type>
Type& Vector<Type>::operator[](int index) {
	if (index > _size) { // User Defined error
		try {
			throw OutOfRange("Index out of Range !");
		}
		catch (OutOfRange& ex) {
			cout << ex.what() << endl;
			throw;
		}
	}
	if (index < 0) {
		try {
			throw OutOfRange("Index can't be negative");
		}
		catch (OutOfRange& ex) {
			cout << ex.what() << endl;
			throw;
		}
	}
	return _array[index];
}

template<typename Type>
Type& Vector<Type>::operator()(int index) {
	if (index > _size) { // User Defined error
		try {
			throw OutOfRange("Index out of Range !");
		}
		catch (OutOfRange& ex) {
			cout << ex.what() << endl;
			throw;
		}
	}
	if (index < 0) {
		try {
			throw OutOfRange("Index can't be negative");
		}
		catch (OutOfRange& ex) {
			cout << ex.what() << endl;
			throw;
		}
	}
	return _array[index];
}

template<typename Type>
Vector<Type>& Vector<Type>::operator++() {
	for (int i = 0; i < _size; i++) ++_array[i];
	return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::operator++(int) {
	for (int i = 0; i < _size; i++) _array[i]++;
	return *this;
}

template<typename Type>
Vector<Type> Vector<Type>::operator+(const Vector& other) {
	int len = _size + other._size;
	Vector newVector(((_size + other._size) / 15 + 1) * 15);
	newVector._size = len;
	for (int i = 0; i < len; i++) {
		if (i < _size) newVector[i] = _array[i];
		else newVector[i] = other._array[i - _size];
	}
	return newVector;
}

template<typename Type>
bool Vector<Type>::operator==(const Vector& other) {
	bool status = true;
	if (_size == other._size) {
		for (int i = 0; i < _size; i++) {
			if (other._array[i] != _array[i]) status = false;
		}if (status) return true;
	}return false;
}

template<typename Type>
bool Vector<Type>::operator!=(const Vector& other) {
	bool status = true;
	if (_size == other._size) {
		for (int i = 0; i < _size; i++) {
			if (other._array[i] != _array[i]) status = false;
		}if (status) return false;
	}return true;
}

template<typename Type>
Vector<Type>& Vector<Type>::push_back(const Type value) {
	if (_capacity == _size++) _capacity += 15;
	Type* newarrey = new Type[_capacity];
	for (int i = 0; i < _size; i++) newarrey[i] = _array[i];
	newarrey[_size - 1] = value;
	_array = newarrey;
	return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::push_front(const Type value) {
	if (_capacity == _size++) _capacity += 15;
	Type* newarrey = new Type[_capacity];
	newarrey[0] = value;
	for (int i = 1; i < _size; i++) newarrey[i] = _array[i - 1];
	_array = newarrey;
	return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::pop_back() {
	_size--;
	Type* newarrey = new Type[_capacity];
	for (int i = 0; i < _size; i++) newarrey[i] = _array[i + 1];
	_array = newarrey;
	return *this;
}

template<typename Type>
Vector<Type>& Vector<Type>::pop_front() {
	_size--;
	Type* newarrey = new Type[_capacity];
	for (int i = 0; i < _size; i++) newarrey[i] = _array[i];
	_array = newarrey;
	return *this;
}

template<typename Type>
void Vector<Type>::delete_by_index(int index) {
	if (index > _size) {
		try {
			throw exception("Index out of Range !");
		}
		catch (const exception& ex) {
			cout << ex.what() << endl;
			return;
		}
	}
	if (index < 0) {
		try {
			throw exception("Index out of Range !");
		}
		catch (...) {
			cout << "Index out of Range !" << endl;
			return;
		}
	}
	Type* newarrey = new Type[_capacity];
	for (int i = 0, ind = 0; i < _size; i++) {
		if (i != index) newarrey[ind++] = _array[i];
	}_size--;
	_array = newarrey;
}

template<typename Type>
void Vector<Type>::insert_by_index(const int index, const Type element) {
	if (index > _size) { // User Defined error
		try {
			throw OutOfRange("Index out of Range !");
		}
		catch (OutOfRange& ex) {
			cout << ex.what() << endl;
			throw;
		}
	}
	if (index < 0) {
		try {
			throw OutOfRange("Index can't be negative");
		}
		catch (OutOfRange& ex) {
			cout << ex.what() << endl;
			throw;
		}
	}
	if (_capacity == _size++) _capacity += 15;
	Type* newarrey = new Type[_capacity];
	for (int i = 0, ind = 0; i < _size; i++) {
		if (i != index) newarrey[i] = _array[ind++];
		else newarrey[i] = element;
	}
	_array = newarrey;
}

template<typename Type>
int Vector<Type>::find(const Type element) {
	for (int i = 0; i < _size; i++) {
		if (_array[i] == element) {
			return i;
		}
	}return -1;
}

template<typename Type>
int Vector<Type>::rfind(const Type element) {
	for (int i = _size - 1; i >= 0; i--) {
		if (_array[i] == element) {
			return i;
		}
	}return -1;
}
//// reverse true gonderilse, tersine sort olunsun.

template<typename Type>
void Vector<Type>::sort(bool reverse) {
	int key, j;
	for (int i = 1; i < _size; i++) {
		key = _array[i];
		j = i - 1;
		if (reverse) {
			while (j >= 0 && _array[j] < key) {
				_array[j + 1] = _array[j];
				j -= 1;
			}_array[j + 1] = key;
		}
		else {
			while (j >= 0 && _array[j] > key) {
				_array[j + 1] = _array[j];
				j -= 1;
			}_array[j + 1] = key;
		}
	}
}

template<typename Type>
size_t Vector<Type>::len() { return _size; }

template<typename Type>
size_t Vector<Type>::capacity() { return _capacity; }

template<typename Type>
void Vector<Type>::insert(size_t index, const Type data) {
	for (int i = 0; i < _size; i++) if (i == index) _array[i] = data;
}

template<typename Type>
void Vector<Type>::remove(const Type data) {
	if (_size > 0) _size--;
	Type* newarrey = new Type[_capacity];
	for (int i = 0, ind = 0; i < _size + 1; i++) {
		if (_array[i] != data) newarrey[ind++] = _array[i];
	}
}

template<typename Type>
void Vector<Type>::clear() {
	delete[] _array;
	_array = new Type[_capacity];
	_size = 0;
}

template<typename Type>
int& Vector<Type>::first() { return _array[0]; }

template<typename Type>
int& Vector<Type>::last() { return _array[_size - 1]; }

template<typename Type>
void Vector<Type>::shuffle() {
	srand(time(0));
	int index1, index2;
	for (int i = 0; i < _size / 2; i++) {
		index1 = 0, index2 = 0;
		index1 = rand() % _size;
		while (index2 == index1) {
			index2 = rand() % _size;
		}int temp = _array[index1];
		_array[index1] = _array[index2];
		_array[index2] = temp;
	}
}

template<typename Type>
const int* Vector<Type>::getRange(size_t min, size_t max) {
	int* range = new int[max - min];
	for (int i = min, ind = 0; i < max; i++) range[ind++] = _array[i];
	cout << "{ ";
	for (int i = 0; i < max; i++) if (i != max - 1) cout << range[i] << ", "; else cout << range[i];
	cout << " }" << endl;
	return range;
}

template<typename Type>
Vector<Type>::~Vector() {
	delete[] _array;
}