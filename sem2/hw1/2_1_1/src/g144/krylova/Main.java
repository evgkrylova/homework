package g144.krylova;

public class Main {

    public static void main(String[] args) {
        Stack stack = new Stack();

        for (int i = 1; i <= 10; i++) {
            stack.push(i);
        }

        System.out.println("Length: " + stack.getLength());
        System.out.println("Popped element: " + stack.pop());
        System.out.println("Top element: " + stack.top());

        for (int i = 1; i < 10; i++) {
            System.out.print(stack.pop() + " ");
        }
    }
}