#include<iostream>

using namespace std;

template<typename num_type>
struct Node{
    num_type data = 0;
    Node *next = nullptr;
    Node *prev = nullptr;
};

template<typename num_type>
class List{
    Node<num_type> *first = nullptr;
    num_type size = 0;
    Node<num_type> *last = nullptr;
    Node<num_type> *cursor = nullptr;
    public:
    
    void new_size(num_type siz_);
    // int get_size(){
    //     return size;
    // }
    bool is_empty() const{
    if (first == nullptr){
        return true;
    }
    return false;
}

    template<typename type> friend istream& operator>>(istream& in, List<type>& conc);
    template<typename type> friend ostream& operator<<(ostream& out, const List<type>& conc);
    void add_el_ahead(num_type num);
    void add_el_back(num_type num);
    void pop_first();
    void pop_last();
    void add_bef_cur(num_type num);
    void pop_curs_nod();
    void move_left();
    void move_right();
};

template<typename num_type>
void List<num_type>::move_right(){
    if(cursor->next  == nullptr){
        cout << "\nWe can't move right, try again :(\n";
        return;
    }
    cursor = cursor->next;
}

template<typename num_type>
void List<num_type>::move_left(){
    if(cursor->prev  == nullptr){
        cout << "\nWe can't move left, try again :(\n";
        return;
    }
    cursor = cursor->prev;
}

template<typename num_type>
void List<num_type>::pop_curs_nod(){
    if (is_empty()){
        cout << "\n-No items to delete-\n";
        return;
    }
    if (first->next == nullptr) {
        delete first;
        delete last;
        last = nullptr;
        first = nullptr;
        cursor = nullptr;
        size --;
        return;
    }
    Node<num_type> *it = cursor;
    if ( cursor->next != nullptr && cursor->prev != nullptr ){
        cursor = cursor->next;
        it->prev->next = cursor;
        cursor->prev = it->prev;
    } else if ( cursor->prev == nullptr && cursor->next != nullptr){
        first = first->next;
        cursor = cursor->next;
        delete it;
        cursor->prev = nullptr;
    }else {
        last = last -> prev;
        cursor = cursor->prev;
        cursor->next = nullptr;
        delete it;
    }
    size--;
}

template<typename num_type>
void List<num_type>::add_bef_cur(num_type num){
    if (is_empty()){
        cout << "\nWe recommend using the 2 or 3.\nList is empty\n";
        return;
    }
    if (cursor->prev == nullptr){
        Node<num_type> *it = new Node<num_type>;
        it->data = num;
        it->next = cursor;
        cursor->prev = it;
        first = it;
        size++;
        return;
    }
    Node<num_type> *it = cursor->prev;
    Node<num_type> *new_el = new Node<num_type>;
    new_el->data = num;
    new_el->next = cursor;
    new_el->prev = it;
    cursor->prev = new_el;
    it->next = new_el;
    size++;
}

template<typename num_type>
void List<num_type>::pop_last(){
    if (is_empty()){
        cout << "-No items to delete-\n";
        return;
    }
    if (first->next == nullptr) {
        delete first;
        delete last;
        last = nullptr;
        first = nullptr;
        cursor = nullptr;
        size --;
        return;
    }
    if (cursor == last){
        cursor = last->prev;
        cursor->next = nullptr;
    }
    last = last->prev;
    last->next = nullptr;
    size--;
}

template<typename num_type>
void List<num_type>::pop_first(){
    if (is_empty()){
        cout << "-No items to delete-\n";
        return;
    }
    if (first == last) {
        delete first;
        delete last;
        last = nullptr;
        first = nullptr;
        cursor = nullptr;
        size --;
        return;
    }
    if (cursor == first){
        cursor = first->next;
        cursor->prev = nullptr;
    }
    first = first->next;
    first->prev = nullptr;
    size--;
}

template<typename num_type>
void List<num_type>::add_el_back(num_type num){
    if (is_empty()){
        first = new Node<num_type>;
        last = new Node<num_type>;
        cursor = new Node<num_type>;
        first -> data = num;
        last = first;
        cursor = first;
        size ++;
        return;
    } else{
        Node<num_type> *it = new Node<num_type>;
        it = last;
        it->next = new Node<num_type>;
        it->next->data = num;
        last = it->next;
        last->prev = it;
        size ++;
    }
}

template<typename num_type>
void List<num_type>::add_el_ahead(num_type num){
    if (is_empty()){
        first = new Node<num_type>;
        last = new Node<num_type>;
        cursor = new Node<num_type>;
        first -> data = num;
        last = first;
        cursor = first;
        size ++;
        return;
    }
    Node<num_type> *it = new Node<num_type>;
    it->data = num;
    first->prev = it;
    it->next = first;
    first = it;
    size ++;
}

template<typename num_type>
void List<num_type>::new_size(num_type siz_){
    size = siz_;
}

template<typename num_type>
ostream& operator<<(ostream& out, const List<num_type>& conc) {
    Node<num_type> *it = new Node<num_type>;
    it = conc.first;
    out << "\nYour list:\n";
    if (conc.is_empty()){
        out << "-";
    }else{
        while (it->next != nullptr){
            if( it == conc.cursor){
                out << "[" << it->data << "] - ";
            } else{
                out << it->data << " - ";
            }
            it = it->next;
        }
        if( it == conc.cursor){
            out << "[" << it->data << "]\n";
        } else{
            out << it->data << endl;
        }
    }

    out << "\nlength = " << conc.size << endl;
    // out << "\nYour cursor on " << conc.cursor->data << ' ';
    // Node<num_type> *it2 = conc.first;
    // int numb = 0;
    // while (it2 != conc.cursor){
    //     it2 = it2->next;
    //     numb ++;
    // }
    // out << "( " << numb + 1 << " element)\n";
    return out;
}


template<typename num_type>
istream &operator>>(istream& in, List<num_type>& conc){
    conc.first = new Node<num_type>;
    conc.cursor = conc.first; 
    Node<num_type> *it = conc.first;
    Node<num_type> *prev_it = conc.first;
    int num;
    in >> num;
    it->data = num;
    for (int i = 0; i < conc.size - 1; i++){
        int num;
        in >> num;
        it->next =  new Node<num_type>;
        prev_it = it;
        it = it-> next;
        it->prev = prev_it;
        it->data = num;
    }
    conc.last = it;
    return in;
}