class noncopyable{
public:
    noncopyable(){}
    ~noncopyable(){}
private:
    noncopyable(const noncopyable&);
    noncopyable& operator=(const noncopyable&);
};