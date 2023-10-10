package com.benson.note.pij;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Some {

    private static final Logger LOG = LoggerFactory.getLogger(Some.class);

    public int calculate() {
        LOG.info("execute cal and return val");
        return 1;
    }

    public static void main(String[] args) {
        new Some().calculate();
    }
}
