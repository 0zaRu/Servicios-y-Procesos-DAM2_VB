package com.mycompany.ejercicio_9;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class HiloSacaDinero extends Thread{
    
    static final int NUM_RESTAS = 4;
    static final float CANT_RETIRO = 10;
    Cuenta cuenta;
    
    public HiloSacaDinero(String name, Cuenta cuenta){
        setName(name);
        this.cuenta = cuenta;
    }

    @Override
    public void run() {
        for(int i = 0; i < NUM_RESTAS; i++){
            try {
                sleep(100);
            } catch (InterruptedException ex) {
                Logger.getLogger(HiloSacaDinero.class.getName()).log(Level.SEVERE, null, ex);
            }
            cuenta.retirarDinero(getName(), CANT_RETIRO);
        }
    }
}
