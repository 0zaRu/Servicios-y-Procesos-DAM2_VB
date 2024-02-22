package com.mycompany.ejercicio_14;

import java.util.ArrayList;
import java.util.concurrent.BrokenBarrierException;
import java.util.concurrent.CyclicBarrier;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author arube
 */
class HArbitro extends Thread{

    private Cola cola;
    private int valorPensado;
    CyclicBarrier barrera;
    private ArrayList<HJugador> jugadores;
    int turnoCont;
    boolean terminado = false;
    
    public HArbitro(ArrayList<HJugador> jugadores, Cola cola){
        this.cola = cola;
        this.valorPensado = (int)(Math.random()*50);
        this.jugadores = jugadores;
        this.barrera = new CyclicBarrier(jugadores.size() +1);
    }
    
    @Override
    public void run() {
        
        for (int i = 1; !terminado; i++){
            
            System.out.println("TURNO: "+i);
            compruebaJugada();
            
            try {
                barrera.await();
            } catch (InterruptedException | BrokenBarrierException e) {
                Logger.getLogger(HArbitro.class.getName()).log(Level.SEVERE, null, e);
            }
        }  
    }
    
    public synchronized void compruebaJugada(){
        for (int j = 0; j < jugadores.size(); j++){
                
            int numeroRecibido = cola.get();
                
            if (comprobarNumero(numeroRecibido)) {
                System.out.println("SE HA ACERTADO EL NÚMERO!!");
                    
                setTerminado(true);
                return;
            }
        }
    } 

    public int getTurnoCont() {
        return turnoCont;
    }

    public void setTurnoCont(int turnoCont) {
        this.turnoCont = turnoCont;
    }

    public boolean isTerminado() {
        return terminado;
    }

    public void setTerminado(boolean terminado) {
        this.terminado = terminado;
    }
    
    private boolean comprobarNumero(int recibido) {
        if (recibido == valorPensado)
            return true;
        else
            return false;
    }    
}