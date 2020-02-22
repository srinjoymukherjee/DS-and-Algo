#include<bits/stdc++.h>

using namespace std;

class logger
{
    static logger* log_obj;
    fstream log_str;

    logger(string fname)
    {
        log_str.open(fname,ios::out);
        cout<<"logger initialized"<<endl;
    }

public:
    static logger* getLogInstance(string fname)
    {
        if(!log_obj)
        {
            log_obj = new logger(fname);
        }
        return log_obj;
    }

    void addLog(string log_data);

    ~logger()
    {
        log_str.close();
    }
};

logger* logger::log_obj = nullptr;

void logger::addLog(string data)
{
    // log_str.write(data.c_str(), data.size());
    log_str<<data<<endl;
}

int main(){
    logger* logs = logger::getLogInstance("newlog.txt");
    logs->addLog("Added New log");
    logger* log_debug = logger::getLogInstance("newlog1.txt");
    logs->addLog("Added Next log");
    return 0;
}
