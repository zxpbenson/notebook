package com.benson.note.pij.construct.simplefactory.example1;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class Apple implements Fruit {

    private static final Logger LOG = LoggerFactory.getLogger(Apple.class);

    private int treeAge;

    @Override
    public void plant() {
        LOG.info("Apple has benn planted.");
    }

    @Override
    public void grow() {
        LOG.info("Apple is growing...");
    }

    @Override
    public void harvest() {
        LOG.info("Apple has benn harvested.");
    }

    public int getTreeAge() {
        return treeAge;
    }

    public void setTreeAge(int treeAge) {
        this.treeAge = treeAge;
    }
}
