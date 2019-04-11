package g144.krylova;

/**
 * Class containing hash function calculating with polynomial.
 */
public class PolynomialHasher implements Hasher<String> {
    /**
     * {@inheritDoc}
     */
    @Override
    public int hashFunction(String value, int module) {
        int prime = 47;
        int key = 0;
        for (int i = 0; i < value.length(); i++){
            key = ((key * prime) % module + value.charAt(i) % module) % module;
        }
        return key;
    }
}
