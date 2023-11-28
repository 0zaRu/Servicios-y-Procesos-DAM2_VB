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
        
        for(int i = 0; i < rand.nextInt(5, 11); i++){
            listaHilos.add(new MiHilo("Hilo "+ i));
        }
        
        for(MiHilo hilo: listaHilos){
            //MiHilo saliente = hilo.pop
        }
        
    }
}
