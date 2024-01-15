package com.benson.note.pij.construct.factorymethod.example2;

public class GrapeGardener implements FruitGardener {
    @Override
    public Fruit factory() {
        return new Grape();
    }
}
