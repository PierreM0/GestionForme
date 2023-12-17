package app.communication.parser.expert;

import app.communication.parser.ParseExpertCOR;
import app.window.Window;

/**
 * Représente un expert capable de parser un message de demande de nettoyage de la zone de dessin
 */
public class ClearParseExpert extends ParseExpertCOR {

    /**
     * Initialise un maillon en donnant le maillon suivant
     *
     * @param suivant le maillon suivant ou <i>null</i> si ce maillon est le dernier de la chaîne
     */
    public ClearParseExpert(ParseExpertCOR suivant) {
        super(suivant);
    }

    @Override
    protected boolean parseLogic(String[] tokens, Window window) {
        if (!tokens[0].equals("clear")) return false;
        window.clear();
        return false;
    }
}
