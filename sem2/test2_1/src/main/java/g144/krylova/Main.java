package g144.krylova;

import java.util.Scanner;
import java.util.LinkedList;

/**
 * Program reading the arrays of strings from the file, setting it in the order and printing after all.
 */
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner("input.txt");
        SortedSet set = new SortedSet();
        LinkedList<String> list = new LinkedList<>();
        String currentWord;
        while (input.hasNext()){
            currentWord = input.next();
            while (currentWord != "\n") {
                list.add(currentWord);
            }
            set.addList(list);
            list.clear();
        }
        set.print();
    }
}
