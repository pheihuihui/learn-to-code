class FizzBuzz {
    private int n;
    private int cur;
    private int state;

    public FizzBuzz(int n) {
        this.n = n;
        this.cur = 1;
        this.state = 0;
    }

    private void changeType() {
        if (this.cur % 3 == 0 && this.cur % 5 == 0) {
            this.state = 15;
        } else if (this.cur % 3 == 0) {
            this.state = 3;
        } else if (this.cur % 5 == 0) {
            this.state = 5;
        } else {
            this.state = 0;
        }
    }

    // printFizz.run() outputs "fizz".
    public synchronized void fizz(Runnable printFizz) throws InterruptedException {
        while (this.cur <= this.n) {
            while (this.state != 3 && this.cur <= this.n) {
                wait();
            }
            if (this.cur <= this.n) {
                printFizz.run();
                this.cur += 1;
                changeType();
                notifyAll();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public synchronized void buzz(Runnable printBuzz) throws InterruptedException {
        while (this.cur <= this.n) {
            while (this.state != 5 && this.cur <= this.n) {
                wait();
            }
            if (this.cur <= this.n) {
                printBuzz.run();
                this.cur += 1;
                changeType();
                notifyAll();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public synchronized void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (this.cur <= this.n) {
            while (this.state != 15 && this.cur <= this.n) {
                wait();
            }
            if (this.cur <= this.n) {
                printFizzBuzz.run();
                this.cur += 1;
                changeType();
                notifyAll();
            }
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public synchronized void number(IntConsumer printNumber) throws InterruptedException {
        while (this.cur <= this.n) {
            while (this.state != 0 && this.cur <= this.n) {
                wait();
            }
            if (this.cur <= this.n) {
                printNumber.accept(this.cur);
                this.cur += 1;
                changeType();
                notifyAll();
            }

        }
    }
}