/*
 * Kehittyneet ohjelmointikielet, Java harjoitustyö
 * Minna Hannula
 */

/*
 * Train
 * Pre: None
 * Post: Train luokka, jossa määritellään junaan liittyvät muuttujat
 */
public class Train {
    private int trainNumber;
    private String departureDate;
    private String timestamp;
    private int speed;

    public Train(int trainNumber, String departureDate, String timestamp, int speed) {
        this.trainNumber = trainNumber;
        this.departureDate = departureDate;
        this.timestamp = timestamp;
        this.speed = speed;
    }

    public int getTrainNumber() {
        return trainNumber;
    }
    public void setTrainNumber(int trainNumber) {
        this.trainNumber = trainNumber;
    }
    public String getDepartureDate() {
        return departureDate;
    }
    public void setDepartureDate(String departureDate) {
        this.departureDate = departureDate;
    }
    public String getTimestamp() {
        return timestamp;
    }
    public void setTimestamp(String timestamp) {
        this.timestamp = timestamp;
    }
    public int getSpeed() {
        return speed;
    }
    public void setSpeed(int speed) {
        this.speed = speed;
    }

    @Override
    public String toString() {
        return "Train{" +
                "trainNumber=" + trainNumber +
                ", departureDate='" + departureDate + '\'' +
                ", timestamp='" + timestamp + '\'' +
                ", speed=" + speed +
                '}';
    }
}
