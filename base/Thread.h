#include"CountDownLatch.h"
#include"noncopyable.h"
#include<functional>
#include<pthread.h>
#include<string>
#include<sys/syscall.h>
#include<unistd.h>

class Thread:noncopyable{
public:
    typedef std::function<void ()>ThreadFunc;
    explicit Thread(const ThreadFunc&,const std::string& name=std::string());
    ~Thread();
    void start();
    int join();
    bool started();
    pid_t tid()const {return tid_;}
    const std::string& name() const{return name_;}
private:
    void setDefaultName();
    bool started_;
    bool joined_;
    pthread_t pthreadID_;
    pid_t tid_;
    ThreadFunc func_;
    std::string name_;
    CountDownLatch latch_;
};