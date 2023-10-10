package com.benson.note.pij;

public class AB {

    public static void main(String[] args) {
        Object s1 = new Object();
        Object s2 = new Object();
        ThreadA a = new ThreadA(s1, s2);
        ThreadB b = new ThreadB(s1, s2);

        b.start();
        while (!b.isReady()) {
            try {
                System.out.println("thread b is not ready");
                Thread.sleep(10);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        a.start();

        try {
            b.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        try {
            a.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }

}

class ThreadA extends Thread {

    private Object s1;
    private Object s2;

    public ThreadA(Object s1, Object s2) {
        this.s1 = s1;
        this.s2 = s2;
    }

    @Override
    public void run() {
        System.out.println("ThreadA start");
        synchronized (s1) {
            s1.notify();
            System.out.println("ThreadA send signal to ThreadB");
        }
        try {
            synchronized (s2) {
                s2.wait();
                System.out.println("ThreadA receive signal from ThreadB");
            }
        } catch (InterruptedException e) {
            System.out.println("ThreadA e");
            e.printStackTrace();
        }
        System.out.println("ThreadA end");
    }
}

class ThreadB extends Thread {

    private Object s1;
    private Object s2;
    private boolean ready = false;

    public ThreadB(Object s1, Object s2) {
        this.s1 = s1;
        this.s2 = s2;
    }

    @Override
    public void run() {
        System.out.println("ThreadB start");
        try {
            synchronized (s1) {
                ready = true;
                s1.wait();
                System.out.println("ThreadB receive signal from ThreadA");
            }
        } catch (InterruptedException e) {
            System.out.println("ThreadB e");
            e.printStackTrace();
        }

        synchronized (s2) {
            s2.notify();
            System.out.println("ThreadB send signal to ThreadA");
        }
        System.out.println("ThreadB end");
    }

    public boolean isReady() {
        return this.ready;
    }
}