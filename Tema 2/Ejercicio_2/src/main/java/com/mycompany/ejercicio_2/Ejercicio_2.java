package com.mycompany.ejercicio_2;

import java.util.ArrayList;

/**
 *
 * @author 6002754
 */
public class Ejercicio_2 {

    public static void main(String[] args) {
        ArrayList<MiHilo> listaHilos = new ArrayList<>();
        listaHilos.add(new MiHilo(1));
        listaHilos.add(new MiHilo(2));
            
        listaHilos.get(0).setName("Hilo 1");
        listaHilos.get(0).start();
        listaHilos.get(1).setName("Hilo 2");
        listaHilos.get(1).start();
    }
}
