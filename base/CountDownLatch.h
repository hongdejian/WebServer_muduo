#include"noncopyable.h"
#include"MutexLock.h"
#include"Condition.h"
//
class CountDownLatch:noncopyable{
public:
    explicit CountDownLatch(int count);
    void wait();
    void countDown();
private:
    mutable MutexLock mutex_;
    Condition cond_;
    int count_;
};