

#ifndef SMARTPOINTERS_SAFEPTR_H
#define SMARTPOINTERS_SAFEPTR_H

#include <iostream>

template <class T>
class SharedPtr {
public:
    explicit SharedPtr(T* ptr = NULL);
    ~SharedPtr();
    template <class U>
    SharedPtr(SharedPtr<U>& other);
    template <class U>
    SharedPtr<T>& operator =(SharedPtr<U>& other);

    T& operator *() const;
    T* operator ->() const;
    T* getPtr() const;
    size_t getCount();
    operator bool() const; // unsafe operator

private:
    T *m_ptr;
    size_t * m_count;

    void deletePtr();
    friend class TestSafePtr;
    template <class U> friend class SharedPtr;
};


template <class T>
SharedPtr<T>::SharedPtr(T* ptr):m_ptr(ptr), m_count(NULL)
{
    m_count = new size_t(1);
}

template <class T>
SharedPtr<T>::~SharedPtr()
{
    deletePtr();
}

template <class T>
template <class U>
SharedPtr<T>::SharedPtr(SharedPtr<U>& other)
{
    m_ptr = other.m_ptr;
    m_count = other.m_count;
    (*m_count) ++;
}

template <class T>
template <class U>
SharedPtr<T>& SharedPtr<T>::operator =(SharedPtr<U>& other)
{
    if ((void*)this == (void*)&other) {
        return *this;
    }

    deletePtr();
    m_ptr = other.m_ptr;
    m_count = other.m_count;
    (*m_count) ++;

    return *this;
}

template <class T>
T& SharedPtr<T>::operator *() const
{
    return *m_ptr;
}

template <class T>
T* SharedPtr<T>::operator ->() const
{
    return m_ptr;
}

template <class T>
T* SharedPtr<T>::getPtr() const
{
    return m_ptr;
}

template <class T>
size_t SharedPtr<T>::getCount()
{
    return *m_count;
}

template <class T>
SharedPtr<T>::operator bool() const
{
    return m_ptr != NULL;
}

template<class T>
void SharedPtr<T>::deletePtr() {
    *m_count --;

    if(!*m_count)
    {
        delete (m_ptr);
        m_ptr = NULL;
    }
}


#endif //SMARTPOINTERS_SAFEPTR_H
