package com.benson.note.pij;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingQueue;

public class Tmp {
    public static void main(String[] args) {

        BlockingQueue<String> bq = new LinkedBlockingQueue<String>();

        for(int i = 1; i< 15; i++){
            System.out.println("==========");
            System.out.println(kinds1(i));
            System.out.println(kinds2(i));
        }
    }

    private static void m1() {
        long currentTimeMillis = System.currentTimeMillis();
        int currentTime = (int) (currentTimeMillis / 1000);
        System.out.println(currentTimeMillis);
        System.out.println(currentTime);
        System.out.println(Integer.MAX_VALUE);
        System.out.println(Long.MAX_VALUE);
        byte[] currentByteArr = toBigEndian(currentTime);
        System.out.println(fromBigEndian(currentByteArr));
        //System.out.println(Integer.toBinaryString(0));
        System.out.println(0x7fffffff);
    }

    private static byte[] toBigEndian(int n) {
        byte[] b = new byte[4];
        b[3] = (byte) (n & 0xff);
        b[2] = (byte) (n >> 8 & 0xff);
        b[1] = (byte) (n >> 16 & 0xff);
        b[0] = (byte) (n >> 24 & 0xff);
        return b;
    }

    private static int fromBigEndian(byte[] ba) {
        int i = 0;
        i = i | ((0xff & ba[0]) << 24);
        i = i | ((0xff & ba[1]) << 16);
        i = i | ((0xff & ba[2]) << 8);
        i = i | (0xff & ba[3]);
        return i;
    }

    public static int kinds1(int step) {
        if (step == 1) {
            return 1;
        }
        if (step == 2) {
            return 2;
        }
        return kinds1(step - 1) + kinds1(step - 2);
    }

    public static int kinds2(int step){
        if(step==1){
            return 1;
        }else if(step==2){
            return 2;
        }else{
            int a=1;
            int b=2;
            int res = 0;
            for(int i=3;i<=step;i++){
                res=a+b;
                a=b;
                b=res;
            }
            return res;
        }
    }

}

