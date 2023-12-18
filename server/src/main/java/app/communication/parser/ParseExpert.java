package app.communication.parser;

import app.window.Window;

/**
 * Représente un expert capable de parser un type de message
 */
public abstract class ParseExpert {

    /**
     * Parse le message donné en paramètre. Si cet expert est incapable de parser ce type de message alors il retournera
     * <i>false</i>
     * @param tokens les tokens du message
     * @param window la fenêtre de l'application
     * @return <i>true</i> si le parsing est réussi, <i>false sinon</i>
     */
    public abstract boolean parse(String[] tokens, Window window);
}
