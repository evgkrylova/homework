package g144.krylova;

/**
 * Class containing realization of the lazy evaluation.
 * @param <T> is the type of resulted value.
 */
public interface Lazy<T> {

    /**
     * Method calculating the express or returning the calculated value earlier.
     * @return the result of the evaluation.
     */
    T get();
}