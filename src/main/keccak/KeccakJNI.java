package keccak;

import java.nio.ByteBuffer;
import java.util.Arrays;

public class KeccakJNI {
   static {
      System.loadLibrary("keccak"); // Load native library at runtime
                                   // hello.dll (Windows) or libhello.so (Unixes)
   }


   public static native byte[] keccak_sha3(byte[] input);

   public static native void keccak_sha3_2(ByteBuffer input, ByteBuffer output, int size);


   // Test Driver
   public static void main(String[] args) {

       ByteBuffer input = ByteBuffer.allocateDirect(1);
       input.put(0, (byte)1);

       ByteBuffer output = ByteBuffer.allocateDirect(32);

       keccak_sha3_2(input, output, 1);

       byte[] result = new byte[32];
       output.get(result);

       System.out.println(result[0]);

//	   System.out.println(output);
   }
}