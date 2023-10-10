package com.benson.note.pij.construct.simplefactory.example1;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Strawberry implements Fruit {

    private static final Logger LOG = LoggerFactory.getLogger(Strawberry.class);

    @Override
    public void plant() {
        LOG.info("Grape has benn planted.");
    }

    @Override
    public void grow() {
        LOG.info("Grape is growing...");
    }

    @Override
    public void harvest() {
        LOG.info("Grape has benn harvested.");
    }
}
