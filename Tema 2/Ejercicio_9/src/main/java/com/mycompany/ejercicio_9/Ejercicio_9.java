package com.mycompany.ejercicio_9;

import java.util.ArrayList;

/**
 *
 * @author 6002754
 */
public class Ejercicio_9 {

    static final int CANT_HILOS = 2;
    
    public static void main(String[] args) {
        Cuenta cuenta = new Cuenta(40);
        
        ArrayList<HiloSacaDinero> listaHilos = new ArrayList<>();
        
        for(int i = 0; i < CANT_HILOS; i++)
            listaHilos.add(new HiloSacaDinero("Hilo "+(i+1), cuenta));
        
        for(HiloSacaDinero hsd: listaHilos)
            hsd.start();
    }
}
