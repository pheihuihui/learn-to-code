class H2O {

    int O = 0;
    int H = 0;

    public H2O() {
        
    }

    public synchronized void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
        while(H == 2){
            wait();
        }
        releaseHydrogen.run();
        H += 1;
        if(O == 1 && H == 2){
            H = 0;
            O = 0;
        }
        notifyAll();
    }

    public synchronized void oxygen(Runnable releaseOxygen) throws InterruptedException {
        while(O == 1){
            wait();
        }
        releaseOxygen.run();
        O += 1;
        if( H == 2 && O == 1){
            H = 0;
            O = 0;
        }
        notifyAll();
    }
}