package g144.krylova;

import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveAction;

/**
 * Class containing realization of the multi thread algorithm of the quick dorter.
 */
public class MultiThreadSorter implements QuickSorter {
    /**
     * {@inheritDoc}
     */
    @Override
    public void sort(int[] array, int left, int right) {
        new ForkJoinPool().invoke(new MultiSorter(array, 0, array.length - 1));
    }

    private class MultiSorter extends RecursiveAction {
        private int[] array;
        private int left;
        private int right;

        /**
         * Constructor for a multi sorter of the array.
         * @param array is array to sort.
         * @param left is left interval bound.
         * @param right is right interval bound.
         */
        public MultiSorter(int[] array, int left, int right) {
            this.array = array;
            this.left = left;
            this.right = right;
        }

        /**
         * Method swapping two elements of the array.
         * @param i is the first element index.
         * @param j is the second element index.
         */
        private void swap(int i, int j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        /**
         * Method realizing computing of the multi thread sorter.
         */
        @Override
        protected void compute() {
            if (left >= right) {
                return;
            }
            int i = left;
            int j = right;
            int pivot = array[(i + j) / 2];

            while (i <= j) {
                while (array[i] < pivot) {
                    i++;
                }
                while (array[j] > pivot) {
                    j--;
                }

                if ((i <= j) && (array[i] >= array[j])) {
                    swap(i, j);
                    i++;
                    j--;
                }
            }
            MultiSorter taskRight = new MultiSorter(array, i, right);
            MultiSorter taskLeft = new MultiSorter(array, left, j);

            taskRight.fork();
            taskLeft.compute();
            taskRight.join();
        }
    }
}