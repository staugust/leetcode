package cn.augusto;

public class RotateImage {

  public void rotate(int[][] matrix) {
    int n = matrix.length;
    int tmp = 0;
    for(int i = 0; i != n; i++){
      for(int j = 0; j != i; j++){
        tmp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = tmp;
      }
    }
    for(int j = 0; j != n/2; j++){
      for(int i= 0; i!=n; i++){
        tmp = matrix[i][j];
        matrix[i][j] = matrix[i][n-j-1];
        matrix[i][n-j-1] = tmp;
      }
    }
  }

  public void print(int[][] matrix){
    for(int i= 0; i != matrix.length; i++){
      for(int j =0 ; j != matrix.length; j++){
        System.out.printf("%5d", matrix[i][j]);
      }
      System.out.println();
    }
  }

  public static void main(String[] args) {
    RotateImage r = new RotateImage();
    int[][] matrix = {{1,2,3},{4,5,6},{7,8,9}};
    System.out.println(matrix);
    r.print(matrix);
    r.rotate(matrix);
    System.out.println(matrix);
    r.print(matrix);
  }
}
