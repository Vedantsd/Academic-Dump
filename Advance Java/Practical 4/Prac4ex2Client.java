import java.net.*;
import java.io.*;
import java.util.*;

public class Prac4ex2Client {
    public static void main(String[] args) throws Exception{
        Socket socket = new Socket("localhost", 5000);
        DataOutputStream outputstream = new DataOutputStream(socket.getOutputStream());

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter message : ");
        String msg = sc.nextLine();

        outputstream.writeUTF(msg);
        outputstream.close();
        socket.close();
    }
}
