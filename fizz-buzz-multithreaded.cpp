class FizzBuzz {
private:
    int n;
    int iter = 1;
    mutex m;
    condition_variable cv;
public:
    FizzBuzz(int n) {
        this->n = n;
    }


    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        unique_lock<mutex> lk(m);
        while (true) {
            cv.wait(lk, [this] { return (iter % 3) == 0 && (iter % 5) > 0 || iter > n; });
            if (iter > n) return;
            printFizz();
            iter++;
            cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        unique_lock<mutex> lk(m);
        while (true) {
            cv.wait(lk, [this] { return (iter % 5) == 0 && (iter % 3) > 0 || iter > n; });
            if (iter > n) return;
            printBuzz();
            iter++;
            cv.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz(function<void()> printFizzBuzz) {
        unique_lock<mutex> lk(m);
        while (true) {
            cv.wait(lk, [this] { return (iter % 5) == 0 && (iter % 3) == 0 || iter > n; });
            if (iter > n) return;
            printFizzBuzz();
            iter++;
            cv.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        unique_lock<mutex> lk(m);
        while (true) {
            cv.wait(lk, [this] { return (iter % 5) > 0 && (iter % 3) > 0 || iter > n; });
            if (iter > n) return;
            printNumber(iter);
            iter++;
            cv.notify_all();
        }
    }
};
