package g144.krylova;

import java.util.function.Supplier;

/**
 * Class containing the realization of creating the lazy evaluation object.
 */
public class LazyFactory {

    /**
     * Method creating the lazy object working with an only thread.
     * @param expression is the expression to calculate.
     * @param <T> is the type of the resulted value.
     * @return the result of the evaluation.
     */
    public static <T> Lazy<T> createOneThreadLazy(Supplier<T> expression) {
        return new OneThreadLazy<>(expression);

    }

    /**
     * Method creating the lazy object working with several threads.
     * @param expression is the expression to calculate.
     * @param <T> is the type of the resulted value.
     * @return the result of the evaluation.
     */
    public static <T> Lazy<T> createMultiTreadLazy(Supplier<T> expression) {
        return new MultiThreadLazy<>(expression);
    }
}