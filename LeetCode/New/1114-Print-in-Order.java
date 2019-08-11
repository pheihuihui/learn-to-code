class Foo {

    boolean firstDone = false;
    boolean secondDone = false;

    public Foo() {

    }

    public synchronized void first(Runnable printFirst) throws InterruptedException {
        printFirst.run();
        this.firstDone = true;
        notifyAll();
    }

    public synchronized void second(Runnable printSecond) throws InterruptedException {
        while(!this.firstDone){
            wait();
        }
        printSecond.run();
        this.secondDone = true;
        notifyAll();
    }

    public synchronized void third(Runnable printThird) throws InterruptedException {
        while(!this.secondDone){
            wait();
        }
        printThird.run();
        notifyAll();
    }
}