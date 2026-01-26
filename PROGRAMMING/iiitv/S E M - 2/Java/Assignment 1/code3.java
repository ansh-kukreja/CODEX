public class code3 {
    public static void main(String[] args) {
        int[][] a = {
            {1, 2, 3},
            {4, 5, 6}
        };

        int[][] b = {
            {7, 8, 9},
            {1, 2, 3}
        };

        int[][] c = {
            {1, 2},
            {3, 4},
            {5, 6}
        };

        System.out.println("\nAddition:");
        printMatrix(addMatrices(a, b));

        System.out.println("\nMultiplication:");
        printMatrix(multiplyMatrices(a, c));
    }

    static int[][] addMatrices(int[][] a, int[][] b) {
        int rows = a.length;
        int cols = a[0].length;

        int[][] sum = new int[rows][cols];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                sum[i][j] = a[i][j] + b[i][j];
            }
        }
        return sum;
    }

    static int[][] multiplyMatrices(int[][] a, int[][] b) {
        int r1 = a.length;
        int c1 = a[0].length;
        int c2 = b[0].length;

        int[][] result = new int[r1][c2];

        for (int i = 0; i < r1; i++) {
            for (int j = 0; j < c2; j++) {
                for (int k = 0; k < c1; k++) {
                    result[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        return result;
    }

    static void printMatrix(int[][] mat) {
        for (int[] row : mat) {
            for (int val : row) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
    }
}
