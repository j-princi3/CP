class immutable {
  private int length;
  private int width;
  
  immutable(int l, int w) { 
    length = l;
    width = w;
  }
  int getLength() {
    return length;
  }
  int getWidth() {
    return width;
  }
  boolean isSquare() {
    return length == width;
  }
}
 
class test {
  public static void main(String [] args) {
    immutable obj = new immutable(10,10);
    System.out.println(obj.getLength());
    System.out.println(obj.getWidth());
    System.out.println(obj.isSquare());
  }
}