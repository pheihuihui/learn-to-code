class ZeroEvenOdd {
    private int n;
    int status = 0;
    int cur = 1;

    public ZeroEvenOdd(int n) {
        this.n = n;
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        for (int u = 0; u < n; u++) {
            synchronized (this) {
                while (status != 0) {
                    wait();
                }
                printNumber.accept(0);
                if (cur % 2 == 1) {
                    status = 1;
                } else {
                    status = 2;
                }
                notifyAll();
            }
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int u = 2; u < n; u += 2) {
            synchronized (this) {
                while (status != 2) {
                    wait();
                }
                printNumber.accept(cur);
                status = 0;
                cur += 1;
                notifyAll();
            }
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int u = 1; u < n; u += 2) {
            synchronized (this) {
                while (status != 1) {
                    wait();
                }
                printNumber.accept(cur);
                status = 0;
                cur += 1;
                notifyAll();
            }
        }
    }
}