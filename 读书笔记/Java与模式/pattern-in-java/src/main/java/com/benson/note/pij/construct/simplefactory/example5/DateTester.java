package com.benson.note.pij.construct.simplefactory.example5;

import java.text.DateFormat;
import java.util.Date;
import java.util.Locale;

public class DateTester {

    public static void main(String[] args) {
        tmp();


        Locale local = Locale.FRENCH;
        DateFormat dateFormat = DateFormat.getTimeInstance(DateFormat.DEFAULT, local);

        Date date = new Date();
        String now = dateFormat.format(date);
        System.out.println(now);
        try {
            date = dateFormat.parse("16 nov. 01");
            System.out.println(date);
        } catch (Exception e) {
            System.out.println("Parsing exception : " + e);
        }
    }

    public static void tmp() {
        Locale local = Locale.ENGLISH;
        DateFormat dateFormat = DateFormat.getTimeInstance(DateFormat.FULL, local);
        String now = dateFormat.format(new Date());
        System.out.println(now);
    }
}
