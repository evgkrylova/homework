package g144.krylova;

import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;

public class Main {
    public static void main(String[] args){
        System.out.println("This program is working with hash-table data structure.");
        System.out.println("Choose what hash function should be used and print:");
        System.out.println("\t0 - if polynomial one;");
        System.out.println("\t1 - if string length one.");
        HashTable table;
        int size = 512;

        Scanner input = new Scanner(System.in);
        String chosenHash = input.next();
        while (!chosenHash.equals("0") && !chosenHash.equals("1")) {
            System.out.println("Input is incorrect. Try again:");
            chosenHash = input.next();
        }

        if (chosenHash.equals("0")) {
            table = new HashTable(size, new PolynomialHasher());
        } else {
            table = new HashTable(size, new StringLengthHasher());
        }

        System.out.println("Choose the function and print corresponding number.");
        System.out.println("Print 'help' to see all functions.");
        String chosenFunction = input.next();
        while (!chosenFunction.equals("0")) {
            switch (chosenFunction) {
                case "help":
                    System.out.println("There are all possible functions:");
                    System.out.println("\t0 - to exit;");
                    System.out.println("\t1 - to load table from the file;");
                    System.out.println("\t2 - to add element;");
                    System.out.println("\t3 - to remove element;");
                    System.out.println("\t4 - to know if the element is in the table;");
                    System.out.println("\t5 - to print static data.");
                    break;
                case "1":
                    System.out.println("Enter the input file name: ");
                    String inputFileName = input.next();
                    Scanner inputFile;
                    try {
                        inputFile = new Scanner(new File(inputFileName));
                    } catch (FileNotFoundException e) {
                        System.out.println("File " + inputFileName + " is not found.");
                        return;
                    }
                    while (inputFile.hasNext()) {
                        try {
                            table.add(inputFile.next());
                        } catch (DuplicateValueException e){
                            //ignore;
                        }
                    }
                    break;
                case "2":
                    System.out.print("Enter the word to add: ");
                    try {
                        table.add(input.next());
                    } catch (DuplicateValueException e) {
                        e.message();
                    }
                    break;
                case "3":
                    System.out.print("Enter the word to remove: ");
                    try {
                        table.remove(input.next());
                    } catch (NotExistingValueException e) {
                        e.message();
                    }
                    break;
                case "4":
                    System.out.print("Enter the word to check:");
                    if (table.contains(input.next())) {
                        System.out.println("There is this word in the table.");
                    } else {
                        System.out.println("There is no this word in the table.");
                    }
                    break;
                case "5":
                    System.out.println("Static data:");
                    System.out.println("Element number: " + table.getNumberOfElements());
                    System.out.println("Conflict number: " + table.getNumberOfConflicts());
                    System.out.println("Load factor: " + table.getLoadFactor());
                    System.out.println("Empty rows: " + table.countEmptyRows());
                    System.out.println("Maximal list length: " + table.getMaxLengthList());
                    break;
            }
            System.out.println("Successfully.");
            System.out.print("Print next command: ");
            chosenFunction = input.next();
        }
    }
}
