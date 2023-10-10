package com.benson.note.pij.construct.simplefactory.example3;

public class Creator {
    /*
    * 静态工厂方法
    * */
    public static ConcreteProduct factory() {
        return new ConcreteProduct();
    }
}