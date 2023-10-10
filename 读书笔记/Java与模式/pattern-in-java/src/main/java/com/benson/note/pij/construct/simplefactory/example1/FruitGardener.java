package com.benson.note.pij.construct.simplefactory.example1;

public class FruitGardener {
    public static Fruit factory(String which) throws BadFruitException {
        if ("apple".equalsIgnoreCase(which)) {
            return new Apple();
        } else if ("grape".equalsIgnoreCase(which)) {
            return new Grape();
        } else if ("strawberry".equalsIgnoreCase(which)) {
            return new Strawberry();
        } else {
            throw new BadFruitException("Bad fruit request");
        }
    }
}
