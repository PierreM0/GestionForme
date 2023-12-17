package app.communication.parser.expert;

import app.communication.parser.ParseExpertCOR;
import app.geometry.Vector2D;
import app.window.Window;

import java.awt.Color;

/**
 * Représente un expert capable de parser un message de demande de dessin d'un segment
 */
public class DrawLineParseExpert extends ParseExpertCOR {

    /**
     * Initialise un maillon en donnant le maillon suivant
     *
     * @param suivant le maillon suivant ou <i>null</i> si ce maillon est le dernier de la chaîne
     */
    public DrawLineParseExpert(ParseExpertCOR suivant) {
        super(suivant);
    }

    @Override
    protected boolean parseLogic(String[] tokens, Window window) {
        if (!tokens[0].equals("line") || tokens.length != 6) return false;
        Vector2D p1 = new Vector2D(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
        Vector2D p2 = new Vector2D(Double.parseDouble(tokens[3]), Double.parseDouble(tokens[4]));
        Color color = parseColor(tokens[5]);
        window.drawLine(p1, p2, color);
        return true;
    }
}
