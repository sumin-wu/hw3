#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack: private std::vector<T>
{
public:
    Stack(){}
    ~Stack(){}
    bool empty() const{
        return this->size()==0;//use derived
    }
    size_t size() const{
        return std::vector<T>::size();//use parent function
    }
    void push(const T& item){
        std::vector<T>::push_back(item);//use parent function
    }
    void pop(){
        if (this->empty())//use derived to check if its empty
        {
            throw std::underflow_error("stack is empty");
        }
        std::vector<T>::pop_back();//use parent to pop back
    }
      // throws std::underflow_error if empty
    const T& top() const{
        if (this->empty())
        {
            throw std::underflow_error("empty stack");
        }
        std::vector<T>::back();//do i use front o rback?
    } // throws std::underflow_error if empty
    // Add other members only if necessary
};


#endif