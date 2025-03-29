package com.benson.note.pij.behavior.observer.example2;

public class ConcreteSubject extends Subject {
    private String state;
    public void change(String newState) {
        this.state = newState;
        this.notifyObservers();
    }
}
