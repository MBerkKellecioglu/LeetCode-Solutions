using namespace std;

template<typename T>
class node{
public:
    T data;
    node* prev;

    node(){
        this->prev = nullptr;
    }

    node(T d){
        this->data = d;
        this->prev = nullptr;
    }
};
