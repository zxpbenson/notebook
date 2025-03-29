package com.benson.note.pij.behavior.observer.example3;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import java.util.Observable;
import java.util.Observer;
import java.util.concurrent.atomic.AtomicInteger;

public class Watcher implements Observer {


    private static final Logger LOG = LoggerFactory.getLogger(Watcher.class);
    private static AtomicInteger counter = new AtomicInteger(0);

    private Integer id;

    public Watcher(Watched watched) {
        watched.addObserver(this);
        this.id = counter.incrementAndGet();
    }

    public void update(Observable obj, Object arg) {
        LOG.info("{} : Watched data change to : {}.", this, arg);
    }

    @Override
    public String toString() {
        return String.format("Watcher[id=%d]", id);
    }
}
