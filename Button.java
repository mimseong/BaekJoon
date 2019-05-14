package test_button;

import java.awt.Button;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;
import java.awt.Panel;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

//가로 : 768 세로: 480
public class MainUI {
    private Frame mainFrame;
    private Label headerLabel;
    private Label statusLabel;
    private Panel controlPanel;
 
    public MainUI() {
        prepareGUI();
    }
 
    public static void main(String[] args) {
    	MainUI mainButtonControl = new MainUI();
        mainButtonControl.showButton();
    }
 
    private void prepareGUI() {
        mainFrame = new Frame("Rhythm Catchball ^.^");
        mainFrame.setSize(768, 480);
        mainFrame.setLayout(new GridLayout(5, 1));
        mainFrame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent windowEvent) {
                System.exit(0);
            }
        });
 
        headerLabel = new Label();
        headerLabel.setAlignment(Label.CENTER);
        headerLabel.setText("~~ Rhythm Catchball ~~~");
 
        statusLabel = new Label();
        statusLabel.setText("Status Lable");
        statusLabel.setAlignment(Label.CENTER);
        statusLabel.setSize(350, 100);
 
        controlPanel = new Panel();
        controlPanel.setLayout(new FlowLayout());
 
        mainFrame.add(headerLabel);
        mainFrame.add(controlPanel);
        mainFrame.add(statusLabel);
        mainFrame.setVisible(true);
    }
 
    private void showButton() {
 
        Button onePlay = new Button("1p GAME PLAY");
        Button twoPlay = new Button("2p GAME PLAY");
        Button onlinePlay = new Button("Online GAME PLAY");
        Button preference = new Button("PREFERENCE");
        Button close = new Button("CLOSE");
 
        //여기서 버튼 클릭되었을 때 행동 함
        onePlay.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("onePlay Button clicked.");
            }
        });
 
        twoPlay.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("twoPlay Button clicked.");
            }
        });
 
        onlinePlay.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("onlinePlay Button clicked.");
            }
        });
 
        preference.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("preference Button clicked.");
            }
        });

        close.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("close Button clicked.");
            }
        });

        controlPanel.add(onePlay);
        controlPanel.add(twoPlay);
        controlPanel.add(onlinePlay);
        controlPanel.add(preference);
        controlPanel.add(close);
 
        mainFrame.setVisible(true);
 
    }
}