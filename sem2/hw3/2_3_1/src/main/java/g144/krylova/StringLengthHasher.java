package g144.krylova;

/**
 * Class containing hash function calculating with sum of each symbol code.
 */
public class StringLengthHasher implements Hasher<String> {
    /**
     * {@inheritDoc}
     */
    @Override
    public int hashFunction(String value, int module) {
        int prime = 23;
        int key = value.length() * prime;
        return key % module;
    }
}
