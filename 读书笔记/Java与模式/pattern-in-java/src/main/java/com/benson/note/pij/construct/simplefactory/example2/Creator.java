package com.benson.note.pij.construct.simplefactory.example2;

public class Creator {
    /*
     * 静态工厂方法
     * */
    public static Product factory() {
        return new ConcreteProduct();
    }
}