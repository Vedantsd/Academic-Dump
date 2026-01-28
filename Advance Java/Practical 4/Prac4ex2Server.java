import java.net.*;
import java.io.*;

public class Prac4ex2Server {
    public static void main(String[] args) throws Exception{
        ServerSocket serversocket = new ServerSocket(5000);
        Socket socket = serversocket.accept();
        DataInputStream dis = new DataInputStream(socket.getInputStream());

        String msg = dis.readUTF();
        System.out.println("Client Says : " + msg);

        serversocket.close();
    }
}
