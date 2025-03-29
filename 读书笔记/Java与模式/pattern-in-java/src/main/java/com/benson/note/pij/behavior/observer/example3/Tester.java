package com.benson.note.pij.behavior.observer.example3;

public class Tester {

    /*
    * Attention:
    *
    * Observable and Observer are two interfaces that are used to implement the Observer pattern in Java.
    * But both Observer and Observable are deprecated in Java 9.
    * It is recommended to use the java.util.concurrent.Flow API introduced in Java 9.
    * see: https://docs.oracle.com/javase/9/docs/api/java/util/concurrent/Flow.html
    * Example: https://www.baeldung.com/java-9-reactive-streams
    * Local example : example4
    * */

    static private Watched watched = null;
    static private Watcher watcher = null;

    public static void main(String[] args) {
        watched = new Watched();
        watcher = new Watcher(watched);
        watched.changeData("1");
        watched.changeData("2");
        watched.changeData("3");
        watched.changeData("4");
    }
}
