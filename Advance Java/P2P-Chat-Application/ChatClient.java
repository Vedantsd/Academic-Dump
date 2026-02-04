import java.net.*;
import java.io.*;
import java.util.*;

public class ChatClient {
    public static void main(String[] args) throws Exception{
        Socket socket = new Socket("localhost", 5000);
        DataOutputStream outputstream = new DataOutputStream(socket.getOutputStream());
        DataInputStream dis = new DataInputStream(socket.getInputStream());
        Scanner sc = new Scanner(System.in);
        String msg = "";

        while (!msg.equals("/exit")) {
            System.out.print("Enter message : ");
            msg = sc.nextLine();
            outputstream.writeUTF(msg);
            String data = dis.readUTF();
            System.out.println("Server says : " + data);
        }

        outputstream.close();
        socket.close();
    }
}
