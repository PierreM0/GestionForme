package app;

import app.communication.Server;
import app.window.JFrameWindow;
import app.window.Window;

import java.io.IOException;

/**
 * La classe principale de l'application
 */
public class Application {

    public Application() {
        Window window = new JFrameWindow();
        try {
            new Server(window);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void main(String[] args) {
        new Application();
    }
}
