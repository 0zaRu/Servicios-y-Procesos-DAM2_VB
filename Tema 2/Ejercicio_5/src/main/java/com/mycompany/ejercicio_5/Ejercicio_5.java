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
    static ArrayList<Cliente> clientes = new ArrayList<>();
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        ArrayList<HiloCajero> cajeros = new ArrayList<>();
        
        for (int i = 0; i < NCAJEROS; i++) 
            cajeros.add(new HiloCajero("Cajero "+(i+1)));
        
        for (int i = 0; i < 100; i++) 
            clientes.add(new Cliente(rand.nextInt(20-1)+1, i+1));
        
        for(HiloCajero cajero: cajeros){
            cajero.start();
            
            try {
                Thread.sleep(10);
            } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_5.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        for(HiloCajero cajero: cajeros){
            try {
                cajero.join();
            } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_5.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        
        System.out.println("Cierra el super");
    }
}
