#include <iostream>

template<typename T>
class vector {
    T* set;
    int count;
    int size;
    void free();
    void copyFrom(const vector<T>&);
    void moveFrom(vector<T>&&);
    void addSpace();
    void moveMembersForward(int start_pos);
    void moveMembersBack(int start_pos);
public:
    const T& operator[](int index) const;
    T& operator[](int index);
    void popBack();
    void popAt(int pos);
    void pushAt(const T& member, int pos);
    void pushBack(const T& member);
    vector<T>();
    vector<T>(const vector<T>&);
    vector<T>(vector<T>&&);
    ~vector();
    vector<T>& operator=(const vector<T>&);
    vector<T>& operator=(vector<T>&&);
    bool empty() const;
    void erase();
    void swap(int pos1, int pos2);
    int getCount() const;
};

template<typename T>
int vector<T>::getCount() const {
    return count;
}

template<typename T>
void vector<T>::swap(int pos1, int pos2) {
    T temp = set[pos1];
    set[pos1] = set[pos2];
    set[pos2] = temp;
}

template<typename T>
void vector<T>::erase() {
    free();
}

template<typename T>
bool vector<T>::empty() const {
    return count == 0;
}

template<typename T>
const T& vector<T>::operator[](int index) const {
    return set[index];
}

template<typename T>
T& vector<T>::operator[](int index) {
    return set[index];
}

template<typename T>
void vector<T>::popAt(int pos) {
    moveMembersBack(pos);
}

template<typename T>
void vector<T>::moveMembersBack(int start_pos) {
    for (int i = start_pos; i < count; ++i)
        set[i] = set[i + 1];
    count--;
}

template<typename T>
void vector<T>::moveMembersForward(int start_pos) {
    if (count == size)
        addSpace();
    for (int i = count; i > start_pos; --i)
        set[i] = set[i - 1];
    count++;
}

template<typename T>
void vector<T>::free() {
    delete[] set;
    count = size = 0;
}

template<typename T>
void vector<T>::copyFrom(const vector<T> &vec) {
    count = vec.count;
    size = vec.size;
    set = new T[size];
    for (int i = 0; i < count; ++i)
        set[i] = vec.set[i];
}

template<typename T>
void vector<T>::moveFrom(vector<T> &&vec) {
    set = vec.set;
    vec.set = nullptr;
    count = vec.count;
    size = vec.size;
    vec.count = vec.size = 0;
}

template<typename T>
vector<T>::vector(vector<T> &&vec) {
    moveFrom(std::move(vec));
}

template<typename T>
vector<T>::vector(const vector<T> &vec) {
    copyFrom(vec);
}

template<typename T>
vector<T>::vector() {
    set = nullptr;
    count = size = 0;
}

template<typename T>
vector<T>::~vector() {
    free();
}

template<typename T>
vector<T> &vector<T>::operator=(vector<T> &&vec) {
    if (this != &vec) {
        free();
        moveFrom(std::move(vec));
    }
    return *this;
}

template<typename T>
vector<T> &vector<T>::operator=(const vector<T> &vec) {
    if (this != &vec) {
        free();
        copyFrom(vec);
    }
    return *this;
}

template<typename T>
void vector<T>::addSpace() {
    if (size == 0)
        size++;
    T* nSet = new T[size *= 2];
    for (int i = 0; i < count; ++i)
        nSet[i] = set[i];
    delete[] set;
    set = nSet;
}

template<typename T>
void vector<T>::pushBack(const T &member) {
    if (size == count)
        addSpace();
    set[count++] = member;
}

template<typename T>
void vector<T>::pushAt(const T &member, int pos) {
    moveMembersForward(pos);
    set[pos] = member;
}

template<typename T>
void vector<T>::popBack() {
    count--;
}

