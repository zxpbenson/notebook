package com.benson.note.pij.behavior.observer.example1;

import java.util.Enumeration;
import java.util.Vector;

public class ConcreteSubject implements Subject {

    private Vector<Observer> observers = new Vector<Observer>();

    @Override
    public void attach(Observer observer) {
        this.observers.addElement(observer);
    }

    @Override
    public void detach(Observer observer) {
        this.observers.removeElement(observer);
    }

    @Override
    public void notifyObservers() {
        Enumeration<Observer> enumeration = this.observers.elements();
        while (enumeration.hasMoreElements()) {
            enumeration.nextElement().update();
        }
    }

    public Enumeration<Observer> getObservers() {
        return this.observers.elements();
    }
}
