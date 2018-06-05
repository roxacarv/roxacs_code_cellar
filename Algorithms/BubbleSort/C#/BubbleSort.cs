using System;

class MainClass {
    public static void Main (string[] args) {
    int[] newArrayToSort = new int[20];
    Random random = new Random();
    for(int i = 0; i < 20; i++)
        newArrayToSort[i] = random.Next(0, 100);
    
    Console.Write("Un-sorted Array: ");

    for(int i = 0; i < 20; i++)
        Console.Write(newArrayToSort[i] + " ");

    Console.Write("\n\nSorted Array: ");

    int[] sortedArray = new int[20];
    sortedArray = BubbleSort(newArrayToSort);

    for(int i = 0; i < 20; i++)
        Console.Write(sortedArray[i] + " ");
    }

    static int[] BubbleSort(int[] arrayToSort)
    {
        bool change = false;
        for(int i = 0; i < (arrayToSort.Length - 1); i++)
        {
            if(arrayToSort[i] > arrayToSort[i+1])
            {
                int bufferElement = arrayToSort[i];
                arrayToSort[i] = arrayToSort[i+1];
                arrayToSort[i+1] = bufferElement;
                change = true;
            }
        }
        if(change)
            return BubbleSort(arrayToSort);
        else
            return arrayToSort;
    }

}