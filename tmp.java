package test_button;

import java.awt.Frame;
import java.awt.Lable;
import java.awt.Panel;
import java.awt.TextField;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class MakeRoomUI {
	private Frame mainFrame;
    private Label headerLabel;
    private Panel controlPanel;
    private Label statusLabel;
 
    public MakeRoomUI() {
        makeGUI();
    }
 
    public static void main(String[] args) {
    	OnlineUI mainButtonControl = new OnlineUI();
        mainButtonControl.TextField();
    }
 
    private void makeGUI() {
        mainFrame = new Frame("Rhythm Catchball");
        mainFrame.setSize(768, 480);
        mainFrame.setLayout(new GridLayout(3, 1));
        
        mainFrame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent windowEvent) {
                System.exit(0);
            }
        });
 
        headerLabel = new Label();
        headerLabel.setAlignment(Label.CENTER);
        headerLabel.setText("온라인 모드 선택");
 
        statusLabel = new Label();
        statusLabel.setText("click button");
        statusLabel.setAlignment(Label.CENTER);
        statusLabel.setSize(350, 100);
 
        controlPanel = new Panel();
        controlPanel.setLayout(new FlowLayout(FlowLayout.CENTER));
 
        mainFrame.add(headerLabel);
        mainFrame.add(controlPanel);
        mainFrame.add(statusLabel);
        mainFrame.setVisible(true);
    }
 
    private void TextField() {
 
        Button mkRoomButton = new Button("MAKE ROOM");
        Button joinRoomButton = new Button("JOIN ROOM");
 
        mkRoomButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("mkRoomButton Button clicked.");
            }
        });
 
        joinRoomButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                statusLabel.setText("joinRoomButton Button clicked.");
            }
        });
        
        controlPanel.add(mkRoomButton);
        controlPanel.add(joinRoomButton);
 
        mainFrame.setVisible(true);
 
    }
}
