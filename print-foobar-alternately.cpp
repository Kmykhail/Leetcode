class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool switch_flag = true;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this](){return switch_flag;});
            
            printFoo();
            switch_flag = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this](){return !switch_flag;});
            printBar();
            
            switch_flag = true;
            cv.notify_all();
        }
    }
};
