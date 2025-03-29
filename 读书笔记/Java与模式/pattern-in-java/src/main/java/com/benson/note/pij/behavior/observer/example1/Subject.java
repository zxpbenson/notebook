package com.benson.note.pij.behavior.observer.example1;

public interface Subject {
    void attach(Observer observer);

    void detach(Observer observer);

    void notifyObservers();
}
