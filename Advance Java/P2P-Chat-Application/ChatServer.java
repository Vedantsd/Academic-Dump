import java.net.*;
import java.io.*;
import java.util.Scanner;

public class ChatServer {
    public static void main(String[] args) throws Exception{
        ServerSocket serversocket = new ServerSocket(5000);
        Socket socket = serversocket.accept();

        DataInputStream dis = new DataInputStream(socket.getInputStream());
        DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
        Scanner sc = new Scanner(System.in);

        String msg = "";

        while (!msg.equals("/exit")) {
            msg = dis.readUTF();
            System.out.println("Client Says : " + msg);
            System.out.print("\nEnter a message: ");
            String data = sc.nextLine();
            dos.writeUTF(data);
        }

        dos.close();
        dis.close();
        serversocket.close();
    }
}
