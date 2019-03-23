package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ArrayStackTest {

    @Test
    void pushTest() throws EmptyStackException{
        ArrayStack<Integer> stack = new ArrayStack<>();
        for (int i = 1; i <= 10; i++) {
            stack.push(i);
        }

        for (int i = 10; i > 5; i--) {
            assertEquals(i, (int)(stack.pop()));
        }
    }

    @Test
    void topTest() throws EmptyStackException{
        ArrayStack<Integer> stack = new ArrayStack<>();
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }
        assertEquals(5, (int)(stack.top()));
    }

    @Test
    void getLengthTest() {
        ArrayStack<Integer> stack = new ArrayStack<>();
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }
        assertEquals(5, stack.getLength());
    }

    @Test
    void popTest() throws EmptyStackException{
        ArrayStack<Integer> stack = new ArrayStack<>();
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }

        for (int i = 5; i > 0; i--) {
            assertEquals(i, (int)(stack.pop()));
        }
    }

    @Test
    void popFromEmptyTest() throws EmptyStackException{
        ArrayStack<Integer> stack = new ArrayStack<>();
        assertThrows(EmptyStackException.class, () ->
            stack.pop());
    }
}