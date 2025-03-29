package com.benson.note.pij.behavior.observer.example1;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.concurrent.atomic.AtomicInteger;

public class ConcreteObserver implements Observer {

    private static final Logger LOG = LoggerFactory.getLogger(ConcreteObserver.class);
    private static AtomicInteger counter = new AtomicInteger(0);

    private Integer id;

    public ConcreteObserver() {
        this.id = counter.incrementAndGet();
    }

    @Override
    public void update() {
        LOG.info("{} is notified.", this);
    }

    @Override
    public String toString() {
        return String.format("ConcreteObserver[id=%d]", id);
    }
}
