package app.communication.parser;

import app.window.Window;

import java.awt.Color;
import java.util.Map;

/**
 * Représente un maillon d'une chaîne de responsabilité de parsing de message
 */
public abstract class ParseExpertCOR extends ParseExpert {

    private static final Map<String, Color> COLOR_MAP = Map.of(
            "black", Color.BLACK,
            "blue", Color.BLUE,
            "red", Color.RED,
            "green", Color.GREEN,
            "yellow", Color.YELLOW,
            "cyan", Color.CYAN
    );

    private final ParseExpertCOR suivant;

    /**
     * Initialise un maillon en donnant le maillon suivant
     * @param suivant le maillon suivant ou <i>null</i> si ce maillon est le dernier de la chaîne
     */
    public ParseExpertCOR(ParseExpertCOR suivant) {
        this.suivant = suivant;
    }

    @Override
    public boolean parse(String[] tokens, Window window) {
        if (parseLogic(tokens, window)) {
            return true;
        }
        if (suivant != null) {
            return suivant.parse(tokens, window);
        } else {
            return false;
        }
    }

    /**
     * Convert a color string to a {@link Color} object. If the color is not recognized then black is returned by
     * default
     * @param colorStr the color's string
     * @return the corresponding {@link Color} object
     */
    protected Color parseColor(String colorStr) {
        return COLOR_MAP.getOrDefault(colorStr.toLowerCase(), Color.BLACK);
    }

    /**
     * Parse le message donné en paramètre. Si cet expert est incapable de parser ce type de message alors il retournera
     * <i>false</i>
     * @param tokens les tokens du message
     * @param window la fenêtre de l'application
     * @return <i>true</i> si le parsing est réussi, <i>false sinon</i>
     */
    protected abstract boolean parseLogic(String[] tokens, Window window);
}
