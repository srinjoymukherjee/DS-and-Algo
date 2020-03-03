#include <thread>
#include <iostream>
#include <fstream>
#include <mutex>
#include <sstream>

using namespace std;

class Mylog
{
	std::ofstream m_stream;
	mutex mu;
public:
	Mylog()
	{
		m_stream.open("D:\\theMasterRepo\\C++\\Log\\mutex_log.txt", ios::out);
		if(!m_stream.is_open())
		{
			cout<<"File open Error"<<endl;
		}
	}
	~Mylog()
	{
		m_stream.close();
	}
	
	void operator()(stringstream&& log_str)
	{
//		lock_guard<mutex> locker(mu);
		m_stream << log_str.str() << endl;
	}
};

void thread_funct(Mylog& log)
{
	stringstream log_str;
	static int msg_no = 0;
	
	for(size_t idx = 0; idx < 10; idx++)
	{
		log_str << "Thread Id: " << this_thread::get_id();

		log_str << " Message No: "<< msg_no++;
		
		log_str<<"\n";
	}	
	
	log(move(log_str));
}

int main()
{
	try{
		Mylog log;
		thread t1(thread_funct, ref(log));
	
		thread t2(thread_funct, ref(log));
		
		if(t2.joinable())
			t2.join();
	
		if(t1.joinable())
			t1.join();
			
	}catch(exception e){			
		cout<<e.what()<<endl;
	}	
	
//	t1.detach();
}
