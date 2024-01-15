package com.benson.note.pij.construct.factorymethod.example2;

public class StrawberryGardener implements FruitGardener {

    @Override
    public Fruit factory() {
        return new Strawberry();
    }
}
