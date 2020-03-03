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
	once_flag _flag;
public:
	Mylog()
	{
		/*m_stream.open("D:\\theMasterRepo\\C++\\Log\\mutex_log.txt", ios::out);
		if(!m_stream.is_open())
		{
			cout<<"File open Error"<<endl;
		}*/
	}
	~Mylog()
	{
		m_stream.close();
	}
	
	void operator()(stringstream& log_str)
	{
		try{
			for(size_t idx = 0; idx < 10; idx++)
			{
				call_once(_flag, [&](){
					m_stream.open("D:\\theMasterRepo\\C\\Log\\mutex_log.txt", ios::out);
					if(!m_stream.is_open())
					{
						throw runtime_error("File open Error");
					}
				});
				unique_lock<mutex> locker(mu);
				m_stream << log_str.str() << endl;
			}
		}catch(exception &e){			
			cerr<<e.what()<<endl;
		}	
//		lock_guard<mutex> locker(mu);
		
//		locker.unlock();
//		cout<<"Directly: "<<log_str.str()<<endl;
	}
};

void thread_funct(Mylog& log)
{
	stringstream log_str;
//	static int msg_no = 0;
	
	try{
		for(size_t idx = 0; idx < 10; idx++)
		{
			stringstream log_str;
			log_str << "Thread Id: " << this_thread::get_id();

			log_str << " Message No: "<< idx;
		
			log_str<<"\n";
		
//			cout<<log_str.str()<<endl;
		
			log(ref(log_str));
		}
	}catch(exception e){			
		cerr<<e.what()<<endl;
	}	
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

