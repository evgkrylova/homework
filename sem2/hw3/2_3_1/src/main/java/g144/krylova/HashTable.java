package g144.krylova;

import java.util.ArrayList;

/**
 * Class realising a hash table.
 */
public class HashTable {
    private ArrayList<ArrayList<String>> table;
    private Hasher hasher;

    private int numberOfElements = 0;
    private int numberOfConflicts = 0;

    /**
     * Constructor for a hash table.
     * @param size is the capacity of the table.
     * @param hashFunction is the chosen way to calculatng hash function.
     */
    HashTable(int size, Hasher hashFunction){
        table = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            table.add(new ArrayList<>());
        }
        this.hasher = hashFunction;
    }

    /**
     * Method adding an element to the table.
     * @param value is an element to add.
     * @throws DuplicateValueException if the element is already in table.
     */
    public void add(String value) throws DuplicateValueException{
        int key = hasher.hashFunction(value, table.size());
        ArrayList currentList = table.get(key);
        if (currentList.contains(value)){
            throw new DuplicateValueException();
        } else {
            if (currentList.size() > 0) {
                numberOfConflicts++;
            }
            numberOfElements++;
            currentList.add(value);
        }
    }

    /**
     * Method removing an element from the table.
     * @param value is an element to remove.
     * @throws NotExistingValueException if the element is not in table.
     */
    public void remove(String value) throws  NotExistingValueException{
        int key = hasher.hashFunction(value, table.size());
        ArrayList currentList = table.get(key);
        if (currentList.contains(value)){
            currentList.remove(value);
            numberOfElements--;
            if (currentList.size() == 1){
                numberOfConflicts--;
            }
        } else {
            throw new NotExistingValueException();
        }
    }

    /**
     * Method checking an existence of the element in table.
     * @param value is an element to remove.
     */
    public boolean contains(String value){
        int key = hasher.hashFunction(value, table.size());
        ArrayList currentList = table.get(key);
        return currentList.contains(value);
    }

    public double getLoadFactor(){
        return numberOfElements / table.size();
    }

    public int getNumberOfElements(){
        return numberOfElements;
    }

    public int getNumberOfConflicts(){
        return numberOfConflicts;
    }

    /**
     * Method counting empty rows in table.
     */
    public int countEmptyRows() {
        int result = 0;
        for (ArrayList currentList : table) {
            if (currentList.size() == 0){
                result++;
            }
        }
        return result;
    }

    /**
     * Method finding for the maximal length of list in table.
     */
    public int getMaxLengthList() {
        int result = 0;
        for (ArrayList currentList : table) {
            result = Math.max(result, currentList.size());
        }
        return result;
    }
}
