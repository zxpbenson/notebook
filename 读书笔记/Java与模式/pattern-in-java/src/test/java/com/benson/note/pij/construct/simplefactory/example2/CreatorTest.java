package com.benson.note.pij.construct.simplefactory.example2;

import junit.framework.TestCase;
import org.junit.Test;

public class CreatorTest extends TestCase {
    @Test
    public void testFactory() {
        Product product = Creator.factory();
        assertTrue(product instanceof ConcreteProduct);
    }
}