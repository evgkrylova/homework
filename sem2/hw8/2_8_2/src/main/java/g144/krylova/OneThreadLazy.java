package g144.krylova;

import java.util.function.Supplier;

public class OneThreadLazy<T> implements Lazy<T> {
    private T value = null;
    private Supplier<T> expression;

    /**
     * {@inheritDoc}
     */
    @Override
    public T get() {
        if (expression != null) {
            value = expression.get();
            expression = null;
        }
        return value;
    }

    public OneThreadLazy(Supplier<T> expression) {
        this.expression = expression;
    }
}
