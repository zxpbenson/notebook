package com.benson.note.pij.construct.factorymethod.example2;

public class AppleGardener implements FruitGardener {
    @Override
    public Fruit factory() {
        return new Apple();
    }
}
