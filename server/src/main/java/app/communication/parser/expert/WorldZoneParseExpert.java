package app.communication.parser.expert;

import app.communication.parser.ParseExpertCOR;
import app.geometry.Vector2D;
import app.window.Window;

/**
 * Représente un expert capable de parser un message de mise à jour de la zone du monde
 */
public class WorldZoneParseExpert extends ParseExpertCOR {

    /**
     * Initialise un maillon en donnant le maillon suivant
     *
     * @param suivant le maillon suivant ou <i>null</i> si ce maillon est le dernier de la chaîne
     */
    public WorldZoneParseExpert(ParseExpertCOR suivant) {
        super(suivant);
    }

    @Override
    protected boolean parseLogic(String[] tokens, Window window) {
        if (!tokens[0].equals("worldzone") || tokens.length != 5) return false;
        Vector2D[] zone = new Vector2D[2];
        zone[0] = new Vector2D(Double.parseDouble(tokens[1]), Double.parseDouble(tokens[2]));
        zone[1] = new Vector2D(Double.parseDouble(tokens[3]), Double.parseDouble(tokens[4]));
        window.updateWorldZone(zone);
        return true;
    }
}
