package com.mycompany.ejercicio_4;

import java.util.ArrayList;
import java.util.Random;

/**
 *
 * @author arube
 */
public class Ejercicio_4 {
    
    static Random rand = new Random();
    static final int NFRASES = 1;
    
    public static void main(String[] args) {
        ArrayList<MiHilo> listaHilos = new ArrayList<>();
        
        int nHilos = rand.nextInt(6)+5;

        for(int i = 1; i <= nHilos; i++){
            listaHilos.add(new MiHilo("Hilo "+ i));
            listaHilos.get(i-1).start();
            
        }
        
        while(Thread.activeCount() > 2);
        
        System.out.println("¡Programa finalizado!");
    
    }
}