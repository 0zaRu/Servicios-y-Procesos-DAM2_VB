package com.mycompany.ejercicio_5;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author 6002754
 */
public class Ejercicio_5 {
    static final int NCAJEROS = 10;
    
    public static void main(String[] args) {
        Random rand = new Random();
        
        ArrayList<HiloCajero> cajeros = new ArrayList<>();
        ArrayList<Cliente> clientes = new ArrayList<>();
        
        for (int i = 0; i < NCAJEROS; i++) 
            cajeros.add(new HiloCajero("Cajero "+(i+1)));
        
        int nClientes = rand.nextInt(10-1)+1;
        for (int i = 0; i < nClientes; i++) 
            clientes.add(new Cliente(rand.nextInt(20-1)+1));
        
        
    }
}
