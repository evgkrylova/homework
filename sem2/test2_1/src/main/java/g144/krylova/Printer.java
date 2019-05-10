package g144.krylova;

import java.util.Scanner;

public class Printer {
    SortedSet set = new SortedSet();

    public void readSet(Scanner input){
        while (input.hasNext()) {
            set.add(input.next());
        }
    }

}
