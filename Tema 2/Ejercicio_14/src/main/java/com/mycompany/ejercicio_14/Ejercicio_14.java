package com.mycompany.ejercicio_14;

import java.util.ArrayList;
import java.util.concurrent.CyclicBarrier;

/**
 *
 * @author 6002754
 */
public class Ejercicio_14 {

    private final static int NUM_JUGADORES = 5;
    private final static CyclicBarrier barrera = new CyclicBarrier(NUM_JUGADORES-1);
    
    public static void main(String[] args) {
        Arbitro arbi = new Arbitro(barrera);
        
        ArrayList<HJugador> jugadores = new ArrayList<>();
        
        for(int i = 0; i < NUM_JUGADORES; i++){
            jugadores.add(new HJugador(arbi, i+1, barrera));
        }
        
        for(HJugador j: jugadores)
            j.start();
       
    }
}

class Arbitro {
    CyclicBarrier barrera;
    private final static int nAleatorio = (int)(Math.random() * 50);
    int turnoCont = 1, nVuelta = 1;
    
    boolean terminado = false;
    
    public Arbitro(CyclicBarrier barrera){
        this.barrera = barrera;
    }
    
    public synchronized void jugada(int hJugador) {
        try{
            turnoCont++;
            
            if(turnoCont == 6){
                turnoCont = 1;
                nVuelta++;
            }
            
            int valorPensado = (int)(Math.random()*50);
            System.out.println("Vuelta: "+nVuelta+" | Turno del jugador: "+ hJugador+": "+valorPensado);
            
            if(valorPensado == nAleatorio){
                System.out.println("\t\tHA GANADO EL JUGADOR "+hJugador);
                terminado = true;
            }
            
            barrera.await();
            
        }catch(Exception e){
            
        }
    }
}