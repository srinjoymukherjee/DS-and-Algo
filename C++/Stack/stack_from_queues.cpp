#include <iostream>
#include <queue>
#include <climits>

using namespace std;

void clearQueue(queue<int>& q){
	while(!q.empty())
		q.pop();
}

class myStack{
	int stack_size;
	queue<int> q1, q2;
	
public:
	myStack(){
		stack_size = 0;
	}
	
	void pushVal(int val);
	int popVal();
	int getSize();
	friend void clearQueue(queue<int>& q);
};

void myStack::pushVal(int val){
	q2.push(val);
	stack_size++;
	
	while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
	}
			
	q1 = q2;
	clearQueue(q2);
}

int myStack::popVal(){
	int val = INT_MIN;
	
	if(!q1.empty()){
		val = q1.front();
		q1.pop();
		stack_size--;
	}
	
	return val;
}

int myStack::getSize(){
	return this->stack_size;
}


int main(){
	myStack s;
	s.pushVal(1);
	s.pushVal(2);
	s.pushVal(3);
	
	cout<<"Size: "<<s.getSize()<<endl;
	cout<<"Value: "<<s.popVal()<<endl;
	cout<<"Value: "<<s.popVal()<<endl;
	cout<<"Size: "<<s.getSize()<<endl;
	
	s.pushVal(4);
	cout<<"Size: "<<s.getSize()<<endl;
	cout<<"Value: "<<s.popVal()<<endl;
	cout<<"Value: "<<s.popVal()<<endl;
	cout<<"Size: "<<s.getSize()<<endl;
}
