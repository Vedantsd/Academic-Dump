import java.util.*;
import java.sql.*;

class Student {

    Connection conn;

    void connectDB() {
        try {
            Class.forName("com.mysql.cj.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/studentData", "root", "helloworld");
            System.out.println("Connection Established");

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void createTable() {
        try {
            Statement stmt = conn.createStatement();
            String sql = "CREATE TABLE if not exists Student (" +
                    "PRN VARCHAR(12) PRIMARY KEY, " +
                    "RollNo INT, " +
                    "Name VARCHAR(50))";

            stmt.executeUpdate(sql);
            System.out.println("Table Created");

        } catch (Exception e) {
            System.out.println(e);
        }
    }


    void insert(String PRN, int rollno, String name) {
        try {
            String sql = "INSERT INTO Student (PRN, RollNo, Name) VALUES (?, ?, ?)";
            PreparedStatement ps = conn.prepareStatement(sql);

            ps.setString(1, PRN);
            ps.setInt(2, rollno);
            ps.setString(3, name);

            ps.executeUpdate();
            System.out.println("Inserted successfully");

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void update(String PRN, int rollno, String name) {
        try {
            String sql = "UPDATE Student SET RollNo = ?, Name = ? WHERE PRN = ?";
            PreparedStatement ps = conn.prepareStatement(sql);

            ps.setInt(1, rollno);
            ps.setString(2, name);
            ps.setString(3, PRN);

            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("Record updated successfully");
            } else {
                System.out.println("No record found with PRN: " + PRN);
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void delete(String PRN) {
        try {
            String sql = "DELETE FROM Student WHERE PRN = ?";
            PreparedStatement ps = conn.prepareStatement(sql);

            ps.setString(1, PRN);

            int rows = ps.executeUpdate();

            if (rows > 0) {
                System.out.println("Record deleted successfully");
            } else {
                System.out.println("No record found with PRN: " + PRN);
            }

        } catch (Exception e) {
            System.out.println(e);
        }
    }

    void display() {
        try {
            Statement stmt = conn.createStatement();
            String sql = "Select * from Student";
            ResultSet set = stmt.executeQuery(sql);

            while (set.next()) {
                System.out.println(set.getString("PRN") + " " + set.getInt("RollNo") + " " + set.getString("Name"));
            }
        } catch (Exception e) {
            System.out.println(e);
        }
    }
}

public class prac2 {

    public static void main(String[] args) {
        Student stud = new Student();
        stud.connectDB();
        stud.createTable();
        boolean flag = true;
        String prn, name;
        int roll;

        Scanner sc = new Scanner(System.in);

        while (flag) {
            System.out.println("Menu : ");
            System.out.println("1. Insert Data");
            System.out.println("2. Update Data");
            System.out.println("3. Delete Data");
            System.out.println("4. Display Data");
            System.out.println("5. Exit");
            System.out.println("Enter your choice : ");
            int n = sc.nextInt();

            switch (n) {
                case 1 :
                    sc.nextLine();
                    System.out.println("Enter PRN : ");
                    prn = sc.nextLine();
                    System.out.println("Enter Roll number : ");
                    roll = sc.nextInt();
                    sc.nextLine();
                    System.out.println("Enter name : ");
                    name = sc.nextLine();
                    stud.insert(prn, roll, name);

                    break;

                case 2 :
                    sc.nextLine();
                    System.out.println("Enter PRN to update : ");
                    prn = sc.nextLine();
                    System.out.println("Enter Roll number to set : ");
                    roll = sc.nextInt();
                    sc.nextLine();
                    System.out.println("Enter name to set : ");
                    name = sc.nextLine();
                    stud.update(prn, roll, name);

                    break;

                case 3 :
                    sc.nextLine();
                    System.out.println("Enter PRN to delete : ");
                    prn = sc.nextLine();
                    stud.delete(prn);
                    break;

                case 4 :
                    stud.display();
                    break;

                case 5 :
                    System.out.println("Quitting program...");
                    flag = false;

                default :
                    System.out.println("Invalid input");
            }
        }

        sc.close();
    }
}
