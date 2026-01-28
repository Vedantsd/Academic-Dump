import java.io.*;
import java.net.*;

class URLInfo {
    final private String website;
    URLInfo(String website) {
        this.website = website;
    }

    void getIP() {
        try {
            InetAddress addr = InetAddress.getByName(new URL(website).getHost());

            System.out.println("IP Address of " + website + " : " + addr.getHostAddress());

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

    void getContent() {
        try {
            URL url = new URL(website);
            BufferedReader br = new BufferedReader(new InputStreamReader(url.openStream()));

            System.out.println("Content of website :\n");
            String line;
            while ((line = br.readLine()) != null) {
                System.out.println(line);
            }

            br.close();

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }
}

public class Prac4ex1 {
    public static void main(String[] args) {

        URLInfo obj = new URLInfo("https://memotape.vercel.app");
        obj.getIP();
        obj.getContent();
    }
}
