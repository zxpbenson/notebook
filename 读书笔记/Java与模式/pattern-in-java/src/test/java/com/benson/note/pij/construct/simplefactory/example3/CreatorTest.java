package com.benson.note.pij.construct.simplefactory.example3;

import junit.framework.TestCase;
import org.junit.Test;

public class CreatorTest extends TestCase {
    @Test
    public void testFactory() {
        ConcreteProduct product = Creator.factory();
        assertTrue(product instanceof ConcreteProduct);
    }
}