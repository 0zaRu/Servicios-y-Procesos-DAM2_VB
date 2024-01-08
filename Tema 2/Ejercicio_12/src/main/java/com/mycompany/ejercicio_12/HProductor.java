package com.mycompany.ejercicio_12;

/**
 *
 * @author 6002754
 */
public class HProductor extends Thread {
    Cola cola;

    public HProductor(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
        
        while (!cola.terminado)
            cola.readPut();
    }    
}
