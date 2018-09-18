package cn.augusto;

import javax.swing.*;
import javax.swing.text.html.ImageView;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;

public class ImageViewer {
  public static void main(String[] args) {
    EventQueue.invokeLater(new Runnable() {
      @Override
      public void run() {
        JFrame frame =new ImageViewerFrame();
        frame.setTitle("ImageViewer");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setVisible(true);
      }
    });
  }
}

class ImageViewerFrame extends JFrame {
  private JLabel label;
  private JFileChooser chooser;
  private static final int DEFAULT_WIDTH = 300;
  private static final int DEFAULT_HEIGHT = 400;

  public ImageViewerFrame() {
    setSize(DEFAULT_WIDTH, DEFAULT_HEIGHT);
    label = new JLabel();
    add(label);
    chooser = new JFileChooser();
    chooser.setCurrentDirectory(new File("."));
    JMenuBar menuBar = new JMenuBar();
    setJMenuBar(menuBar);
    JMenu menu = new JMenu("File");
    menuBar.add(menu);
    JMenuItem item = new JMenuItem("Open");
    menu.add(item);
    item.addActionListener(event -> {
      int result = chooser.showOpenDialog(null);
      if (result == JFileChooser.APPROVE_OPTION) {
        String fpath = chooser.getSelectedFile().getPath();
        label.setIcon(new ImageIcon(fpath));
      }
    });

    JMenuItem exit = new JMenuItem("Exit");
    menu.add(exit);
    exit.addActionListener(event -> {
          System.exit(0);
        }
    );

    exit.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {
        System.out.println("Exit clicked");
      }
    });
  }

}