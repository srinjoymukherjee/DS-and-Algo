#include <bits/stdc++.h>

using namespace std;

class myQueue{
	int queue_size;
	stack<int> s1, s2;

public:
	myQueue(){
		queue_size = 0;
	}
	
	void pushQueue(int val){
		if(s1.empty())
			s1.push(val);
		else
		{
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
			
			s2.push(val);
			
			while(!s2.empty()){
				s1.push(s2.top());
				s2.pop();
			}		
		}
		queue_size++;
	}
	
	int popQueue(){
		int val = INT_MIN;
		
		if(!s1.empty()){
			val = s1.top();
			s1.pop();
			queue_size--;
		}
				
		return val;
	}
	
	int getSize(){
		return queue_size;
	}
};

int main(){
	myQueue mq;
	mq.pushQueue(1);
	mq.pushQueue(2);
	mq.pushQueue(3);
	
	cout<<"Value: "<<mq.popQueue()<<endl;
	cout<<"Size: "<<mq.getSize()<<endl;
	
	mq.pushQueue(4);
	mq.pushQueue(5);
	
	cout<<"Value: "<<mq.popQueue()<<endl;
	cout<<"Value: "<<mq.popQueue()<<endl;
	cout<<"Value: "<<mq.popQueue()<<endl;
	
	cout<<"Size: "<<mq.getSize()<<endl;
	cout<<"Value: "<<mq.popQueue()<<endl;
	
	return 0;
		
}
