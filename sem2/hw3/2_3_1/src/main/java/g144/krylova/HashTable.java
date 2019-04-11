package g144.krylova;

import java.util.ArrayList;

public class HashTable {
    private ArrayList<ArrayList<String>> table;
    private Hasher hasher;

    private int numberOfElements = 0;
    private int numberOfConflicts = 0;

    HashTable(int size, Hasher hashFunction){
        table = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            table.add(new ArrayList<>());
        }
        this.hasher = hashFunction;
    }

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

    public int countEmptyRows() {
        int result = 0;
        for (ArrayList currentList : table) {
            if (currentList.size() == 0){
                result++;
            }
        }
        return result;
    }

    public int getMaxLengthList() {
        int result = 0;
        for (ArrayList currentList : table) {
            result = Math.max(result, currentList.size());
        }
        return result;
    }
}











