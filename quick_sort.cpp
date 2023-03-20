int partition(int array[], unsigned lowIndex, unsigned highIndex) {
    //1, choose pivot
    unsigned middlePoint = (lowIndex + highIndex) / 2;
    int pivot = array[middlePoint];
    while (1) {
        //2, increment the highIndex and decrement the lowIndex
        while (array[lowIndex] < pivot) {
            lowIndex++;
        }
        while (array[highIndex] > pivot) {
            highIndex--;
        }
        if (lowIndex >= highIndex) {
            return highIndex;
        }
        else {
            //3, swap the high and low index
            int temp = array[lowIndex];
            array[lowIndex] = array[highIndex];
            array[highIndex] = temp;
            lowIndex++;
            highIndex--;
        }
    }
}

void quickSort(int array[], unsigned lowIndex, unsigned highIndex) {
    if (lowIndex >= highIndex) {
        return;
    }
    unsigned lowEndIndex = partition(array, lowIndex, highIndex);
    quickSort(array, lowIndex, lowEndIndex);
    quickSort(array, lowEndIndex + 1, highIndex);
}