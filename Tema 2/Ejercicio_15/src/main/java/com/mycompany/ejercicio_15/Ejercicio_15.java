package com.mycompany.ejercicio_15;

import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class Ejercicio_15 {
    
    static final int NCAJAS = 8;
    static final int NCLIENTS = 100;
    
    public static void main(String[] args) {

        long initTime = System.nanoTime();

        Semaphore semaphore = new Semaphore(NCAJAS);
        HProcClient.setSemaphore(semaphore);

        ArrayList<HProcClient> clients = new ArrayList<>();
        for (int i = 0; i < NCLIENTS; i++)
            clients.add(new HProcClient("Cliente "+(i+1)));
        
        startAndJoin(clients);

        System.out.println("Cierra el super, ha estado abierto: "+(System.nanoTime()-initTime)/1e9);
    }
    
    public static void startAndJoin(ArrayList<HProcClient> threads){
        try{
            
            for(Thread thread: threads){
                thread.start();
                Thread.sleep(10);                
            }

            for(Thread thread: threads)
                thread.join();
                
        } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_15.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
