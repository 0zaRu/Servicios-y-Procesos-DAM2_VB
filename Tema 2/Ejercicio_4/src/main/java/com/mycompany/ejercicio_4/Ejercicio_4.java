package com.mycompany.ejercicio_4;

import java.util.ArrayList;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author arube
 */
public class Ejercicio_4 {
    
    static Random rand = new Random();
    
    public static void main(String[] args) {
        ArrayList<MiHilo> listaHilos = new ArrayList<>();
        
        int nHilos = rand.nextInt(6)+5;

        for(int i = 1; i <= nHilos; i++){
            listaHilos.add(new MiHilo("Hilo "+ i));
        }
        
        for(MiHilo hilo: listaHilos){
            hilo.start();
        }
        
        for(MiHilo hilo: listaHilos){
            try {
                
                hilo.join();
            
            } catch (InterruptedException ex) {
                Logger.getLogger(Ejercicio_4.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        System.out.println("¡Programa finalizado!");
    
    }
}