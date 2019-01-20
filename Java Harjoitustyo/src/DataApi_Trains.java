/*
* Kehittyneet ohjelmointikielet, Java harjoitustyö
* Minna Hannula
*/
import com.google.gson.*;
import javax.net.ssl.HttpsURLConnection;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.URL;

/*
* DataApi_Trains
* Pre: None
* Post: Haetaan data verkosta ja Sijoitetaan String[] train muuttujaan.
* Säikeen delay 10s, eli 10s välein data päivitetään
* Säikeessä kutsutaan Print luokkaa, joka tulostaa datan
*/
public class DataApi_Trains implements Runnable{
    String url;
    Print trainPrint = new Print();
    int index =0;
    String[] train = new String[100000];
    DataApi_Trains(String url){
        this.url = url;
    }

    @Override
    public void run() {
        trainPrint.setPaused(true);
        trainPrint.Frame();
        while (trainPrint.getPaused() == true) {
            try {
                HttpsURLConnection connection = (HttpsURLConnection) new URL(url).openConnection();
                connection.setRequestMethod("GET");
                BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder stringBuilder = new StringBuilder();
                String input;
                while ((input = bufferedReader.readLine()) != null) {
                        stringBuilder.append(input);
                    }
                    bufferedReader.close();
                    connection.disconnect();

                    JsonParser parser = new JsonParser();
                    JsonArray jsonArray = parser.parse(stringBuilder.toString()).getAsJsonArray();
                    Train[] trains = new Gson().fromJson(jsonArray.getAsJsonArray(), Train[].class);
                    for (Train t : trains) {
                        train[index++] = ("ID: " + t.getTrainNumber() + ", Departure Date: " + t.getDepartureDate() + ",  Time stamp: " +
                                    t.getTimestamp() + ", Speed: " + t.getSpeed() +"\n");
                            for(int i=0; i<index;i++){
                                trainPrint.setTrain(String.valueOf(train[i]));
                            }
                        trainPrint.text();
                    }
                Thread.sleep(10000);
            } catch (IOException ex) {
                System.out.println(ex);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}
