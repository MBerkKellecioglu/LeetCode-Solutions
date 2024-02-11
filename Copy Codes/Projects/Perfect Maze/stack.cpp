#include"node.cpp"
#include<iostream>
#include"cell.cpp"

using namespace std;

template<typename T>
class stack{
private:
    node<T> *_top;
    int _size;

public:
    
    stack(){
        _top = nullptr;
        _size = 0;
    }

    void push(T data){
        node<T> *new_element = new node<T>(data);

        new_element->prev = _top;

        _top = new_element;

        _size++;
    }

    void pop(){
        if(_top != nullptr){
            node<T> *deleted_element;

            deleted_element = _top;

            _top = _top->prev;

            free(deleted_element);

            if(_size > 0) _size--;
        }
    }

    bool empty(){
        return _top == nullptr;
    }

    T top(){
        if(_top) return _top->data;
    }

    int size(){
        return _size;
    }

};