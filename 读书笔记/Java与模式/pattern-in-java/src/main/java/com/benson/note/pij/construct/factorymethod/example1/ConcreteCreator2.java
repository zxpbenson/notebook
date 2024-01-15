package com.benson.note.pij.construct.factorymethod.example1;

public class ConcreteCreator2 implements Creator {
    @Override
    public Product factory() {
        return new ConcreteProduct2();
    }
}
