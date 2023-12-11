package com.mycompany.ejercicio_9;

import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author 6002754
 */
public class Cuenta {
    private float cantDinero;

    public Cuenta(float cantDinero){
        this.cantDinero = cantDinero;
    }
    
    public void retirarDinero(String nombre, float cantRetiro){
        synchronized (this) {
            if(this.cantDinero - cantRetiro >= 0)
            {
                try{
                    Thread.sleep((int)Math.random()*1000);
                }catch (InterruptedException ex) {
                    Logger.getLogger(Cuenta.class.getName()).log(Level.SEVERE, null, ex);
                }
                
                this.cantDinero -= cantRetiro;
                System.out.println("Antes: "+(this.cantDinero+cantRetiro)
                                 + "€\nAhora: "+this.cantDinero
                                 + "€\n"+nombre+" ha sacado: "+cantRetiro+"€\n");

            }
            else
                System.out.println(nombre+" no ha podido sacar "+cantRetiro+" porque actualmente hay: "+this.cantDinero+"€");
        }
    }
}
