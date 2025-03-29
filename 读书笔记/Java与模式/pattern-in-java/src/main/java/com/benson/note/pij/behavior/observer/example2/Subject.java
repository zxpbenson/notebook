package com.benson.note.pij.behavior.observer.example2;

import java.util.Enumeration;
import java.util.Vector;

public abstract class Subject {
    
    private Vector<Observer> observers = new Vector<Observer>();

    public void attach(Observer observer) {
        this.observers.addElement(observer);
    }

    public void detach(Observer observer) {
        this.observers.removeElement(observer);
    }

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
