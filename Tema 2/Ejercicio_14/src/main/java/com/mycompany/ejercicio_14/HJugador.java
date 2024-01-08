package com.mycompany.ejercicio_14;

import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class HJugador extends Thread{
    Arbitro arbi;
    int miNum;
    CyclicBarrier barrera;

    public HJugador(Arbitro cola, int miNum, CyclicBarrier barrera) {
        this.arbi = cola;
        this.miNum = miNum;
        this.barrera = barrera;
    }

    @Override
    public void run() {
    
        while(!arbi.terminado){
            if(arbi.turnoCont == miNum)
                arbi.jugada(miNum);
    
            try {
                barrera.await();
                sleep((long) ((Math.random()*300)+200));
            } catch (InterruptedException | BrokenBarrierException ex) {
                Logger.getLogger(HJugador.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
    }
}
