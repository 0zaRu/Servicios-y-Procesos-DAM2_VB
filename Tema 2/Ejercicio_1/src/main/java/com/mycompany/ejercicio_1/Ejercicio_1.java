package com.mycompany.ejercicio_1;

import java.util.ArrayList;

/**
 *
 * @author 6002754
 */
public class Ejercicio_1 {

    public static void main(String[] args) {
        ArrayList<MiHilo> listaHilos = new ArrayList<>();
        
        for (int i = 0; i < 10; i++) {
            listaHilos.add(new MiHilo());
            
            listaHilos.get(i).setName("hilo"+i);
            listaHilos.get(i).start();
        }
    }
}
