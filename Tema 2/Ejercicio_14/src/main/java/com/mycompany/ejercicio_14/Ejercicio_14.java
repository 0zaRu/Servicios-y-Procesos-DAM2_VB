package com.mycompany.ejercicio_14;

import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class Ejercicio_14 {

    private final static int NUM_JUGADORES = 5;
    
    public static void main(String[] args) {
        ArrayList<HJugador> jugadores = new ArrayList<>();
        Cola cola = new Cola();
        HArbitro arbi = new HArbitro(jugadores, cola);
        
        for(int i = 0; i < NUM_JUGADORES; i++)
            jugadores.add(new HJugador(arbi, i+1, cola));
        
        arbi.start();
        
        for(HJugador j: jugadores)
            j.start();
       
    }
}

class Cola{

    private boolean disponible;
    private int numero = 0;

    public synchronized int get(){
        
        while(!disponible){
            try {
            
                wait();
        
            } catch (InterruptedException e) {
                Logger.getLogger(Cola.class.getName()).log(Level.SEVERE, null, e);
            }
        }
        
        disponible = false;
        notifyAll();
        return numero;
    }

    public synchronized void put(int numero){
         while(disponible){
            try {
                wait();
            } catch (InterruptedException e) {
                Logger.getLogger(Cola.class.getName()).log(Level.SEVERE, null, e);
            }
        }
        this.numero = numero;
        disponible = true;

        notifyAll();
    }

    public boolean isDisponible() {
        return disponible;
    }

    public void setDisponible(boolean disponible) {
        this.disponible = disponible;
    }
}