package g144.krylova;

/**
 * Class containing methods for work with a singly linked list.
 */
public class UniqueList<Type> extends List<Type>{
    /**
     * {@inheritDoc}
     */
    @Override
    public void addElement(Type value) throws DuplicateElementException {
        if (isElementInList(value)){
            throw new DuplicateElementException();
        }
        else{
            super.addElement(value);
        }
    }

    /**
     * {@inheritDoc}
     */
    @Override
    public void addElement(Type value, int n) throws DuplicateElementException {
        if (isElementInList(value)){
            throw new DuplicateElementException();
        }
        else{
            super.addElement(value, n);
        }
    }
}
