
import java.io.*;
class ShowFileMultiple {
public static void main(String args[])
{
int i;
// First, confirm that a filename has been specified.
if(args.length != 2) {
System.out.println("Usage: ShowFile filename");
return;
}
// Attempt to open the file.
try ( FileInputStream fin = new FileInputStream(args[0]);FileOutputStream fout = new FileOutputStream(args[1]))
{
do {
i = fin.read();
if(i != -1) fout.write(i);
} while(i != -1);
} catch(IOException e) {
System.out.println("Error Reading File");
}

}
}
