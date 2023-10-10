package com.benson.note.pij.construct.simplefactory.example1;

import junit.framework.TestCase;
import org.junit.Test;

public class FruitGardenerTest extends TestCase {
    @Test
    public void testFactory() {
        try {
            Fruit fruit = FruitGardener.factory("Apple");
            assertTrue(fruit instanceof Apple);

            fruit = FruitGardener.factory("Grape");
            assertTrue(fruit instanceof Grape);

            fruit = FruitGardener.factory("Strawberry");
            assertTrue(fruit instanceof Strawberry);

            FruitGardener.factory("something");

        } catch (Exception e) {
            assertTrue(e instanceof BadFruitException);
        }
    }
}
