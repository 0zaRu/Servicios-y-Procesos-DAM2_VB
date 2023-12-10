package com.mycompany.ejercicio_7;

import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class Ejercicio_7 {
    
    static ArrayList<MiHilo> hilos = new ArrayList<>();
    static final int NHILOS = 10;
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        for(int i = 0; i < NHILOS; i++){
            hilos.add(new MiHilo("Hilo "+(i+1)));
        }
        
        for(MiHilo hilo: hilos){
            hilo.start();
        }
        
        while(MiHilo.activeCount() != 1){
            //MiHilo hiloInterrupt = hilos.get(rand.nextInt(hilos.size()-1));
            
            MiHilo hiloInterrupt = null;
            
            do{
                hiloInterrupt = hilos.get(rand.nextInt(10));
            }while(!hiloInterrupt.isAlive());
            
            hiloInterrupt.interrupt();
            
            
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_7.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        System.out.println("\n\tTodos los hilos han muerto.");
        
    }
}
