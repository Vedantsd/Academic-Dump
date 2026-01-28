import java.net.*;
import java.util.*;

public class Prac4ex3Sender {
    public static void main(String[] args) throws Exception{
        DatagramSocket socket = new DatagramSocket();

        System.out.print("Enter message : ");
        Scanner sc = new Scanner(System.in);
        String msg = sc.nextLine();

        byte[] buffer = msg.getBytes();

        InetAddress addr = InetAddress.getByName("localhost");

        DatagramPacket packet = new DatagramPacket(buffer, buffer.length, addr, 5000);

        socket.send(packet);
        socket.close();
    }
}
