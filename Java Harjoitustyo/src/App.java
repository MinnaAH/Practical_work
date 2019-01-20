/*
 * Kehittyneet ohjelmointikielet, Java harjoitustyö
 * Minna Hannula
 */

import javax.swing.*;

/*
 * App
 * Pre: None
 * Post: App luokassa pyöritetään ohjelma valintaikkunan avulla
 * Valinta 1: Haetaan kaikkien junien tiedot
 * Valinta 2: Haetaan vain yhden junan tiedot. Haettavan junan numero syötetään ja lisätään url osoitteeseen
 * Valinta 3: Lopettaa ohjelman
 */
public class App {
    public static void main(String[] args) {
        String choice, train;
        do {
            choice = JOptionPane.showInputDialog(null, "1. Get data from latest trains \n " +
                    "2. Get data from one train \n " +
                    "3. Exit program \n ");
            if(choice.equals("1")) {
                String url = "https://rata.digitraffic.fi/api/v1/train-locations/latest/";
                DataApi_Trains dataApi = new DataApi_Trains(url);
                Thread dataThread = new Thread(dataApi);
                dataThread.start();
                while (dataThread.isAlive()) {
                    System.out.println("Searching..");
                    try {
                        Thread.sleep(1000);
                    }
                    catch (InterruptedException ex) {
                        Thread.currentThread().interrupt();
                    }
                }
            }
            else if (choice.equals("2")) {
                train = JOptionPane.showInputDialog(null, "Enter the train number" );
                String url = "https://rata.digitraffic.fi/api/v1/train-locations/latest/"+ train;
                DataApi_Trains dataApi = new DataApi_Trains(url);
                Thread dataThread = new Thread(dataApi);
                dataThread.start();
                while (dataThread.isAlive()) {
                    System.out.println("Searching..");
                    try {
                        Thread.sleep(1000);
                    }
                    catch (InterruptedException ex) {
                        Thread.currentThread().interrupt();
                    }
                }
            }
        }while(!choice.equals("3"));
    }
}

