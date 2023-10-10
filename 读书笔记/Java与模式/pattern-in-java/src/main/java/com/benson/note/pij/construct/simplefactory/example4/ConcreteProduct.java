package com.benson.note.pij.construct.simplefactory.example4;

public class ConcreteProduct {
    public ConcreteProduct() {
        java.text.SimpleDateFormat a;
    }

    /*
    * 静态工厂方法
    * */
    public static ConcreteProduct factory() {
        return new ConcreteProduct();
    }
}