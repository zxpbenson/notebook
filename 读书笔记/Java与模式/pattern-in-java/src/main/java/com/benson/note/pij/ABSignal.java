package com.benson.note.pij;

import java.util.concurrent.Semaphore;

public class ABSignal {

    /*
     * 题目【AB两线程互换信号】
     * a: 发信号给b，等回复，等到回复就结束
     * b: 等信号，等到a的信号后回给a一个信号，结束
     * 推荐使用Semaphore实现信号发送和接收
     * */
    public static void main(String[] args) {
        Semaphore as = new Semaphore(0);
        Semaphore bs = new Semaphore(0);

        Thread a = new A(as, bs);
        Thread b = new B(as, bs);

        //a.setDaemon(true);
        //b.setDaemon(true);

        b.start();
        a.start();

        //try {
        //    a.join();
        //} catch (InterruptedException e) {
        //    e.printStackTrace();
        //}
        //try {
        //    b.join();
        //} catch (InterruptedException e) {
        //    e.printStackTrace();
        //}
        System.out.println("main thread done");
    }
}

class A extends Thread {
    private Semaphore as;
    private Semaphore bs;

    public A(Semaphore as, Semaphore bs) {
        this.as = as;
        this.bs = bs;
    }

    public void run() {
        try {
            System.out.println("A send signal");
            as.release();
            System.out.println("A send signal done and wait for B");
            bs.acquire();
            System.out.println("A got signal from B");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}

class B extends Thread {
    private Semaphore as;
    private Semaphore bs;

    public B(Semaphore as, Semaphore bs) {
        this.as = as;
        this.bs = bs;
    }

    public void run() {
        try {
            System.out.println("B wait for a signal from A");
            as.acquire();
            System.out.println("B got signal from A and send a signal back to A");
            bs.release();
            System.out.println("B jobs done");
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}