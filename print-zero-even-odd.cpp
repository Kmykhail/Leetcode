class ZeroEvenOdd {
private:
    int n;

    mutex m;
    condition_variable cv;

    int val = 0;
    int tmp = 1;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    void zero(function<void(int)> printNumber) {
        std::unique_lock<std::mutex> lk(m);
        while (tmp <= n) {
            cv.wait(lk, [this](){ return val == 0 || tmp > n;});

            if (tmp > n) return;

            printNumber(0);

            val = tmp;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lk(m);
        while (tmp <= n) {
            cv.wait(lk, [this](){ return (val > 0 && !(val % 2)) || tmp > n;});

            if (tmp > n) return;

            printNumber(tmp++);
            val = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lk(m);
        while (tmp <= n) {
            cv.wait(lk, [this](){ return (val > 0 && (val % 2)) || tmp > n;});

            if (tmp > n) return;

            printNumber(tmp++);
            val = 0;
            cv.notify_all();
        }
    }
};
