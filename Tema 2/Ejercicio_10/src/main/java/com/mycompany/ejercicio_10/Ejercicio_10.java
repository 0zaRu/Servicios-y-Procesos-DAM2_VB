package com.mycompany.ejercicio_10;

import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class Ejercicio_10 {
    
    static final int NCAJEROS = 10;
    static final int NCLIENTES = 100;
    
    static long inicio = System.nanoTime();
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        ArrayList<Cliente> clientes = new ArrayList<>();
        ArrayList<HiloCajero> cajeros = new ArrayList<>();
        
        for(int i = 0; i < NCLIENTES; i++)
            clientes.add(new Cliente(rand.nextInt(20-1)+1, i+1));
        
        for (int i = 0; i < NCAJEROS; i++) 
            cajeros.add(new HiloCajero("Cajero "+(i+1), clientes, inicio));
        
        startAndJoin(cajeros);
        
        long acaba = System.nanoTime();
        System.out.println("Cierra el super, ha estado abierto: "+(acaba-inicio)/1e9);
    }
    
    public static void startAndJoin(ArrayList<HiloCajero> hilos){
        try{
            
            for(Thread cajero: hilos){
                cajero.start();
                Thread.sleep(10);                
            }

            for(Thread cajero: hilos)    
                cajero.join();
                
        } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_10.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
}
