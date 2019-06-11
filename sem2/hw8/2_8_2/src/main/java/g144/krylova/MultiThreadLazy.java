package g144.krylova;

import java.util.function.Supplier;

public class MultiThreadLazy<T> implements Lazy<T> {

    private volatile T value = null;
    private volatile Supplier<T> expression;

    /**
     * {@inheritDoc}
     */
    @Override
    public T get() {
        if (expression != null) {
            synchronized (this) {
                if (expression != null) {
                    value = expression.get();
                    expression = null;
                }
            }
        }
        return value;
    }

    public MultiThreadLazy(Supplier<T> expression) {
        this.expression = expression;
    }
}