package com.mycompany.ejercicio_4;

import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author arube
 */
public class MiHilo extends Thread{
    Random rand = new Random();
    int nFrases = 3;
    
    public MiHilo(String nombre){
        setName(nombre);
        nFrases = rand.nextInt(10)+1;
    }
    
    @Override
    public void run() {
        for(int i = 0; i < nFrases; i++){
            if(activeCount() > 2){
                System.out.printf("Soy %7s, y no me quiero ir señor Stark ...   %2d\n", getName(), i);
            
            }else {
                System.out.println("¡Soy "+getName()+", el último superviviente!");
            }
            
            try {
                int nAleat = rand.nextInt(4000-1000)+1000;
                System.out.println(nAleat);
                sleep(nAleat);
            } catch (InterruptedException ex) {
                Logger.getLogger(MiHilo.class.getName()).log(Level.SEVERE, null, ex);
            }
            
        }
    }
}