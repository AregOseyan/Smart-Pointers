#ifndef UNIQUE_PTRR_HPP
#define UNIQUE_PTRR_HPP

template <typename T>
class unique_ptrr
{
public:
  unique_ptrr() 
    : ptr(nullptr)
  { }

  unique_ptrr(T* ptr1)
    : ptr(ptr1)
  { }

  unique_ptrr(unique_ptrr&& other)
  {
    if (this->ptr) 
    { 
      delete this->ptr;
      this->ptr = nullptr;
    }
    this->ptr = other->ptr;
    other->ptr = nullptr;
  }

  ~unique_ptrr() 
  { 
    if (this->ptr) 
    { 
      delete this->ptr;
      this->ptr = nullptr;
    }
  }
  
  unique_ptrr(const unique_ptrr& other) = delete;
  unique_ptrr& operator=(const unique_ptrr& other) = delete;

public:
  T* operator->() { return this->ptr; }
  T& operator*() { return *(this->ptr); }

private:
  T* ptr; 
};

template <typename T>
class unique_ptrr<T[]>
{
public:
  unique_ptrr()
    : ptr(nullptr)
  { }

  unique_ptrr(T* ptr1)
    : ptr(ptr1)
  { }

  unique_ptrr(unique_ptrr&& other)
  {
    if (this->ptr)
    {
      delete[] this->ptr;
      this->ptr = nullptr;
    }
    this->ptr = other->ptr;
    other->ptr = nullptr;
  }
  
  ~unique_ptrr()
  {
    if (this->ptr)
    {
      delete[] this->ptr;
      this->ptr = nullptr;
    }
  }

  unique_ptrr(const unique_ptrr& other) = delete;
  unique_ptrr& operator=(const unique_ptrr& other) = delete;

public:
  T* operator->() { return this->ptr; }
  T& operator*() { return *(this->ptr); }
  T& operator[](int idx) 
  {
    if (idx < 0) { throw "Invalid index!"; }
    return *(this->ptr + idx);
  }

private:
  T* ptr;
};
#endif // UNIQUE_PTRR_HPP
