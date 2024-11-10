import java.util.Scanner;
import java.security.MessageDigest;
class hash
{
public static void main(String[] args) {
try
{
System.out.println("Enter a message to hash");
Scanner sc=new Scanner(System.in);
String message=sc.nextLine();
MessageDigest md=MessageDigest.getInstance("SHA-256");
byte[]hash=md.digest(message.getBytes());
for(byte b:hash)
System.out.print(String.format("%02x",b));
}
catch(Exception e )
{
System.out.println("Errror");
}
}
}
