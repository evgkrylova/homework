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
        return new Lazy<>() {
            private T result = null;
            private boolean alsoHasAnswer = false;

            @Override
            public T get() {
                if (!alsoHasAnswer) {
                    result = expression.get();
                    alsoHasAnswer = true;
                }
                return result;
            }
        };
    }


    /**
     * Method creating the lazy object working with several threads.
     * @param expression is the expression to calculate.
     * @param <T> is the type of the resulted value.
     * @return the result of the evaluation.
     */
    public static <T> Lazy<T> createMultiThreadLazy(Supplier<T> expression) {
        return new Lazy<>() {
            private T result = null;
            private boolean alsoHasAnswer = false;

            @Override
            public T get() {
                if (!alsoHasAnswer) {
                    synchronized (this) {
                        if (!alsoHasAnswer) {
                            result = expression == null ? null : expression.get();
                            alsoHasAnswer = true;
                        }
                    }
                }
                return result;
            }
        };
    }
}