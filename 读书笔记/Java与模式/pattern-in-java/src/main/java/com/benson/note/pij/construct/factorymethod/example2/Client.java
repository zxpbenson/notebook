package com.benson.note.pij.construct.factorymethod.example2;

public class Client {
    private static FruitGardener ag, sg, gg;
    private static Fruit apple, strawberry, grape;

    public static void main(String[] args) {
        ag = new AppleGardener();
        sg = new StrawberryGardener();
        gg = new GrapeGardener();

        apple = ag.factory();
        strawberry = sg.factory();
        grape = gg.factory();
    }
}
