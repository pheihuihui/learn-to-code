class DiningPhilosophers {

    ReentrantLock forks[];

    public DiningPhilosophers() {
        forks = new ReentrantLock[5];
        forks[0] = new ReentrantLock();
        forks[1] = new ReentrantLock();
        forks[2] = new ReentrantLock();
        forks[3] = new ReentrantLock();
        forks[4] = new ReentrantLock();
    }

    private ReentrantLock getFork(int philosopher, int lr) {
        if (lr == 1) {
            return forks[philosopher];
        } else {
            if (philosopher == 0) {
                return forks[4];
            } else {
                return forks[philosopher - 1];
            }
        }
    }

    // call the run() method of any runnable to execute its code
    public synchronized void wantsToEat(int philosopher, Runnable pickLeftFork, Runnable pickRightFork, Runnable eat,
            Runnable putLeftFork, Runnable putRightFork) throws InterruptedException {
        ReentrantLock left = getFork(philosopher, 1);
        ReentrantLock right = getFork(philosopher, 2);
        while (left.isLocked() && right.isLocked()) {
            wait();
        }
        if (!left.isLocked()) {
            left.lock();
            pickLeftFork.run();
            while (right.isLocked()) {
                wait();
            }
            right.lock();
            pickRightFork.run();
        } else if (!right.isLocked()) {
            right.lock();
            pickRightFork.run();
            while (left.isLocked()) {
                wait();
            }
            left.lock();
            pickLeftFork.run();
        }
        eat.run();
        putLeftFork.run();
        putRightFork.run();
        left.unlock();
        right.unlock();
        notifyAll();
    }
}