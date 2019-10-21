import java.io.*;
import java.net.*; // contains Socket-related classes
import java.util.*; // java.util.Scanner
public class EchoClient {
    public EchoClient() {
        make();
    }
    private BufferedReader br;
    private PrintWriter pw;
    public void make() {

        try {
            Socket s = new Socket("localhost", 8000);
            System.out.println(s.getInetAddress() + " " + s.getPort()) ;
            System.out.println(s.getLocalAddress().getHostAddress() + " " + s.getLocalPort());
            try {
                InputStream inStream = s.getInputStream();
                OutputStream outStream = s.getOutputStream();
                Scanner in = new Scanner(System.in);
                Scanner input = new Scanner(inStream);
                PrintWriter out = new PrintWriter(outStream, true /* autoFlush */);
                String line = input.nextLine();
                System.out.println(line);
                String msg = "";
                while (!msg.equalsIgnoreCase("bye")) {
                    while (!msg.equalsIgnoreCase("disconnect")) {
                        msg = in.nextLine();
                        if (!msg.equalsIgnoreCase("disconnect")) {
                            out.println(msg);
                            line = input.nextLine();
                            System.out.println(line);
                        }
                        else {
                            out.println("Server disconnected");
                        }

                    }
                    while (!msg.equalsIgnoreCase("connect")) {
                        msg= in.nextLine();
                    }

                }
            }
            finally { s.close(); } // void close() throws IOException; Closes this socket.
        }
        catch ( IOException e ) { e.printStackTrace(); }
// UnknownHostException is a subclass of IOException
    }
    public static void main(String[] args) {
        new EchoClient();
    }
}