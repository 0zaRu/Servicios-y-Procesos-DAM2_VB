package com.mycompany.ejercicio_14;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class HJugador extends Thread{
    int miNum;
    private boolean jugado = false;
    private HArbitro arbi;
    private Cola cola;

    public HJugador(HArbitro arbi, int miNum, Cola cola) {
        this.arbi = arbi;
        this.miNum = miNum;
        this.cola = cola;
    }

    @Override
    public void run() {
    
        while (!arbi.isTerminado()){
            
            try {
                int num = new Random().nextInt(50) + 1;
                System.out.println("El Jugador " + miNum + " ha sacado un " + num);
                cola.put(num);
                
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                Logger.getLogger(HJugador.class.getName()).log(Level.SEVERE, null, e);
            }
            
        }
    }
    
    public boolean isJugado() {
        return jugado;
    }

    public void setJugado(boolean jugado) {
        this.jugado = jugado;
    }
}
