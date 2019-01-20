/*
 * Kehittyneet ohjelmointikielet, Java harjoitustyö
 * Minna Hannula
 */

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

/*
 * Print
 * Pre: None
 * Post: Print luokka, jossa käsitellään tulostus, Lopeta painikkeen toiminta
 * sekä lisätään Data_api luokasta data tekstikenttään.
 * Tulostetaan näkyviin aikaisemmat junat sekä uusi juna.
 */
public class Print extends JFrame{
    public String train;
    public boolean paused;

    public boolean getPaused() {
        return paused;
    }
    public void setTrain(String train) {
        this.train = train;
    }
    public void setPaused(boolean paused) {
        this.paused = paused;
    }

    JTextArea t = new JTextArea(10,50);
    JButton b = new JButton("Stop");
    JScrollPane s = new JScrollPane(t, JScrollPane.VERTICAL_SCROLLBAR_ALWAYS, JScrollPane.HORIZONTAL_SCROLLBAR_AS_NEEDED);

    void Frame(){
        setTitle("Train");
        setSize(600,300);
        setLayout(new FlowLayout());
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
        add(s);
        add(b);

        b.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                setPaused(false);
            }
        });
    }
    void text(){
            t.setText(t.getText() + train);
    }
}
