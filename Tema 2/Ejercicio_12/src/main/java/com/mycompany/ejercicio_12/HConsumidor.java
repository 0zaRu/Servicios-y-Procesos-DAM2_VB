package com.mycompany.ejercicio_12;

/**
 *
 * @author 6002754
 */
public class HConsumidor extends Thread{
    Cola cola;

    public HConsumidor(Cola cola) {
        this.cola = cola;
    }

    @Override
    public void run() {
    
        while(!cola.terminado)
            cola.get();
    }
}
