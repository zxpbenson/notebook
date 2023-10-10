package com.benson.note.pij.construct.simplefactory.example4;

import junit.framework.TestCase;
import org.junit.Test;

public class ConcreteProductTest extends TestCase {
    @Test
    public void testFactory() {
        ConcreteProduct product = ConcreteProduct.factory();
        assertTrue(product instanceof ConcreteProduct);
    }
}
