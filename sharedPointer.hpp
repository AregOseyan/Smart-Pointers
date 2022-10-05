#ifndef SHARED_POINTER_HPP
#define SHARED_POINTER_HPP

template <typename T>
class shared_pointer
{
public:
  shared_pointer()
    : ptr(nullptr)
    , count(new unsigned int(0))
  { }

  shared_pointer(T* ptr1)
    : ptr(ptr1)
    , count(new unsigned int(1))
  { }

  shared_pointer(shared_pointer&& other)
  {
    this->ptr = other.ptr;
    this->count = other.count;
    other.ptr = nullptr;
    other.count = nullptr;
  }

  shared_pointer(const shared_pointer& other)
  {
    this->ptr = other.ptr;
    this->count = other.count;
    if (other.ptr) { (*this->count)++; }
  }

public:
  shared_pointer& operator=(const shared_pointer& other)
  {
    this->ptr = other.ptr;
    this->count = other.count;
    if (other.ptr) { (*this->count)++; } 
  }

  T* operator->() { return this->ptr; }
  T& operator*() { return *(this->ptr); }

  unsigned int getCount() const { return *(this->count); }

private:
  T* ptr;
  unsigned int* count;
};
#endif // SHARED_POINTER_HPP
