#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;








int main(){
    queue< deque<int> > s;  //stack which also contains the which is the queue.

    deque<int> t;      //this gives you the caller t for queue so you can access
    t.push_front(5);    //this pushes the int into the queue
    s.push(t);    
    cout << s.front().front() << endl;
    s.pop();       //s.pop will pop off the first element in list queue


    t.push_front(6);             
    s.push(t);    
    cout << s.front().front() << endl;
    s.pop();


    t.push_front(3); 
    s.push(t);    
    cout << s.front().front() << endl;
    s.pop();

cout << " "<< endl;


    deque<int> p;      //this gives you the caller t for queue so you can access
    p.push_front(5);    //this pushes the int into the queue 
    s.push(p);    
    cout << s.front().front() << endl;
    s.pop();       //s.pop will pop off the 
                       //first element in list queue


    p.push_front(1);             
    s.push(p);    
    cout << s.front().front() << endl;
    s.pop();


    p.push_front(4); 
    s.push(p);    
    cout << s.front().front() << endl;
    s.pop();

cout << " "<< endl; 


    deque<int> x;      //this gives you the caller t for queue so you can access
    x.push_front(3);    //this pushes the int into the queue
    s.push(x);    
    cout << s.front().front() << endl;
    s.pop();       //s.pop will pop off the 
                       //first element in list queue


    x.push_front(2);             
    s.push(x);    
    cout << s.front().front() << endl;
    s.pop();


    x.push_front(0); 
    s.push(x);    
    cout << s.front().front() << endl;
    s.pop();

cout << " "<< endl; 

deque<int> d;      //this gives you the caller t for queue so you can access
    d.push_front(7);    //this pushes the int into the queue 
    s.push(d);    
    cout << s.front().front() << endl;
    s.pop();       //s.pop will pop off the 
                       //first element in list queue


    d.push_front(8);             
    s.push(d);    
    cout << s.front().front() << endl;
    s.pop();


    d.push_front(4); 
    s.push(d);    
    cout << s.front().front() << endl;
    s.pop();

cout << " "<< endl;

deque<int> u;      //this gives you the caller t for queue so you can access
    u.push_front(7);    //this pushes the int into the queue 
    s.push(u);    
    cout << s.front().front() << endl;
    s.pop();       //s.pop will pop off the 
                       //first element in list queue


    u.push_front(9);             
    s.push(u);    
    cout << s.front().front() << endl;
    s.pop();


    u.push_front(4); 
    s.push(u);    
    cout << s.front().front() << endl;
    s.pop();

cout << " "<< endl;


    return 0;
}
