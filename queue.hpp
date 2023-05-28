#include <iostream>

template<typename T>
class queue {
    T* set;
    int count;
    int size;
    void free();
    void copyFrom(const queue<T>&);
    void moveFrom(queue<T>&&);
    void addSpace();
    void moveMembersForward();
public:
    T dequeue();
    bool isEmpty() const;
    void enqueue(const T& member);
    queue<T>& operator=(const queue<T>&);
    queue<T>& operator=(queue<T>&&);
    queue<T>();
    queue<T>(const queue<T>&);
    queue<T>(queue<T>&&);
    ~queue();
};

template<typename T>
bool queue<T>::isEmpty() const {
    return count == 0;
}

template<typename T>
void queue<T>::moveMembersForward() {
    if (count == size)
        addSpace();
    for (int i = count; i > 0; --i)
        set[i] = set[i - 1];
}

template<typename T>
T queue<T>::dequeue() {
    return set[--count];
}

template<typename T>
void queue<T>::enqueue(const T &member) {
    if (count == size)
        addSpace();
    moveMembersForward();
    set[0] = member;
    count++;
}

template<typename T>
void queue<T>::free() {
    delete[] set;
    count = size = 0;
}

template<typename T>
void queue<T>::copyFrom(const queue<T> &vec) {
    count = vec.count;
    size = vec.size;
    set = new T[size];
    for (int i = 0; i < count; ++i)
        set[i] = vec.set[i];
}

template<typename T>
void queue<T>::moveFrom(queue<T> &&vec) {
    set = vec.set;
    vec.set = nullptr;
    count = vec.count;
    size = vec.size;
    vec.count = vec.size = 0;
}

template<typename T>
queue<T>::queue(queue<T> &&vec) {
    moveFrom(std::move(vec));
}

template<typename T>
queue<T>::queue(const queue<T> &vec) {
    copyFrom(vec);
}

template<typename T>
queue<T>::queue() {
    set = nullptr;
    count = size = 0;
}

template<typename T>
queue<T>::~queue() {
    free();
}

template<typename T>
queue<T> &queue<T>::operator=(queue<T> &&vec) {
    if (this != &vec) {
        free();
        moveFrom(std::move(vec));
    }
    return *this;
}

template<typename T>
queue<T> &queue<T>::operator=(const queue<T> &vec) {
    if (this != &vec) {
        free();
        copyFrom(vec);
    }
    return *this;
}

template<typename T>
void queue<T>::addSpace() {
    if (size == 0)
        size++;
    T* nSet = new T[size *= 2];
    for (int i = 0; i < count; ++i)
        nSet[i] = set[i];
    delete[] set;
    set = nSet;
}
