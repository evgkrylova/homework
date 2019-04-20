package g144.krylova;

/**
 * Interface containing main methods for working with stack.
 * @param <ElementType> is type of elements.
 */
public interface Hasher<ElementType> {
    /**
     * Method calculating a hash key for the element.
     * @param value is value to get hash.
     * @return integer value of hash key.
     */
    int hashFunction(ElementType value, int module);
}
