package com.mycompany.ejercicio_4;

import static com.mycompany.ejercicio_4.Ejercicio_4.NFRASES;

/**
 *
 * @author arube
 */
public class MiHilo extends Thread{

    public MiHilo(String nombre){
        setName(nombre);
    }
    
    @Override
    public void run() {
        
        if(activeCount() > 2){
            for(int j = 0; j < NFRASES; j++){
                System.out.println("Soy "+getName()+", y no me quiero ir señor Stark ...");
            }
        }else {
            System.out.println("¡Soy "+getName()+", el último superviviente!");
        }
    }
}
