package com.mycompany.ejercicio_5;

import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class Ejercicio_5 {
    static final int NCAJEROS = 10;
    static long inicio = System.nanoTime();
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        ArrayList<HiloCajero> cajeros = new ArrayList<>();
        
        for (int i = 0; i < NCAJEROS; i++) 
            cajeros.add(new HiloCajero("Cajero "+(i+1)));
        
        try{
            
            for(HiloCajero cajero: cajeros){
                cajero.start();
                Thread.sleep(10);                
            }

            for(HiloCajero cajero: cajeros)    
                cajero.join();
                
        } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_5.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        long acaba = System.nanoTime();
        System.out.println("Cierra el super, ha estado abierto: "+(acaba-inicio)/1e9);
    }
}
