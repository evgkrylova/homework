package g144.krylova;

public class Main {
    public static void main(String[] args) {
        List list = new List();

        list.addElement(0);
        for (int i = 1; i <= 10; i++) {
            list.addElement(i, list.getLength() - 1);
        }

        list.print();

        System.out.println();
        System.out.println("Removing element: " + list.getElement(5));
        list.removeElement(5);

        list.print();
    }
}
