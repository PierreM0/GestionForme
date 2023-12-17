package app.communication.parser.expert;

import app.communication.parser.ParseExpertCOR;
import app.geometry.Vector2D;
import app.window.Window;

import java.awt.Color;

/**
 * Représente un expert capable de parser un message de demande de dessin d'un polygone
 */
public class DrawPolygonParseExpert extends ParseExpertCOR {

    /**
     * Initialise un maillon en donnant le maillon suivant
     *
     * @param suivant le maillon suivant ou <i>null</i> si ce maillon est le dernier de la chaîne
     */
    public DrawPolygonParseExpert(ParseExpertCOR suivant) {
        super(suivant);
    }

    @Override
    protected boolean parseLogic(String[] tokens, Window window) {
        if (!tokens[0].equals("polygon") || tokens.length < 2) return false;
        int nPoints = Integer.parseInt(tokens[1]);
        if (tokens.length < nPoints * 2 + 4) return false;
        Vector2D[] points = new Vector2D[nPoints];
        for (int i = 0; i < nPoints; i++) {
            points[i] = new Vector2D(Double.parseDouble(tokens[i * 2 + 2]), Double.parseDouble(tokens[i * 2 + 3]));
        }
        Color color = parseColor(tokens[tokens.length - 2]);
        boolean fill = tokens[tokens.length - 1].equals("true");
        window.drawPolygon(points, color, fill);
        return true;
    }
}
