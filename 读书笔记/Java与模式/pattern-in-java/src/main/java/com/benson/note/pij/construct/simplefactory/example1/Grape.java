package com.benson.note.pij.construct.simplefactory.example1;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Grape implements Fruit {

    private static final Logger LOG = LoggerFactory.getLogger(Grape.class);

    private boolean seedless;

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

    public boolean isSeedless() {
        return seedless;
    }

    public void setSeedless(boolean seedless) {
        this.seedless = seedless;
    }
}
