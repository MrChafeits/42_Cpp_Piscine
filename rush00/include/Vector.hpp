#ifndef VECTOR_HPP
#define VECTOR_HPP

template <typename T> class Vector {
private:
  T *_arr;
  int _capacity;
  int _size;

public:
  Vector();
  Vector(Vector &v);
  Vector &operator=(Vector &v);
  ~Vector();
  int size();
  int capacity();
  void reserve(int val);
  void shrinkToFit();
  bool emtpy();

  T &operator[](int val);
  void push_back(T val);
  void pop_back();
  void erase(int idx);
  void insert(int idx, T &val);
  void clear();
};

// **vector pointer type!!
template <typename T> class Vector<T *> {
private:
  T **_arr;
  int _capacity;
  int _size;

public:
  Vector();
  Vector(Vector &v);
  Vector &operator=(Vector &v);
  ~Vector();
  int size();
  int capacity();
  void reserve(int val);
  void shrinkToFit();
  bool emtpy();

  T *operator[](int val);
  void push_back(T *val);
  void pop_back();
  void erase(int idx);
  void insert(int idx, T *val);
  void clear();
};

template <typename T>
Vector<T>::Vector() : _arr(new T[8]()), _capacity(8), _size(0) {}

template <typename T> Vector<T>::Vector(Vector &v) {
  _arr = new T[v.size()]();
  for (int i = 0; i < v.size(); i++) {
    _arr[i] = v[i];
  }
  _size = v.size();
  _capacity = v.capacity();
}

template <typename T> Vector<T> &Vector<T>::operator=(Vector &v) {
  delete _arr;
  _arr = new T[v.size()]();
  for (int i = 0; i < v.size(); i++) {
    _arr[i] = v[i];
  }
  _size = v.size();
  _capacity = v.capacity();
  return (*this);
}

template <typename T> Vector<T>::~Vector() { delete _arr; }

template <typename T> int Vector<T>::size() { return _size; }

template <typename T> int Vector<T>::capacity() { return _capacity; }

template <typename T> void Vector<T>::reserve(int val) {
  if (val <= _capacity)
    return;
  T *newArr = new T[val]();
  for (int i = 0; i < _size; i++) {
    newArr[i] = _arr[i];
  }
  delete _arr;
  _arr = newArr;
  _capacity = val;
}

template <typename T> void Vector<T>::shrinkToFit() {
  if (_size == _capacity)
    return;
  T *newArr = new T[_size]();
  for (int i = 0; i < _size; i++) {
    newArr[i] = _arr[i];
  }
  delete _arr;
  _arr = newArr;
}

template <typename T> bool Vector<T>::emtpy() { return _size == 0; }

template <typename T> T &Vector<T>::operator[](int val) {
  if (val < 0 || val >= _size)
    throw "out of index errr";
  return _arr[val];
}

template <typename T> void Vector<T>::push_back(T val) {
  if (_size == _capacity)
    reserve(_capacity * 2);
  _arr[_size] = val;
  _size++;
}

template <typename T> void Vector<T>::pop_back() { _size--; }

template <typename T> void Vector<T>::erase(int idx) {
  if (idx < 0 || idx >= _size)
    throw "out of index errr";
  for (int i = idx + 1; i < _size; i++) {
    _arr[i - 1] = _arr[i];
  }
  _size--;
}

template <typename T> void Vector<T>::insert(int idx, T &val) {
  if (idx < 0 || idx >= _size)
    throw "out of index errr";
  if (_size == _capacity)
    reserve(_capacity * 2);
  for (int i = _size - 1; i >= idx; i--) {
    _arr[i + 1] = _arr[i];
  }
  _arr[idx] = val;
}

template <typename T> void Vector<T>::clear() { _size = 0; }

template <typename T>
Vector<T *>::Vector() : _arr(new T *[8]()), _capacity(8), _size(0) {}

template <typename T> Vector<T *>::Vector(Vector &v) {
  _arr = new T *[v.size()]();
  for (int i = 0; i < v.size(); i++) {
    _arr[i] = new T(*v[i]);
  }
  _size = v.size();
  _capacity = v.capacity();
}

template <typename T> Vector<T *> &Vector<T *>::operator=(Vector &v) {
  for (int i = 0; i < _size; i++) {
    delete _arr[i];
  }
  delete _arr;
  _arr = new T *[v.size()]();
  for (int i = 0; i < v.size(); i++) {
    _arr[i] = new T(*v[i]);
  }
  _size = v.size();
  _capacity = v.capacity();
  return (*this);
}

template <typename T> Vector<T *>::~Vector() {
  for (int i = 0; i < _size; i++) {
    delete _arr[i];
  }
  delete _arr;
}

template <typename T> int Vector<T *>::size() { return _size; }

template <typename T> int Vector<T *>::capacity() { return _capacity; }

template <typename T> void Vector<T *>::reserve(int val) {
  if (val <= _capacity)
    return;
  T **newArr = new T *[val]();
  for (int i = 0; i < _size; i++) {
    newArr[i] = _arr[i];
  }
  delete _arr;
  _arr = newArr;
  _capacity = val;
}

template <typename T> void Vector<T *>::shrinkToFit() {
  if (_size == _capacity)
    return;
  T **newArr = new T *[_size]();
  for (int i = 0; i < _size; i++) {
    newArr[i] = _arr[i];
  }
  delete _arr;
  _arr = newArr;
}

template <typename T> bool Vector<T *>::emtpy() { return _size == 0; }

template <typename T> T *Vector<T *>::operator[](int val) {
  if (val < 0 || val >= _size)
    throw "out of index errr";
  return _arr[val];
}

template <typename T> void Vector<T *>::push_back(T *val) {
  if (_size == _capacity)
    reserve(_capacity * 2);
  _arr[_size] = val;
  _size++;
}

template <typename T> void Vector<T *>::pop_back() {
  delete _arr[_size - 1];
  _size--;
}

template <typename T> void Vector<T *>::erase(int idx) {
  if (idx < 0 || idx >= _size)
    throw "out of index errr";
  delete _arr[idx];
  for (int i = idx + 1; i < _size; i++) {
    _arr[i - 1] = _arr[i];
  }
  _size--;
}

template <typename T> void Vector<T *>::insert(int idx, T *val) {
  if (idx < 0 || idx >= _size)
    throw "out of index errr";
  if (_size == _capacity)
    reserve(_capacity * 2);
  for (int i = _size - 1; i >= idx; i--) {
    _arr[i + 1] = _arr[i];
  }
  _arr[idx] = val;
}

template <typename T> void Vector<T *>::clear() { _size = 0; }

#endif /* VECTOR_HPP */
