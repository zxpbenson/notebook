package com.benson.note.pij;

import junit.framework.TestCase;
import org.junit.Assert;
import org.junit.Test;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.io.IOException;

public class TestSome extends TestCase {

    private static final Logger LOG = LoggerFactory.getLogger(TestSome.class);

    private Some some = new Some();

    @Override
    protected void setUp() throws Exception {
        super.setUp();
        this.some = new Some();
    }

    @Override
    protected void tearDown() throws Exception {
        super.tearDown();
        this.some = null;
    }

    @Test
    public void testCalculate() throws IOException {
        Assert.assertEquals(some.calculate(), 1);
    }
}
