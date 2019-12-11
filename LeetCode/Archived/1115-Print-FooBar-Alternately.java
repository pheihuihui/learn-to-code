class FooBar {
    private int n;
    private boolean isFoo;

    public FooBar(int n) {
        this.n = n;
        this.isFoo = true;
    }

    public synchronized void foo(Runnable printFoo) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(!this.isFoo){
                wait();
            }
            printFoo.run();
            this.isFoo = false;
            notifyAll();
        }
    }

    public synchronized void bar(Runnable printBar) throws InterruptedException {
        
        for (int i = 0; i < n; i++) {
            while(this.isFoo){
                wait();
            }
            printBar.run();
            this.isFoo = true;
            notifyAll();
        }
    }
}