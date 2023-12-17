package app.communication;

import app.communication.parser.ParseExpertCOR;
import app.communication.parser.expert.ClearParseExpert;
import app.communication.parser.expert.DrawCircleParseExpert;
import app.communication.parser.expert.DrawLineParseExpert;
import app.communication.parser.expert.DrawPolygonParseExpert;
import app.communication.parser.expert.WorldZoneParseExpert;
import app.window.Window;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * La classe s'occupant de la communication avec le client C++.
 * Les instances de cette classe ne sont capables d'entretenir <strong>qu'une seule</strong> connexion avec un client
 */
public class Server {

    private static final int PORT = 12345;
    private static final String TOKENS_SEPARATOR = ";";

    private final Window window;
    private final ParseExpertCOR parser;
    private final ServerSocket server;

    /**
     * Initialise le server. Utilise la fenêtre de l'application
     * @param window la fenêtre du l'application
     * @throws IOException si l'ouverture du serveur n'a pas réussi
     */
    public Server(Window window) throws IOException {
        this.window = window;
        this.parser = initParser();
        this.server = new ServerSocket(PORT);
        new Thread(() -> handleClientCommunication(server)).start();
    }

    /**
     * Initialise la COR responsable du parsing des messages echangés avec le client
     * @return le premier maillon de la COR
     */
    private ParseExpertCOR initParser() {
        ParseExpertCOR chain = new ClearParseExpert(null);
        chain = new DrawCircleParseExpert(chain);
        chain = new DrawPolygonParseExpert(chain);
        chain = new DrawLineParseExpert(chain);
        chain = new WorldZoneParseExpert(chain);
        return chain;
    }

    /**
     * Gère la communication avec le client. N'est capable d'entretenir qu'une unique connexion
     * @param server l'object {@link ServerSocket} du serveur
     */
    private void handleClientCommunication(ServerSocket server) {
        try {
            Socket client = server.accept();
            BufferedReader input = new BufferedReader(new InputStreamReader(client.getInputStream()));
            new Thread(() -> {
                while (!client.isClosed() && !server.isClosed()) {
                    try {
                        String line = input.readLine();
                        if (line == null || line.isEmpty()) break;
                        System.out.println("Received: " + line);
                        // On sépare le message en tokens afin de faciliter le parsing
                        String[] tokens = line.split(TOKENS_SEPARATOR);
                        parser.parse(tokens, window);
                    } catch (IOException ex) {
                        try {
                            client.close();
                            server.close();
                        } catch (IOException ignored) {}
                        break;
                    }
                }
            }).start();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
