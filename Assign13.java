import java.util.HashMap;
import java.util.Scanner;

public class Assign13 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashMap<String, Integer> dictionary = new HashMap<>();

        while (true) {
            System.out.println("Menu:");
            System.out.println("1. Add an entry");
            System.out.println("2. Remove an entry");
            System.out.println("3. Display all entries");
            System.out.println("4. Exit");
            System.out.print("Enter your choice: ");
            
            int choice = scanner.nextInt();
            scanner.nextLine(); 
            
            switch (choice) {
                case 1:
                    System.out.print("Enter key: ");
                    String key = scanner.nextLine();
                    System.out.print("Enter value: ");
                    int value = scanner.nextInt();
                    dictionary.put(key, value);
                    System.out.println("Entry added successfully!");
                    break;
                case 2:
                    System.out.print("Enter key to remove: ");
                    String keyToRemove = scanner.nextLine();
                    if (dictionary.containsKey(keyToRemove)) {
                        dictionary.remove(keyToRemove);
                        System.out.println("Entry removed successfully!");
                    } else {
                        System.out.println("Key not found!");
                    }
                    break;
                case 3:
                    System.out.println("Current entries:");
                    for (String k : dictionary.keySet()) {
                        System.out.println(k + ": " + dictionary.get(k));
                    }
                    break;
                case 4:
                    System.out.println("Exiting program...");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice! Please enter a number between 1 and 4.");
            }
        }
    }
}
