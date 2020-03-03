/*Shared Memory*/
#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <future>
#include <chrono>
//#include <promise>

using namespace std;

queue<int> q;
mutex mu;
condition_variable cond;

int broker(int val)
{	
	unique_lock<mutex> locker(mu);
	q.push(val);
	mu.unlock();
	cond.notify_all();
	return q.size();
}

int subscriber()
{
	unique_lock<mutex> locker(mu);
	cond.wait(locker,[&](){
		return !q.empty();
	});
	this_thread::sleep_for(chrono::milliseconds(30));	
	cout<<"Subcriber Data: "<<q.front()<<endl;
	q.pop();
	return q.size();	
}

int main()
{
	future<int> fu1 = async(launch::async, broker, 5);
	cout<<"Queue size after broker: "<<fu1.get()<<endl;

	future<int> fu2 = async(launch::async, subscriber);
	cout<<"Queue size after subscriber: "<<fu2.get()<<endl;
}
