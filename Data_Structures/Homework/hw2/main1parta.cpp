#include <iostream>
#include <stack>
#include <queue>
#include <deque>

using namespace std;

int main(){
    stack< queue<int> > s;  //stack which also contains the which is the queue.

    queue<int> t;      //this gives you the caller t for queue so you can access
    t.push(5);    //this pushes the int into the queue
    s.push(t);    
    cout << s.top().front() << endl;
    t.pop();


    t.push(6);             
    s.push(t);    
    cout << s.top().front() << endl;
    t.pop();


    t.push(3); 
    s.push(t);    
    cout << s.top().front() << endl;
    t.pop();
cout << " "<< endl; 

 queue<int> x;
    x.push(5);    //this pushes the int into the queue
    s.push(x);    
    cout << s.top().front() << endl;
    x.pop();


    x.push(6);             
    s.push(x);    
    cout << s.top().front() << endl;
    x.pop();


    x.push(4); 
    s.push(x);    
    cout << s.top().front() << endl;
    x.pop();
cout << " "<< endl; 






 queue<int> p;
     p.push(5);    //this pushes the int into the queue
    s.push(p);    
    cout << s.top().front() << endl;
    p.pop();


    p.push(6);             
    s.push(p);    
    cout << s.top().front() << endl;
    p.pop();


    p.push(3); 
    s.push(p);    
    cout << s.top().front() << endl;
    p.pop();
cout << " "<< endl; 

    

 queue<int> o;
    o.push(5);    //this pushes the int into the queue
    s.push(o);    
    cout << s.top().front() << endl;
    o.pop();


    o.push(6);             
    s.push(o);    
    cout << s.top().front() << endl;
    o.pop();


    o.push(3);
    s.push(o);    
    cout << s.top().front() << endl;
    o.pop();
cout << " "<< endl; 

 
 queue<int> i;
    i.push(5);    //this pushes the int into the queue
    s.push(i);    
    cout << s.top().front() << endl;
    i.pop();


    i.push(6);             
    s.push(i);    
    cout << s.top().front() << endl;
    i.pop();


    i.push(3);
    s.push(i);    
    cout << s.top().front() << endl;
    i.pop();

   cout << " "<< endl; 

    return 0;
}
