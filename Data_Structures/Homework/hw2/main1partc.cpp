#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;




int main(){
    deque< stack<int> > s;  //the deque which contains stacks of intergers.

stack<int> t;      //this gives you the caller t for stack so you can access int
    t.push(2);    //this pushes the int into the stack
    s.push_front(t);    
    cout << s.front().top() << endl;
    s.pop_front();


    t.push(6);             
    s.push_front(t);    
    cout << s.front().top() << endl;
    s.pop_front();


    t.push(3); 
    s.push_front(t);    
    cout << s.front().top() << endl;
    s.pop_front();

cout << " "<< endl;

stack<int> x;      //this gives you the caller t for stack so you can access int
    x.push(7);    //this pushes the int into the stack
    s.push_front(x);    
    cout << s.front().top() << endl;
    s.pop_front();


    x.push(4);             
    s.push_front(x);    
    cout << s.front().top() << endl;
    s.pop_front();


    x.push(2); 
    s.push_front(t);    
    cout << s.front().top() << endl;
    s.pop_front();

cout << " "<< endl; 


stack<int> u;      
    u.push(6);    
    s.push_front(u);    
    cout << s.front().top() << endl;
    s.pop_front();


    u.push(7);             
    s.push_front(u);    
    cout << s.front().top() << endl;
    s.pop_front();


    u.push(8); 
    s.push_front(u);    
    cout << s.front().top() << endl;
    s.pop_front();

cout << " "<< endl; 


stack<int> e;   
    e.push(2);    
    s.push_front(e);    
    cout << s.front().top() << endl;
    s.pop_front();


    e.push(3);             
    s.push_front(e);    
    cout << s.front().top() << endl;
    s.pop_front();


    e.push(4); 
    s.push_front(e);    
    cout << s.front().top() << endl;
    s.pop_front();

cout << " "<< endl; 


stack<int> f;   
    f.push(1);    
    s.push_front(f);    
    cout << s.front().top() << endl;
    s.pop_front();


    f.push(3);             
    s.push_front(f);    
    cout << s.front().top() << endl;
    s.pop_front();


    f.push(2); 
    s.push_front(f);    
    cout << s.front().top() << endl;
    s.pop_front();

cout << " "<< endl; 


    return 0;
}
