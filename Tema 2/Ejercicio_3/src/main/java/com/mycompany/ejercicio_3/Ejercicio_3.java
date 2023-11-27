package com.mycompany.ejercicio_3;

import java.util.ArrayList;

/**
 *
 * @author 6002754
 */
public class Ejercicio_3 {

    public static void main(String[] args) {
        ArrayList<MiHilo> listaHilos = new ArrayList<>();
        
        for (int i = 0; i < 10; i++) {
            listaHilos.add(new MiHilo());
            
            listaHilos.get(i).setName("hilo"+i);
            listaHilos.get(i).start();
            
        }
        
        for(MiHilo hilo: listaHilos){
            try{
            
                hilo.join();
            
            }catch(Exception e){e.printStackTrace();}
        }
        
        System.out.println("\nLos hilos han acabado");
    }
}
