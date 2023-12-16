package app;

import app.window.JFrameWindow;
import app.window.Window;

/**
 * La classe principale de l'application
 */
public class Application {

    public Application() {
        Window window = new JFrameWindow();
    }

    public static void main(String[] args) {
        new Application();
    }
}
