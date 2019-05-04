package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class ListStackTest {

    @Test
    void pushTest() throws EmptyStackException{
        ListStack<Integer> stack = new ListStack<>();
        for (int i = 1; i <= 10; i++) {
            stack.push(i);
        }

        for (int i = 10; i > 5; i--) {
            assertEquals(i, (int)(stack.pop()));
        }
    }

    @Test
    void topTest() throws EmptyStackException{
        ListStack<Integer> stack = new ListStack<>();
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }
        assertEquals(5, (int)(stack.top()));
    }

    @Test
    void getLengthTest() {
        ListStack<Integer> stack = new ListStack<>();
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }
        assertEquals(5, stack.getLength());
    }

    @Test
    void popTest() throws EmptyStackException{
        ListStack<Integer> stack = new ListStack<>();
        for (int i = 1; i <= 5; i++) {
            stack.push(i);
        }

        for (int i = 5; i > 0; i--) {
            assertEquals(i, (int)(stack.pop()));
        }
    }

    @Test
    void popFromEmptyTest() throws EmptyStackException{
        ListStack<Integer> stack = new ListStack<>();
        assertThrows(EmptyStackException.class, () ->
                stack.pop());
    }
}