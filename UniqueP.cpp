#include <iostream>
#include <string>
#include <memory>
#include <utility>
using namespace std;

template <typename T>
class MyUniquePtr
{
    private:
    T* ptr;

    public:
    explicit MyUniquePtr(T* p = nullptr):ptr(p) {}
    ~MyUniquePtr() {delete ptr;}
    // Delete copy constructor and copy assignment
    MyUniquePtr(const MyUniquePtr& ) = delete;
    MyUniquePtr& operator =(const MyUniquePtr& ) = delete;
    //Move Constructor
    MyUniquePtr(MyUniquePtr&& other ) noexcept:ptr(other.ptr)
    {
        other.ptr = nullptr;
    }
    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept
    {
        if(this != &other)
        {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }
    T* operator->() const {return ptr;}
    T& operator*() const{ return *ptr;}
    // Get raw pointer
    T* get() const{ return ptr;}
    // Release ownership
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        return temp;
    }

    // Reset the pointer
    void reset(T* p = nullptr) {
        delete ptr;
        ptr = p;
    }
};

class Student {
public:
    void sayHello() {
        std::cout << "Hello from Student!\n";
    }
};

int main() {
    MyUniquePtr<Student> stuPtr(new Student());
    stuPtr->sayHello();

    MyUniquePtr<Student> stuPtr2 = std::move(stuPtr); // ✅ Move is allowed

    if (!stuPtr.get()) {
        std::cout << "stuPtr is now null after move.\n";
    }

    return 0;
}
