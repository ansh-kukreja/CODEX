public class code2 {
    public static void main(String[] args) {
        int[] arr1 = {10, 20, 30, 40};
        int index = linearSearch(arr1, 40);
        if(index != -1){
            System.out.println("\nElement is at Index: "+index+"\n");
        }
        else{
            System.out.println("\nElement Not Found\n");
        }

        int[] arr2 = {10, 20, 30, 40};
        reverseArray(arr2);
        for (int x : arr2){
            System.out.print(x + " ");
        }

        int[] arr3 = {2, 10, -5, 8};
        System.out.println("\n\nMaximum Absolute Difference is : " + maxAbsoluteDifference(arr3) + "\n");
    }

    static int linearSearch(int[] arr, int num){
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == num){
                return i;
            }
        }
        return -1;
    }

    static void reverseArray(int[] arr) {
        int start = 0, end = arr.length - 1;

        while (start < end) {
            int temp = arr[start];

            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    static int maxAbsoluteDifference(int[] arr) {
        int min = arr[0];
        int max = arr[0];

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < min)
                min = arr[i];
            if (arr[i] > max)
                max = arr[i];
        }

        return Math.abs(max - min);
    }

}
