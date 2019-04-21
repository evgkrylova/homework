package g144.krylova;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class QueueTest {

    @Test
    void enqueueTest() throws EmptyQueueException{
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(2, 2);
        queue.enqueue(5, 5);
        queue.enqueue(1, 1);
        queue.enqueue(4, 4);
        queue.enqueue(6, 6);
        queue.enqueue(3, 3);

        assertEquals(6, (int)(queue.dequeue()));
        assertEquals(5, (int)(queue.dequeue()));
        assertEquals(4, (int)(queue.dequeue()));
        assertEquals(3, (int)(queue.dequeue()));
        assertEquals(2, (int)(queue.dequeue()));
        assertEquals(1, (int)(queue.dequeue()));
    }

    @Test
    void dequeueFromEmptyTest() {
        Queue<Integer> queue = new Queue<>();
        assertThrows(EmptyQueueException.class, () -> queue.dequeue());
    }

    @Test
    void peekTest() throws EmptyQueueException{
        Queue<Integer> queue = new Queue<>();
        queue.enqueue(2, 2);
        queue.enqueue(5, 5);
        queue.enqueue(1, 1);
        queue.enqueue(4, 4);

        assertEquals(5, (int)(queue.peek()));
    }

    @Test
    void isEmptyTest() {
        Queue<Integer> queue = new Queue<>();
        assertEquals(true, queue.isEmpty());

        queue.enqueue(2, 2);
        queue.enqueue(5, 5);
        assertEquals(false, queue.isEmpty());
    }

    @Test
    void getLengthTest() {
        Queue<Integer> queue = new Queue<>();
        assertEquals(0, queue.getLength());

        queue.enqueue(2, 2);
        queue.enqueue(5, 5);
        assertEquals(2, queue.getLength());
    }
}