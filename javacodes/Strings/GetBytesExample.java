package Strings;

import java.io.UnsupportedEncodingException;

public class GetBytesExample{
    public static void main(String[] args) throws UnsupportedEncodingException {
        String str = "javaguides";

        // Encodes this String into a sequence of bytes using the platform's
        // default charset, storing the result into a new byte array.
        byte[] bs = str.getBytes();
        for (byte b: bs) {
            System.out.println(b);
        }

        
    }
}