package app.communication.parser.expert;

import app.communication.parser.ParseExpertCOR;
import app.geometry.Vector2D;
import app.window.Window;

import java.awt.Color;

/**
 * Représente un expert capable de parser un message de demande de dessin d'un cercle
 */
public class DrawCircleParseExpert extends ParseExpertCOR {

    /**
     * Initialise un maillon en donnant le maillon suivant
     *
     * @param suivant le maillon suivant ou <i>null</i> si ce maillon est le dernier de la chaîne
     */
    public DrawCircleParseExpert(ParseExpertCOR suivant) {
        super(suivant);
    }

    @Override
    protected boolean parseLogic(String[] tokens, Window window) {
        if (!tokens[0].equals("circle") || tokens.length != 6) return false;
        Vector2D center = new Vector2D(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
        double radius = Double.parseDouble(tokens[3]);
        Color color = parseColor(tokens[4]);
        boolean fill = tokens[5].equals("true");
        window.drawCircle(center, radius, color, fill);
        return true;
    }
}
