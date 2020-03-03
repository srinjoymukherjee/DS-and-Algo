#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>

using namespace std;

class MyLog
{
	mutex mu1;
	mutex mu2;
public:
	MyLog() = default;
	
	void shared_print1(string str)
	{
		lock(mu1, mu2);
		lock_guard<mutex> locker1(mu1, adopt_lock);
		lock_guard<mutex> locker2(mu2, adopt_lock);
		cout<<"Thread Info: "<<str<<endl;
	}
	
	void shared_print2(string str)
	{
		lock(mu1, mu2);
		lock_guard<mutex> locker2(mu2, adopt_lock);
		lock_guard<mutex> locker1(mu1, adopt_lock);
		cout<<"Thread Info: "<<str<<endl;
	}
};

static MyLog log;

void thread_func()
{
	for(size_t idx = 0; idx < 100; idx++)
	{
		stringstream m_str;
		m_str << "From Child Thread -> " << idx;
		log.shared_print1(m_str.str());
	}
}

int main()
{
	thread t1(thread_func);
	
	for(size_t idx = 0; idx < 100; idx++)
	{
		stringstream m_str;
		m_str << "From Main Thread -> " << idx;
		log.shared_print2(m_str.str());
	}
	t1.join();
	
}
