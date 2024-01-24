package com.mycompany.ejercicio_15;

import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class HProcClient extends Thread{
    private static Semaphore semaphore;
    float timeProcClient;

    public HProcClient(String name){
        setName(name);

        int nProduct = (int) (Math.random() * 20)+1;
        for(int i = 0; i < nProduct; i++)
            this.timeProcClient += (float)((Math.random()*0.3f)+0.1f);
    }

    @Override
    public void run() {

        try{
            semaphore.acquire();
            autocobroCliente();
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

        semaphore.release();
    }   

    void autocobroCliente(){
        System.out.println("Soy el "+getName()+" y me voy a cobrar.");
        dormir();

        System.out.println("Soy el "+getName()+" y me voy. He tardado "+timeProcClient+" segundos.");
    }
    
    void dormir(){
        try {
            sleep((int)(timeProcClient * 1000));
        } catch (InterruptedException ex) {
            Logger.getLogger(HProcClient.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    public static void setSemaphore(Semaphore semaphore){
        HProcClient.semaphore = semaphore;
    }
}