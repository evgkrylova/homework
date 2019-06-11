package g144.krylova;

import org.junit.jupiter.api.Test;
import java.util.function.Supplier;
import static org.junit.jupiter.api.Assertions.*;

class LazyFactoryTest {

    @Test
    void oneThreadTest() {
        Supplier<Integer> expression = () -> 1;
        Lazy<Integer> lazyObject = LazyFactory.createOneThreadLazy(expression);
        assertEquals(1, (int)lazyObject.get());
        assertEquals(1, (int)lazyObject.get());
    }

    @Test
    void oneThreadNullTest() {
        Supplier<Integer> expression = () -> null;
        Lazy<Integer> lazyObject = LazyFactory.createOneThreadLazy(expression);
        assertEquals(null, lazyObject.get());
        assertEquals(null, lazyObject.get());
    }

    @Test
    void multiThreadTest() throws InterruptedException{
        int THREADS_NUMBER = 1024;
        Supplier<Integer> expression = () -> 1;
        Lazy<Integer> lazyObject = LazyFactory.createOneThreadLazy(expression);

        Thread[] threads = new Thread[THREADS_NUMBER];
        for (int i = 0; i < THREADS_NUMBER; i++) {
            threads[i] = new Thread(() -> assertEquals(1, (int)lazyObject.get()));
        }

        for (int i = 0; i < THREADS_NUMBER; i++) {
            threads[i].start();
        }

        for (int i = 0; i < THREADS_NUMBER; i++) {
            threads[i].join();
        }

        assertEquals(1, (int)lazyObject.get());
    }

    @Test
    void multiThreadNullTest() {
        Lazy<Integer> lazy = LazyFactory.createMultiTreadLazy(() -> null);
        assertNull(lazy.get());
        lazy.get();
        lazy.get();
        assertNull(lazy.get());
        assertNull(lazy.get());
    }
}